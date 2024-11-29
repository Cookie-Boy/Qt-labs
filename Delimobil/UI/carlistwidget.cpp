#include "carlistwidget.h"
#include "ui_carlistwidget.h"
#include "../services/carservice.h"
#include "../models/car.h"
#include "filterdialog.h"
#include "rentdialog.h"
#include <QPushButton>
#include <QPainter>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDebug>

CarListWidget::CarListWidget(QStackedWidget *stackedWidget, QStack<QWidget*> *widgetHistory, QWidget *parent) :
    BaseWidget(stackedWidget, widgetHistory, parent),
    ui(new Ui::CarListWidget)
{
    ui->setupUi(this);

    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    createFilterButton();
}

CarListWidget::~CarListWidget()
{
    delete ui;
}

void CarListWidget::createFilterButton() {
    QPushButton *filterButton = new QPushButton("Фильтр", this);
    filterButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #A7E6DC;"
        "   color: #000000;"
        "   border-radius: 15px;"
        "   font-size: 12px;"
        "   padding: 5px;"
        "}"
        "QPushButton:hover { background-color: #8ad3c6; }"
        "QPushButton:pressed { background-color: #7ac2b6; }"
    );
    filterButton->move(130, 50);
    filterButton->setCursor(Qt::PointingHandCursor);
    connect(filterButton, &QPushButton::clicked, this, &CarListWidget::openFilterDialog);
}

void CarListWidget::openFilterDialog()
{
    FilterDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString nameFilter = dialog.getNameFilter();
        QString categoryFilter = dialog.getCategoryFilter();
        bool heatedSeatsFilter = dialog.getHeatedSeatsFilter();
        bool parkingSensorsFilter = dialog.getParkingSensorsFilter();
        QDate dateFilter = dialog.getDateFilter();
        QString transmissionFilter = dialog.getTransmissionFilter();
        QString driveTypeFilter = dialog.getDriveTypeFilter();

        QVector<Car> allCars = CarService::instance().getAllCars();
        QVector<Car> filteredCars;

        for (const Car &car : allCars) {
            if (!nameFilter.isEmpty() && !car.getName().contains(nameFilter, Qt::CaseInsensitive))
                continue;
            if (categoryFilter != "Любая" && car.getCategory() != categoryFilter)
                continue;
            if (heatedSeatsFilter && !car.getHasHeatedSeats())
                continue;
            if (parkingSensorsFilter && !car.getHasParkingSensors())
                continue;
            if (transmissionFilter != "Любая" && car.getTransmission() != transmissionFilter)
                continue;
            if (driveTypeFilter != "Любой" && car.getDriveType() != driveTypeFilter)
                continue;
            if (CarService::instance().isBlockedOnDate(car, dateFilter)) // Проверяем, заблокирована ли машина
                continue;

            filteredCars.append(car);
        }

        updateCarList(filteredCars);
        createFilterButton();
    }
}

