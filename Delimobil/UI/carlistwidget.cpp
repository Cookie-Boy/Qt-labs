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

    setAllTools(this);

    foreach (QPushButton *button, this->findChildren<QPushButton*>()) {
        button->setCursor(Qt::PointingHandCursor);
    }

    displayCars();

    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

//    CarService::instance().addCar("Hyundai Solaris", 4, "Эконом", "Автомат", "Передний",
//                                  1.6, 110, true, true, false, true);
//    CarService::instance().addCar("ВАЗ 2110", 4, "Эконом", "Механика", "Передний",
//                                  1.2, 110, true, true, true, true);
//    CarService::instance().addCar("Volkswagen Polo", 4, "Эконом", "Робот", "Передний",
//                                  1.6, 110, true, true, false, true);

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
    filterButton->move(90, 50);
    connect(filterButton, &QPushButton::clicked, this, &CarListWidget::openFilterDialog);
}

void CarListWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // Установка основного фона
    painter.fillRect(rect(), QColor("#D3D3D3"));  // светло-серый фон

    // Белый треугольник
    painter.setBrush(QColor("#ffffff"));
    painter.setPen(Qt::NoPen);
    QPolygon greyTriangle;
    greyTriangle << QPoint(width(), 0)
                 << QPoint(width() - width() / 3, 0)
                 << QPoint(width(), height() / 10);
    painter.drawPolygon(greyTriangle);

    // Мятный треугольник
    painter.setBrush(QColor("#A0EACD"));
    QPolygon mintTriangle;
    mintTriangle << QPoint(0, 0)
                 << QPoint(width() / 3, 0)
                 << QPoint(0, height() / 10);
    painter.drawPolygon(mintTriangle);
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

    double pricePerMinute = CarService::instance().getOptimalPricePerMinute(car);
    QLabel *perMinuteLabel = new QLabel(QString::number(pricePerMinute) + " ₽/мин", cardWidget);
    perMinuteLabel->setAlignment(Qt::AlignCenter);

    double pricePerHour = CarService::instance().getOptimalPricePerHour(car);
    QLabel *perHourLabel = new QLabel(QString::number(pricePerHour) + " ₽/час", cardWidget);
    perHourLabel->setAlignment(Qt::AlignCenter);

    QLabel *categoryLabel = new QLabel(car.getCategory(), cardWidget);
    categoryLabel->setAlignment(Qt::AlignCenter);

    QPushButton *rentButton = new QPushButton("Арендовать", cardWidget);
    rentButton->setFixedHeight(30);
    rentButton->setStyleSheet(
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



