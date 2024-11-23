#include "careditordialog.h"
#include "ui_careditordialog.h"
#include "calendardialog.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>
#include <QCheckBox>
#include <QInputDialog>
#include <QCalendarWidget>

CarEditorDialog::CarEditorDialog(QWidget *parent, const Car *car) :
    QDialog(parent),
    ui(new Ui::CarEditorDialog),
    carService(CarService::instance()),
    editingCar(car)
{
    ui->setupUi(this);

        setWindowTitle("Редактор машины");
        setMinimumSize(800, 700); // Минимальный размер
        resize(800, 700);        // Начальный размер

        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->setSpacing(15);
        mainLayout->setContentsMargins(20, 20, 20, 20);

        this->setStyleSheet(R"(
            QDialog {
                background-color: #D3D3D3;
            }
            QLabel {
                color: black;
                font-size: 14px;
            }
            QLineEdit, QComboBox {
                color: black;
                background-;
                font-size: 14px;
            }
            QPushButton {
                background-color: #4CAF50;
                ;
                font-size: 14px;
                padding: 10px;
                border-radius: 5px;
            }
            QPushButton:hover {
                background-color: #45a049;
            }
            QCheckBox {
                color: black;
                font-size: 14px;
            }
        )");

    // Поле для выбора имени машины
    QLabel *nameLabel = new QLabel("Имя машины:", this);
    nameLabel->setStyleSheet("font-size: 14px;");
    mainLayout->addWidget(nameLabel);

    carNameCombo = new QComboBox(this);
    carNameCombo->setEditable(true);
    carNameCombo->setStyleSheet("color: black; background-color: white; font-size: 14px;");
    carNameCombo->setCurrentIndex(-1);
    carNameCombo->addItem("");

    connect(carNameCombo,
            QOverload<const QString &>::of(&QComboBox::activated),
            this,
            static_cast<void (CarEditorDialog::*)(const QString &)>(&CarEditorDialog::updateCarDetails));

    fillCarNamesBox();

    mainLayout->addWidget(carNameCombo);

    // Кнопка выбора фото
    QLabel *photoLabel = new QLabel("Фото машины:", this);
//    photoLabel->setStyleSheet("; font-size: 14px;");
    mainLayout->addWidget(photoLabel);

    photoButton = new QPushButton("Выбрать фото", this);
    photoButton->setStyleSheet("background-color: #4CAF50; font-size: 14px; padding: 5px;");
    mainLayout->addWidget(photoButton);

    photoPreview = new QLabel(this);
    photoPreview->setFixedSize(200, 150);
    photoPreview->setStyleSheet("border: 1px solid gray; background-color: white;");
    photoPreview->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(photoPreview);

    connect(photoButton, &QPushButton::clicked, this, &CarEditorDialog::selectPhoto);

    // Информация о машине
    QGridLayout *detailsLayout = new QGridLayout();
    detailsLayout->setSpacing(10);
    mainLayout->addLayout(detailsLayout);

    QLabel *label = new QLabel("Объем двигателя:", this);
    label->setStyleSheet("font-size: 14px;");
    detailsLayout->addWidget(label, 0, 0);

    engineCapacityEdit = new QLineEdit(this);
    engineCapacityEdit->setStyleSheet("color: black; background-color: white; font-size: 14px;");
    detailsLayout->addWidget(engineCapacityEdit, 0, 1);

    label = new QLabel("Мощность:", this);
    label->setStyleSheet("font-size: 14px;");
    detailsLayout->addWidget(label, 1, 0);

    powerEdit = new QLineEdit(this);
    powerEdit->setStyleSheet("color: black; background-color: white; font-size: 14px;");
    detailsLayout->addWidget(powerEdit, 1, 1);

    setupDetailField(detailsLayout, "Категория:", categoryCombo, {"Эконом", "Комфорт", "Бизнес"}, 2, 0);
    setupDetailField(detailsLayout, "Трансмиссия:", transmissionCombo, {"Автомат", "Робот", "Механика"}, 3, 0);
    setupDetailField(detailsLayout, "Привод:", driveTypeCombo, {"Передний", "Задний", "Полный"}, 4, 0);

    heatedSeatsCheckBox = new QCheckBox("Подогрев сидений", this);
    heatedSeatsCheckBox->setStyleSheet("font-size: 14px;");
    detailsLayout->addWidget(heatedSeatsCheckBox, 5, 0);

    heatedSteeringWheelCheckBox = new QCheckBox("Подогрев руля", this);
    heatedSteeringWheelCheckBox->setStyleSheet("font-size: 14px;");
    detailsLayout->addWidget(heatedSteeringWheelCheckBox, 5, 1);

    parkingSensorsCheckBox = new QCheckBox("Парковочные датчики", this);
    parkingSensorsCheckBox->setStyleSheet("font-size: 14px;");
    detailsLayout->addWidget(parkingSensorsCheckBox, 6, 0);

    if (car) {
        blockedPeriod = car->getBlockedPeriod();
    }

    blockedPeriodButton = new QPushButton("Заблокировать на период", this);
    connect(blockedPeriodButton, &QPushButton::clicked, this, &CarEditorDialog::setBlockedPeriod);
    mainLayout->addWidget(blockedPeriodButton);

    // Кнопка добавления машины
    addButton = new QPushButton(editingCar == nullptr ? "Добавить" : "Изменить", this);
    addButton->setStyleSheet("background-color: #4CAF50; font-size: 16px; padding: 10px;");
    mainLayout->addWidget(addButton);

    if (editingCar == nullptr) {
        connect(addButton, &QPushButton::clicked, this, &CarEditorDialog::addCar);
    } else {
        connect(addButton, &QPushButton::clicked, this, &CarEditorDialog::changeCar);
    }

    foreach (QPushButton *button, this->findChildren<QPushButton*>()) {
        button->setCursor(Qt::PointingHandCursor);
        button->setStyleSheet("QPushButton { background-color: #A0EACD; border-radius: 10px; }");
    }
    blockedPeriodButton->setStyleSheet("QPushButton { background-color: #E48F94; border-radius: 10px }");

    carNameCombo->clearFocus();
    this->setFocus();
}

