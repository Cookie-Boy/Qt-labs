#include "addcarwidget.h"
#include "ui_addcarwidget.h"
#include "basewidget.h"

#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QCheckBox>

AddCarWidget::AddCarWidget(QStackedWidget *stackedWidget, QWidget *parent) :
    BaseWidget(stackedWidget, parent),
    ui(new Ui::AddCarWidget)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Центрирование основного содержимого
    mainLayout->setAlignment(Qt::AlignCenter);

    // Контейнер для содержимого с фиксированной шириной
    QWidget *contentWidget = new QWidget(this);
    contentWidget->setFixedWidth(600); // Задаем фиксированную ширину
    QVBoxLayout *contentLayout = new QVBoxLayout(contentWidget);

    // Поле для выбора имени машины
    QLabel *nameLabel = new QLabel("Имя машины:", this);
    contentLayout->addWidget(nameLabel);

    carNameCombo = new QComboBox(this);
    carNameCombo->setEditable(true); // Позволяет вводить вручную
    contentLayout->addWidget(carNameCombo);

    connect(carNameCombo, &QComboBox::currentTextChanged, this, &AddCarWidget::updateCarDetails);

    loadCarNames();

    // Кнопка выбора фото
    QLabel *photoLabel = new QLabel("Фото машины:", this);
    contentLayout->addWidget(photoLabel);

    photoButton = new QPushButton("Выбрать фото", this);
    contentLayout->addWidget(photoButton);

    photoPreview = new QLabel(this);
    photoPreview->setFixedSize(200, 150);
    photoPreview->setStyleSheet("border: 1px solid gray;");
    photoPreview->setAlignment(Qt::AlignCenter);
    contentLayout->addWidget(photoPreview);

    connect(photoButton, &QPushButton::clicked, this, &AddCarWidget::selectPhoto);

    // Информация о машине
    QGridLayout *detailsLayout = new QGridLayout();
    contentLayout->addLayout(detailsLayout);

    engineCapacityEdit = new QLineEdit(this);
    detailsLayout->addWidget(new QLabel("Объем двигателя:"), 0, 0);
    detailsLayout->addWidget(engineCapacityEdit, 0, 1);

    powerEdit = new QLineEdit(this);
    detailsLayout->addWidget(new QLabel("Мощность:"), 1, 0);
    detailsLayout->addWidget(powerEdit, 1, 1);

    categoryEdit = new QLineEdit(this);
    detailsLayout->addWidget(new QLabel("Категория:"), 2, 0);
    detailsLayout->addWidget(categoryEdit, 2, 1);

    transmissionEdit = new QLineEdit(this);
    detailsLayout->addWidget(new QLabel("Трансмиссия:"), 3, 0);
    detailsLayout->addWidget(transmissionEdit, 3, 1);

    driveTypeEdit = new QLineEdit(this);
    detailsLayout->addWidget(new QLabel("Привод:"), 4, 0);
    detailsLayout->addWidget(driveTypeEdit, 4, 1);

    heatedSeatsCheckBox = new QCheckBox("Подогрев сидений", this);
    detailsLayout->addWidget(heatedSeatsCheckBox, 5, 0);

    heatedSteeringWheelCheckBox = new QCheckBox("Подогрев руля", this);
    detailsLayout->addWidget(heatedSteeringWheelCheckBox, 5, 1);

    parkingSensorsCheckBox = new QCheckBox("Парковочные датчики", this);
    detailsLayout->addWidget(parkingSensorsCheckBox, 6, 0);

    // Кнопка добавления машины
    addButton = new QPushButton("Добавить машину", this);
    contentLayout->addWidget(addButton);

    connect(addButton, &QPushButton::clicked, this, &AddCarWidget::addCar);

    // Добавляем контентный виджет в главный макет
    mainLayout->addWidget(contentWidget);
}

