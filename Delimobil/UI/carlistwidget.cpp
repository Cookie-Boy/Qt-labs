#include "carlistwidget.h"
#include "ui_carlistwidget.h"
#include "../services/carservice.h"
#include "../models/car.h"
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
    foreach (QPushButton *button, this->findChildren<QPushButton*>()) {
        button->setCursor(Qt::PointingHandCursor);
    }

    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

//    CarService::instance().addCar("Hyundai Solaris", 4, "Эконом", "Автомат", "Передний",
//                                  1.6, 110, true, true, false, true);
//    CarService::instance().addCar("ВАЗ 2110", 4, "Эконом", "Механика", "Передний",
//                                  1.2, 110, true, true, true, true);
//    CarService::instance().addCar("Volkswagen Polo", 4, "Эконом", "Робот", "Передний",
//                                  1.6, 110, true, true, false, true);

    QVector<Car> cars = CarService::instance().getAllCars();
    QGridLayout *layout = ui->layout;

    layout->setHorizontalSpacing(18); // Отступ по горизонтали между карточками
    layout->setVerticalSpacing(20);
    layout->setAlignment(Qt::AlignCenter);
    QString projectPath = "C:\\Users\\vital\\OneDrive\\My projects\\5 semester\\Qt projects\\Delimobil";

    int row = 0;
    int col = 0;
    for (const Car &car : cars) {
        QWidget *commonWidget = new QWidget(this);
        QVBoxLayout *commonLayout = new QVBoxLayout(commonWidget);
        // Создаем контейнер для карточки
        QWidget *cardWidget = new QWidget(commonWidget);
        cardWidget->setFixedSize(210, 250); // Размер карточки
        cardWidget->setStyleSheet("QWidget { background-color: #f5f5f5; border-radius: 20px; }");

        // Верхняя часть с изображением
        QLabel *imageLabel = new QLabel(cardWidget);
        QPixmap pixmap(projectPath + "\\images\\cars\\" + car.getName() + ".png");
        imageLabel->setPixmap(pixmap.scaled(210, 120, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
        imageLabel->setFixedSize(210, 120);
        imageLabel->setStyleSheet("QLabel { border-radius: 20px; }");

        // Метки с информацией о машине
        QLabel *nameLabel = new QLabel(car.getName(), cardWidget);
        nameLabel->setAlignment(Qt::AlignCenter);

        double price = CarService::instance().getOptimalPricePerMinute(car);
        QLabel *priceLabel = new QLabel(QString::number(price) + " ₽/мин", cardWidget);
        priceLabel->setAlignment(Qt::AlignCenter);

        QLabel *categoryLabel = new QLabel(car.getCategory(), cardWidget);
        categoryLabel->setAlignment(Qt::AlignCenter);

        // Кнопка "Арендовать"
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
            "QPushButton:hover {"
            "   background-color: #8ad3c6;"
            "}"
            "QPushButton:pressed {"
            "   background-color: #7ac2b6;"
            "}"
        );

        // Макет для элементов карточки
        QVBoxLayout *cardLayout = new QVBoxLayout(cardWidget);
        cardLayout->setSpacing(5);
        cardLayout->setContentsMargins(0, 0, 0, 0); // Отступы внутри карточки

        cardLayout->addWidget(imageLabel);
        cardLayout->addWidget(nameLabel);
        cardLayout->addWidget(priceLabel);
        cardLayout->addWidget(categoryLabel);

        commonLayout->addWidget(cardWidget);
        commonLayout->addWidget(rentButton);

        // Добавляем карточку в сетку
        layout->addWidget(commonWidget, row, col);

        // Управляем позиционированием карточек
        col++;
        if (col == 5) {
            col = 0;
            row++;
        }

        // Подключаем кнопку "Арендовать" к слоту
        connect(rentButton, &QPushButton::clicked, [car]() {
            // Логика для аренды автомобиля, например, открытие диалога подтверждения
        });

        foreach (QPushButton *button, this->findChildren<QPushButton*>()) {
            button->setCursor(Qt::PointingHandCursor);
        }
    }
}

CarListWidget::~CarListWidget()
{
    delete ui;
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
                 << QPoint(width() - (width() / 4), 0)
                 << QPoint(width(), height() / 11);
    painter.drawPolygon(greyTriangle);

    // Мятный треугольник
    painter.setBrush(QColor("#A0EACD"));
    QPolygon mintTriangle;
    mintTriangle << QPoint(0, 0)
                 << QPoint(width() / 4, 0)
                 << QPoint(0, height() / 11);
    painter.drawPolygon(mintTriangle);
}
