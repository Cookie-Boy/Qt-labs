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

CarListWidget::CarListWidget(QStackedWidget *stackedWidget, QWidget *parent) :
    BaseWidget(stackedWidget, parent),
    ui(new Ui::CarListWidget)
{
    ui->setupUi(this);

    displayCars();

    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

//    CarService::instance().addCar("Hyundai Solaris", 4, "Эконом", "Автомат", "Передний",
//                                  1.6, 110, true, true, false, true);
//    CarService::instance().addCar("ВАЗ 2110", 4, "Эконом", "Механика", "Передний",
//                                  1.2, 110, true, true, true, true);
//    CarService::instance().addCar("Volkswagen Polo", 4, "Эконом", "Робот", "Передний",
//                                  1.6, 110, true, true, false, true);

    createFilterButton();
    setAllTools(this);
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
    filterButton->move(90, 50);
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

            filteredCars.append(car);
        }

        updateCarList(filteredCars);
        createFilterButton();
    }
}

void CarListWidget::createCarCard(const Car &car, QGridLayout *layout, int row, int col)
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
    QLabel *perHourLabel = new QLabel(QString::number(pricePerHour) + " ₽/час", cardWidget);
    perHourLabel->setAlignment(Qt::AlignCenter);
    perHourLabel->setStyleSheet("QLabel { font-size: 14px; }");

    QLabel *categoryLabel = new QLabel(car.getCategory(), cardWidget);
    categoryLabel->setAlignment(Qt::AlignCenter);
    categoryLabel->setStyleSheet("QLabel { font-size: 14px; }");

    QPushButton *rentButton = new QPushButton("Арендовать", cardWidget);
    rentButton->setFixedHeight(30);
    rentButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #A0EACD;"
        "   color: #000000;"
        "   border-radius: 15px;"
        "   font-size: 12px;"
        "   padding: 5px;"
        "}"
        "QPushButton:hover { background-color: #8ad3c6; }"
        "QPushButton:pressed { background-color: #7ac2b6; }"
    );

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
        RentDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted && dialog.isConfirmed()) {
            CarService::instance().startRent(const_cast<Car &>(car));
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

    layout->setHorizontalSpacing(18);
    layout->setVerticalSpacing(20);
    layout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);  // Центрирование по горизонтали

    int row = 0, col = 0, maxCols = 5;

    for (const Car &car : cars) {
        createCarCard(car, layout, row, col);

        col++;
        if (col == maxCols) {
            col = 0;
            row++;
        }
    }
}

void CarListWidget::updateCarList(const QVector<Car> &cars)
{
    // Очистка текущего отображения
    QLayoutItem *child;
    while ((child = ui->layout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    // Отображение машин из нового списка
    int row = 0, col = 0, maxCols = 5;

    for (const Car &car : cars) {
        createCarCard(car, ui->layout, row, col);

        col++;
        if (col == maxCols) {
            col = 0;
            row++;
        }
    }
}