void CarEditorDialog::setupDetailField(QGridLayout *layout, const QString &labelText, QComboBox *&comboBox, QVector<QString> items, int row, int col) {
    QLabel *nameLabel = new QLabel(labelText, this);
    nameLabel->setStyleSheet("font-size: 14px;");
    layout->addWidget(nameLabel, row, col);

    comboBox = new QComboBox(this);
    comboBox->setStyleSheet("color: black; background-color: white; font-size: 14px;");
    comboBox->setCurrentIndex(-1);
    comboBox->addItem("");
    for (QString item : items) {
        comboBox->addItem(item);
    }

    layout->addWidget(comboBox, row, col + 1);
}

CarEditorDialog::~CarEditorDialog() {
    delete ui;
}

void CarEditorDialog::setBlockedPeriod() {
    qDebug() << "Выбор периода блокировки начался";

    blockedPeriod = editingCar->getBlockedPeriod();
    CalendarDialog dateDialog(blockedPeriod.first, blockedPeriod.second, this);
    if (dateDialog.exec() == QDialog::Accepted) {
        if (dateDialog.isUnblockRequested()) {
            qDebug() << "Период блокировки снят.";
            blockedPeriod = qMakePair(QDate(), QDate());
        } else {
            QPair<QDate, QDate> period = dateDialog.selectedDates();
            QDate startDate = period.first;
            QDate endDate = period.second;

            qDebug() << "Выбранный период блокировки: с" << startDate << "по" << endDate;

            // Сохраняем период
            blockedPeriod = period;
        }
    } else {
        qDebug() << "Выбор периода блокировки отменен.";
    }
}