void AddCarWidget::updateCarDetails(const QString &carName) {
    if (!carExistsInDatabase(carName)) {
        // Сбрасываем информацию, если машина не найдена
        engineCapacityEdit->clear();
        powerEdit->clear();
        categoryEdit->clear();
        transmissionEdit->clear();
        driveTypeEdit->clear();
        heatedSeatsCheckBox->setChecked(false);
        heatedSteeringWheelCheckBox->setChecked(false);
        parkingSensorsCheckBox->setChecked(false);
        return;
    }

    // Получаем данные из базы
    Car car = getCarDetailsFromDatabase(carName);

    engineCapacityEdit->setText(QString::number(car.getEngineCapacity()));
    powerEdit->setText(QString::number(car.getPower()));
    categoryEdit->setText(car.getCategory());
    transmissionEdit->setText(car.getTransmission());
    driveTypeEdit->setText(car.getDriveType());
    heatedSeatsCheckBox->setChecked(car.getHasHeatedSeats());
    heatedSteeringWheelCheckBox->setChecked(car.getHasHeatedSteeringWheel());
    parkingSensorsCheckBox->setChecked(car.getHasParkingSensors());
}

Car AddCarWidget::getCarDetailsFromDatabase(const QString &carName) {
//    QSqlQuery query;
//    query.prepare("SELECT * FROM cars WHERE name = :name LIMIT 1");
//    query.bindValue(":name", carName);
//    query.exec();

//    if (query.next()) {
//        return Car(
//            query.value("id").toLongLong(),
//            query.value("name").toString(),
//            query.value("rating").toInt(),
//            query.value("category").toString(),
//            query.value("transmission").toString(),
//            query.value("drive_type").toString(),
//            query.value("engine_capacity").toDouble(),
//            query.value("power").toDouble(),
//            query.value("has_spacious_trunk").toBool(),
//            query.value("has_heated_seats").toBool(),
//            query.value("has_heated_steering_wheel").toBool(),
//            query.value("has_parking_sensors").toBool()
//        );
//    }

    return Car();
}


AddCarWidget::~AddCarWidget()
{
    delete ui;
}

void AddCarWidget::selectPhoto() {
    QString filePath = QFileDialog::getOpenFileName(this, "Выберите фото", "", "Images (*.png *.jpg *.jpeg)");
    if (!filePath.isEmpty()) {
        selectedPhotoPath = filePath;
        QPixmap pixmap(filePath);
        photoPreview->setPixmap(pixmap.scaled(photoPreview->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

void AddCarWidget::addCar() {
    QString carName = carNameCombo->currentText();
    if (carName.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите или выберите имя машины.");
        return;
    }

    if (selectedPhotoPath.isEmpty() && !carExistsInDatabase(carName)) {
        QMessageBox::warning(this, "Ошибка", "Выберите фото или выберите существующую машину.");
        return;
    }

    QString photoPath = selectedPhotoPath;

    if (photoPath.isEmpty()) {
        // Загружаем фото из базы данных
        photoPath = getPhotoForExistingCar(carName);
        if (photoPath.isEmpty()) {
            QMessageBox::warning(this, "Ошибка", "Не удалось загрузить фото для существующей машины.");
            return;
        }
    }

    // Добавляем машину в базу данных
    if (addCarToDatabase(carName, photoPath)) {
        QMessageBox::information(this, "Успех", "Машина успешно добавлена.");
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось добавить машину.");
    }
}

void AddCarWidget::loadCarNames() {
//    QSqlQuery query("SELECT DISTINCT name FROM cars");
//    while (query.next()) {
//        carNameCombo->addItem(query.value(0).toString());
//    }
}

bool AddCarWidget::carExistsInDatabase(const QString &carName) {
//    QSqlQuery query;
//    query.prepare("SELECT COUNT(*) FROM cars WHERE name = :name");
//    query.bindValue(":name", carName);
//    if (query.exec() && query.next()) {
//        return query.value(0).toInt() > 0;
//    }
//    return false;
}

QString AddCarWidget::getPhotoForExistingCar(const QString &carName) {
//    QSqlQuery query;
//    query.prepare("SELECT photo_path FROM cars WHERE name = :name LIMIT 1");
//    query.bindValue(":name", carName);
//    if (query.exec() && query.next()) {
//        return query.value(0).toString();
//    }
//    return QString();
}

bool AddCarWidget::addCarToDatabase(const QString &carName, const QString &photoPath) {
//    QSqlQuery query;
//    query.prepare("INSERT INTO cars (name, photo_path) VALUES (:name, :photo)");
//    query.bindValue(":name", carName);
//    query.bindValue(":photo", photoPath);
//    return query.exec();
}
