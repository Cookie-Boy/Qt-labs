#include "currentrentaldialog.h"
#include "ui_currentrentaldialog.h"

CurrentRentalDialog::CurrentRentalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CurrentRentalDialog)
{
    ui->setupUi(this);
    setupUI();

    connect(&AuthorizedUser::instance(), &AuthorizedUser::tripPriceUpdated,
                this, &CurrentRentalDialog::updateRentalPrice);
}

CurrentRentalDialog::~CurrentRentalDialog() {
    delete ui;
}

void CurrentRentalDialog::setupUI() {
    setWindowTitle("Текущая аренда");
    setFixedSize(600, 400);

    mainLayout = new QVBoxLayout(this);

    // Изображение машины
    carImageLabel = new QLabel(this);
    QPixmap carImage(AuthorizedUser::instance().getCar()->getImagePath());
    if (!carImage.isNull()) {
        carImageLabel->setPixmap(carImage.scaled(300, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        carImageLabel->setText("Изображение отсутствует");
        carImageLabel->setAlignment(Qt::AlignCenter);
    }
    mainLayout->addWidget(carImageLabel, 0, Qt::AlignCenter);

    // Название машины
    carNameLabel = new QLabel(AuthorizedUser::instance().getCar()->getName(), this);
    carNameLabel->setStyleSheet("font-size: 18px; font-weight: bold; color: #333;");
    carNameLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(carNameLabel);

    // Информация о стоимости
    double tripPrice = AuthorizedUser::instance().getTripPrice();
    rentalCostLabel = new QLabel("Текущая стоимость аренды: " + QString::number(tripPrice, 'f', 2) + " рублей", this);
    rentalCostLabel->setStyleSheet("font-size: 16px; color: #555;");
    rentalCostLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(rentalCostLabel);

    // Кнопки
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    endRentalButton = new QPushButton("Завершить аренду", this);
    pauseRentalButton = new QPushButton("В ожидание", this);

    buttonLayout->addWidget(endRentalButton);
    buttonLayout->addWidget(pauseRentalButton);

    connect(endRentalButton, &QPushButton::clicked, this, &CurrentRentalDialog::onEndRentalClicked);
    connect(pauseRentalButton, &QPushButton::clicked, this, &CurrentRentalDialog::onPauseRentalClicked);

    mainLayout->addLayout(buttonLayout);
}

void CurrentRentalDialog::updateRentalPrice(double newPrice) {
    rentalCostLabel->setText("Текущая стоимость аренды: " + QString::number(newPrice, 'f', 2) + " рублей");
}

void CurrentRentalDialog::onEndRentalClicked() {
    // Логика для сохранения поездки в базу данных

    if (AuthorizedUser::instance().getRentMode() == RentMode::PerHour) {
        if (!finishHourlyRental()) {
            QMessageBox::warning(this, "Ошибка", "Произошла ошибка при завершении аренды.");
        }
    }

    CarService::instance().stopRent();
    QMessageBox::information(this, "Информация об аренде", "Аренда успешно завершена.");
    accept();
}

bool CurrentRentalDialog::finishHourlyRental() {
    bool ok;

    QInputDialog::getInt(
        this,
        "Завершение аренды",
        "Введите количество километров:",
        0,     // Значение по умолчанию
        0,     // Минимум
        10000, // Максимум
        1,     // Шаг
        &ok    // Указатель на результат действия пользователя
    );

    return ok;
}

void CurrentRentalDialog::onPauseRentalClicked() {
    if (pauseRentalButton->text() == "В ожидание") {
        pauseRentalButton->setText("Поездка");
        CarService::instance().pauseRent();
        return;
    }

    pauseRentalButton->setText("В ожидание");
    CarService::instance().startRent();
}