void CarListWidget::createCarCard(Car &car, QGridLayout *layout, int row, int col)
{
    QString projectPath = "C:\\Users\\vital\\OneDrive\\My projects\\5 semester\\Qt projects\\Delimobil";

    QWidget *commonWidget = new QWidget(this);
    QVBoxLayout *commonLayout = new QVBoxLayout(commonWidget);

    // Карточка
    QWidget *cardWidget = new QWidget(commonWidget);
    cardWidget->setFixedSize(205, 250);
    cardWidget->setStyleSheet("QWidget { background-color: #f5f5f5; border-radius: 20px; }");

    QLabel *imageLabel = new QLabel(cardWidget);
    QPixmap pixmap(car.getImagePath());
    imageLabel->setPixmap(pixmap.scaled(205, 120, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
    imageLabel->setFixedSize(205, 120);

    QLabel *nameLabel = new QLabel(car.getName(), cardWidget);
    nameLabel->setAlignment(Qt::AlignCenter);
    nameLabel->setStyleSheet("QLabel { font-size: 16px; font-weight: bold }");

    double pricePerMinute = CarService::instance().getOptimalPricePerMinute(car);
    QLabel *perMinuteLabel = new QLabel(QString::number(pricePerMinute) + " ₽/мин", cardWidget);
    perMinuteLabel->setAlignment(Qt::AlignCenter);
    perMinuteLabel->setStyleSheet("QLabel { font-size: 14px; }");

    double pricePerHour = CarService::instance().getOptimalPricePerHour(car);
    double pricePerKilometer = CarService::instance().getOptimalPricePerKilometer(car);
    QLabel *perHourLabel = new QLabel(QString::number(pricePerHour) + " ₽/час и " +
                                      QString::number(pricePerKilometer) + " ₽/км", cardWidget);
    perHourLabel->setAlignment(Qt::AlignCenter);
    perHourLabel->setStyleSheet("QLabel { font-size: 14px; }");

    QLabel *categoryLabel = new QLabel(car.getCategory(), cardWidget);
    categoryLabel->setAlignment(Qt::AlignCenter);
    categoryLabel->setStyleSheet("QLabel { font-size: 14px; }");

    QPushButton *rentButton = new QPushButton("Арендовать", cardWidget);
    rentButton->setFixedHeight(30);
    bool hasRent = AuthorizedUser::instance().getCar() != nullptr;
    rentButton->setStyleSheet(
        QString("QPushButton {"
                "   background-color: %1"
                "   color: #000000;"
                "   border-radius: 15px;"
                "   font-size: 12px;"
                "   padding: 5px;"
                "}"
                "QPushButton:hover { background-color: #8ad3c6; }"
                "QPushButton:pressed { background-color: #7ac2b6; }")
            .arg(hasRent ? "#C0C0C0;" : "#A0EACD;")
    );
    rentButton->setEnabled(!hasRent);

    QVBoxLayout *cardLayout = new QVBoxLayout(cardWidget);
    cardLayout->setSpacing(5);
    cardLayout->setContentsMargins(0, 0, 0, 0);

    cardLayout->addWidget(imageLabel);
    cardLayout->addWidget(nameLabel);
    cardLayout->addWidget(perMinuteLabel);
    cardLayout->addWidget(perHourLabel);
    cardLayout->addWidget(categoryLabel);

    commonLayout->addWidget(cardWidget);
    commonLayout->addWidget(rentButton);

    layout->addWidget(commonWidget, row, col);

    connect(rentButton, &QPushButton::clicked, [this, car]() {
        RentDialog dialog(car, this);
        if (dialog.exec() == QDialog::Accepted && dialog.isConfirmed()) {
            AuthorizedUser::instance().setCar(const_cast<Car*>(&car));
            emit rentStarted();
            qDebug() << "Аренда подтверждена";
        } else {
            qDebug() << "Аренда отменена";
        }
    });
}

void CarListWidget::displayCars()
{
    QVector<Car> cars = CarService::instance().getAllCars();
    QGridLayout *layout = ui->layout;
    while (QLayoutItem *item = layout->takeAt(0)) {
        if (QWidget *widget = item->widget()) {
            widget->deleteLater(); // Удаляем виджет
        }
        delete item; // Удаляем сам QLayoutItem
    }

    layout->setHorizontalSpacing(18);
    layout->setVerticalSpacing(20);
    layout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);  // Центрирование по горизонтали

    int row = 0, col = 0, maxCols = 5;

    for (Car &car : cars) {
        if (CarService::instance().isBlockedOnDate(car, QDate::currentDate()))
            continue;

        createCarCard(car, layout, row, col);

        col++;
        if (col == maxCols) {
            col = 0;
            row++;
        }
    }
}

void CarListWidget::updateCarList(QVector<Car> &cars)
{
    // Очистка текущего отображения
    QLayoutItem *child;
    while ((child = ui->layout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    // Отображение машин из нового списка
    int row = 0, col = 0, maxCols = 5;

    for (Car &car : cars) {
        createCarCard(car, ui->layout, row, col);

        col++;
        if (col == maxCols) {
            col = 0;
            row++;
        }
    }
}