void CarEditorDialog::selectPhoto() {
    QString filePath = QFileDialog::getOpenFileName(this, "Выберите фото", "", "Images (*.png *.jpg *.jpeg)");
    if (!filePath.isEmpty()) {
        selectedPhotoPath = filePath;
        QPixmap pixmap(filePath);
        photoPreview->setPixmap(pixmap.scaled(photoPreview->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

void CarEditorDialog::changeCar() {
    QString carName = carNameCombo->currentText();
    if (carName.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите или выберите имя машины.");
        return;
    }

    if (selectedPhotoPath.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Выберите фото для машины");
        return;
    }

    Car newCar = Car(carNameCombo->currentText(),
                  0,
                  categoryCombo->currentText(),
                  transmissionCombo->currentText(),
                  driveTypeCombo->currentText(),
                  engineCapacityEdit->text().toDouble(),
                  powerEdit->text().toDouble(),
                  selectedPhotoPath,
                  heatedSeatsCheckBox->checkState() == Qt::Checked ? true : false,
                  heatedSteeringWheelCheckBox->checkState() == Qt::Checked ? true : false,
                  parkingSensorsCheckBox->checkState() == Qt::Checked ? true : false,
                  blockedPeriod);

    if (carService.changeCar(*editingCar, newCar)) {
        QMessageBox::information(this, "Успех", "Машина успешно изменена.");
        accept();
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось изменить машину.");
    }
}

void CarEditorDialog::addCar() {
    QString carName = carNameCombo->currentText();
    if (carName.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите или выберите имя машины.");
        return;
    }

    if (selectedPhotoPath.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Выберите фото для машины");
        return;
    }

    QString name = carNameCombo->currentText();
    QString category = categoryCombo->currentText();
    QString transmission = transmissionCombo->currentText();
    QString driveType = driveTypeCombo->currentText();

    if (carService.addCar(name,
                          0,
                          category,
                          transmission,
                          driveType,
                          engineCapacityEdit->text().toDouble(),
                          powerEdit->text().toDouble(),
                          selectedPhotoPath,
                          heatedSeatsCheckBox->checkState() == Qt::Checked ? true : false,
                          heatedSteeringWheelCheckBox->checkState() == Qt::Checked ? true : false,
                          parkingSensorsCheckBox->checkState() == Qt::Checked ? true : false,
                          blockedPeriod)) {

        QMessageBox::information(this, "Успех", "Машина успешно добавлена.");
        accept();
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось добавить машину.");
    }
}

void CarEditorDialog::fillCarNamesBox() {
    QVector<QString> uniqueNames = carService.getUniqueCarNames();
    for (QString name : uniqueNames) {
        carNameCombo->addItem(name);
    }
}

void CarEditorDialog::updateCarDetails(const QString &carName) {
    Car *car = carService.getCarByName(carName);
    if (car == nullptr)
        return;

    updateCarDetails(car);
}

void CarEditorDialog::updateCarDetails(const Car *car) {
    QString carName = car->getName();
    QString currentComboText = carNameCombo->currentText();
    if (currentComboText != carName) {
        carNameCombo->setCurrentText(carName);
    }

    // Фото машины
    selectedPhotoPath = car->getImagePath();
    QPixmap pixmap(selectedPhotoPath);
    photoPreview->setPixmap(pixmap.scaled(photoPreview->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // Информация о машине
    engineCapacityEdit->setText(QString::number(car->getEngineCapacity()));
    powerEdit->setText(QString::number(car->getPower()));
    categoryCombo->setCurrentText(car->getCategory());
    transmissionCombo->setCurrentText(car->getTransmission());
    driveTypeCombo->setCurrentText(car->getDriveType());
    heatedSeatsCheckBox->setCheckState(car->getHasHeatedSeats() ? Qt::Checked : Qt::Unchecked);
    heatedSteeringWheelCheckBox->setCheckState(car->getHasHeatedSteeringWheel() ? Qt::Checked : Qt::Unchecked);
    parkingSensorsCheckBox->setCheckState(car->getHasParkingSensors() ? Qt::Checked : Qt::Unchecked);
}
