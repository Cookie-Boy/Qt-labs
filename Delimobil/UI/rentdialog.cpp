#include "rentdialog.h"
#include "../services/carservice.h"

RentDialog::RentDialog(const Car &car, QWidget *parent)
    : QDialog(parent), confirmed(false) {
    setWindowTitle("Аренда автомобиля");
    setFixedSize(600, 750);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    this->setStyleSheet("background-color: white;");

    // Изображение автомобиля
    carImageLabel = new QLabel(this);
    QPixmap carImage(car.getImagePath());
    if (!carImage.isNull()) {
        carImageLabel->setPixmap(carImage.scaled(300, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        carImageLabel->setText("Изображение отсутствует");
        carImageLabel->setAlignment(Qt::AlignCenter);
    }
    carImageLabel->setStyleSheet("border: 1px solid #ccc; margin-bottom: 15px;");
    mainLayout->addWidget(carImageLabel, 0, Qt::AlignCenter);

    // Название автомобиля
    carNameLabel = new QLabel(car.getName(), this);
    carNameLabel->setStyleSheet("font-size: 18px; font-weight: bold; color: #333; margin-bottom: 10px;");
    carNameLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(carNameLabel);

    // Характеристики автомобиля
    QString details = QString(
        "<b>Рейтинг:</b> %1<br>"
        "<b>Категория:</b> %2<br>"
        "<b>Трансмиссия:</b> %3<br>"
        "<b>Привод:</b> %4<br>"
        "<b>Объем двигателя:</b> %5 л<br>"
        "<b>Мощность:</b> %6 л.с.<br>"
        "<b>Подогрев сидений:</b> %7<br>"
        "<b>Подогрев руля:</b> %8<br>"
        "<b>Парктроники:</b> %9")
        .arg(car.getRating())
        .arg(car.getCategory())
        .arg(car.getTransmission())
        .arg(car.getDriveType())
        .arg(car.getEngineCapacity())
        .arg(car.getPower())
        .arg(car.getHasHeatedSeats() ? "Да" : "Нет")
        .arg(car.getHasHeatedSteeringWheel() ? "Да" : "Нет")
        .arg(car.getHasParkingSensors() ? "Да" : "Нет");

    carDetailsLabel = new QLabel(details, this);
    carDetailsLabel->setStyleSheet("font-size: 14px; color: #333; margin-bottom: 20px;");
    carDetailsLabel->setWordWrap(true);
    mainLayout->addWidget(carDetailsLabel);

    double pricePerMinute = CarService::instance().getOptimalPricePerMinute(car);
    double pricePerHour = CarService::instance().getOptimalPricePerHour(car);
    double pricePerKilometer = CarService::instance().getOptimalPricePerKilometer(car);

    // Описание тарифов
    tariffDescriptionLabel = new QLabel(
        "<b>Описание тарифов:</b><br>"
        "<b>Поминутный тариф:</b> Идеально подходит для кратковременных поездок. "
        "Стоимость составляет <b>" + QString::number(pricePerMinute) + "</b> рублей за минуту аренды. "
        "Вы оплачиваете только фактическое время использования.<br><br>"
        "<b>Почасовой тариф:</b> Рекомендуется для длительных поездок. "
        "Стоимость аренды составляет <b>" + QString::number(pricePerHour) + "</b> рублей за час, "
        "с дополнительной платой в размере <b>" + QString::number(pricePerKilometer) + "</b> рублей за каждый пройденный километр. "
        "Этот тариф позволяет комфортно планировать поездки на длительные расстояния.<br><br>"
        "<i>Пожалуйста, выберите подходящий тариф и подтвердите аренду автомобиля.</i>",
        this);
    tariffDescriptionLabel->setStyleSheet("font-size: 14px; color: #555; margin-bottom: 20px;");
    tariffDescriptionLabel->setWordWrap(true);
    mainLayout->addWidget(tariffDescriptionLabel);

    // Кнопки выбора тарифа
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->setSpacing(20);

    minuteButton = new QPushButton("Поминутно", this);
    minuteButton->setObjectName("minuteButton");
    minuteButton->setStyleSheet("background-color: #4CAF50; color: white; padding: 10px 20px;");
    minuteButton->setCursor(Qt::PointingHandCursor);

    hourButton = new QPushButton("Почасово", this);
    hourButton->setObjectName("hourButton");
    hourButton->setStyleSheet("background-color: #2196F3; color: white; padding: 10px 20px;");
    hourButton->setCursor(Qt::PointingHandCursor);

    cancelButton = new QPushButton("Отмена", this);
    cancelButton->setObjectName("cancelButton");
    cancelButton->setStyleSheet("background-color: #f44336; color: white; padding: 10px 20px;");
    cancelButton->setCursor(Qt::PointingHandCursor);

    // Подключение кнопок
    connect(minuteButton, &QPushButton::clicked, this, [this]() {
        AuthorizedUser::instance().setRentMode(RentMode::PerMinute);
        confirmed = true;
        accept();
    });

    connect(hourButton, &QPushButton::clicked, this, [this]() {
        AuthorizedUser::instance().setRentMode(RentMode::PerHour);
        confirmed = true;
        accept();
    });

    connect(cancelButton, &QPushButton::clicked, this, &RentDialog::onCancel);

    // Добавляем кнопки в макет
    buttonLayout->addWidget(minuteButton);
    buttonLayout->addWidget(hourButton);
    buttonLayout->addWidget(cancelButton);

    mainLayout->addLayout(buttonLayout);
}

bool RentDialog::isConfirmed() const {
    return confirmed;
}

void RentDialog::onCancel() {
    reject();
}
