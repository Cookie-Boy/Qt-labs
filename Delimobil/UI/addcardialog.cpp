#include "addcardialog.h"
#include "ui_addcardialog.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>
#include <QCheckBox>

AddCarDialog::AddCarDialog(QWidget *parent) :
    QDialog(parent), // Используем BaseWidget как базовый класс
    ui(new Ui::AddCarDialog),
    carService(CarService::instance())
{
    ui->setupUi(this);

        setWindowTitle("Редактор машины");
        setMinimumSize(854, 480); // Минимальный размер
        resize(854, 480);        // Начальный размер

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
                background-color: white;
                font-size: 14px;
            }
            QPushButton {
                background-color: #4CAF50;
                color: white;
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
    nameLabel->setStyleSheet("color: white; font-size: 14px;");
    mainLayout->addWidget(nameLabel);

    carNameCombo = new QComboBox(this);
    carNameCombo->setEditable(true);
    carNameCombo->setStyleSheet("color: black; background-color: white; font-size: 14px;");
    carNameCombo->setCurrentIndex(-1);
    carNameCombo->addItem("");

    connect(carNameCombo, &QComboBox::currentTextChanged, this, &AddCarDialog::updateCarDetails);

    fillCarNamesBox();

    mainLayout->addWidget(carNameCombo);

    // Кнопка выбора фото
    QLabel *photoLabel = new QLabel("Фото машины:", this);
    photoLabel->setStyleSheet("color: white; font-size: 14px;");
    mainLayout->addWidget(photoLabel);

    photoButton = new QPushButton("Выбрать фото", this);
    photoButton->setStyleSheet("background-color: #4CAF50; color: white; font-size: 14px; padding: 5px;");
    mainLayout->addWidget(photoButton);

    photoPreview = new QLabel(this);
    photoPreview->setFixedSize(200, 150);
    photoPreview->setStyleSheet("border: 1px solid gray; background-color: white;");
    photoPreview->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(photoPreview);

    connect(photoButton, &QPushButton::clicked, this, &AddCarDialog::selectPhoto);

    // Информация о машине
    QGridLayout *detailsLayout = new QGridLayout();
    detailsLayout->setSpacing(10);
    mainLayout->addLayout(detailsLayout);

    setupDetailField(detailsLayout, "Объем двигателя:", engineCapacityEdit, 0, 0);
    setupDetailField(detailsLayout, "Мощность:", powerEdit, 1, 0);
    setupDetailField(detailsLayout, "Категория:", categoryEdit, 2, 0);
    setupDetailField(detailsLayout, "Трансмиссия:", transmissionEdit, 3, 0);
    setupDetailField(detailsLayout, "Привод:", driveTypeEdit, 4, 0);

    heatedSeatsCheckBox = new QCheckBox("Подогрев сидений", this);
    heatedSeatsCheckBox->setStyleSheet("color: white; font-size: 14px;");
    detailsLayout->addWidget(heatedSeatsCheckBox, 5, 0);

    heatedSteeringWheelCheckBox = new QCheckBox("Подогрев руля", this);
    heatedSteeringWheelCheckBox->setStyleSheet("color: white; font-size: 14px;");
    detailsLayout->addWidget(heatedSteeringWheelCheckBox, 5, 1);

    parkingSensorsCheckBox = new QCheckBox("Парковочные датчики", this);
    parkingSensorsCheckBox->setStyleSheet("color: white; font-size: 14px;");
    detailsLayout->addWidget(parkingSensorsCheckBox, 6, 0);

    // Кнопка добавления машины
    addButton = new QPushButton("Добавить машину", this);
    addButton->setStyleSheet("background-color: #4CAF50; color: white; font-size: 16px; padding: 10px;");
    mainLayout->addWidget(addButton);

    connect(addButton, &QPushButton::clicked, this, &AddCarDialog::addCar);
}

void AddCarDialog::setupDetailField(QGridLayout *layout, const QString &labelText, QLineEdit *&editField, int row, int col) {
    QLabel *label = new QLabel(labelText, this);
    label->setStyleSheet("color: white; font-size: 14px;");
    layout->addWidget(label, row, col);

    editField = new QLineEdit(this);
    editField->setStyleSheet("color: black; background-color: white; font-size: 14px;");
    layout->addWidget(editField, row, col + 1);
}

AddCarDialog::~AddCarDialog() {
    delete ui;
}

void AddCarDialog::selectPhoto() {
    QString filePath = QFileDialog::getOpenFileName(this, "Выберите фото", "", "Images (*.png *.jpg *.jpeg)");
    if (!filePath.isEmpty()) {
        selectedPhotoPath = filePath;
        QPixmap pixmap(filePath);
        photoPreview->setPixmap(pixmap.scaled(photoPreview->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

void AddCarDialog::addCar() {
    QString carName = carNameCombo->currentText();
    if (carName.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите или выберите имя машины.");
        return;
    }

    if (selectedPhotoPath.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Выберите фото для машины");
        return;
    }

    QString photoPath = selectedPhotoPath;

    // Добавляем машину в базу данных

    Car car = Car(carNameCombo->currentText(),
                  0,
                  categoryEdit->text(),
                  transmissionEdit->text(),
                  driveTypeEdit->text(),
                  engineCapacityEdit->text().toDouble(),
                  powerEdit->text().toDouble(),
                  selectedPhotoPath,
                  heatedSeatsCheckBox->checkState() == Qt::Checked ? true : false,
                  heatedSteeringWheelCheckBox->checkState() == Qt::Checked ? true : false,
                  parkingSensorsCheckBox->checkState() == Qt::Checked ? true : false,
                  false);

    QString name = carNameCombo->currentText();
    QString category = categoryEdit->text();
    QString transmission = transmissionEdit->text();
    QString driveType = driveTypeEdit->text();

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
                          false)) {

        QMessageBox::information(this, "Успех", "Машина успешно добавлена.");
        accept();
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось добавить машину.");
    }
}

void AddCarDialog::fillCarNamesBox() {
    QVector<QString> uniqueNames = carService.getUniqueCarNames();
    for (QString name : uniqueNames) {
        carNameCombo->addItem(name);
    }
}

void AddCarDialog::updateCarDetails(const QString &carName) {
    Car *car = carService.getCarByName(carName);
    if (car == nullptr)
        return;

    // Фото машины
    QPixmap pixmap(car->getImagePath());
    photoPreview->setPixmap(pixmap.scaled(photoPreview->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // Информация о машине
    engineCapacityEdit->setText(QString::number(car->getEngineCapacity()));
    powerEdit->setText(QString::number(car->getPower()));
    categoryEdit->setText(car->getCategory());
    transmissionEdit->setText(car->getDriveType());
    driveTypeEdit->setText(car->getDriveType());
    heatedSeatsCheckBox->setCheckState(car->getHasHeatedSeats() ? Qt::Checked : Qt::Unchecked);
    heatedSteeringWheelCheckBox->setCheckState(car->getHasHeatedSteeringWheel() ? Qt::Checked : Qt::Unchecked);
    parkingSensorsCheckBox->setCheckState(car->getHasParkingSensors() ? Qt::Checked : Qt::Unchecked);
}
