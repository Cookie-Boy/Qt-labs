#include "filterdialog.h"
#include <QVBoxLayout>
#include <QLabel>

FilterDialog::FilterDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Фильтр машин");
    setFixedSize(300, 400);

    // Установка стиля для окна и его элементов
    setStyleSheet(
        "QDialog {"
        "    background-color: #2E2E2E;" // Тёмный фон
        "    color: #FFFFFF;"            // Белый текст
        "    border-radius: 10px;"
        "}"
        "QLineEdit {"
        "    background-color: #404040;"
        "    border: 1px solid #A7E6DC;"
        "    border-radius: 5px;"
        "    color: #FFFFFF;"
        "    padding: 5px;"
        "}"
        "QComboBox {"
        "    background-color: #404040;"
        "    border: 1px solid #A7E6DC;"
        "    border-radius: 5px;"
        "    color: #FFFFFF;"
        "    padding: 3px;"
        "}"
        "QComboBox QAbstractItemView {"
        "    background-color: #404040;"
        "    color: #FFFFFF;"
        "    border: 1px solid #A7E6DC;"
        "}"
        "QCheckBox {"
        "    spacing: 5px;"
        "    font-size: 14px;"
        "    color: #A7E6DC;"
        "}"
        "QPushButton {"
        "    background-color: #A7E6DC;"
        "    color: #000000;"
        "    border-radius: 10px;"
        "    font-size: 14px;"
        "    padding: 8px 16px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8ad3c6;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #7ac2b6;"
        "}"
        "QLabel {"
        "    font-size: 14px;"
        "    color: #A7E6DC;"
        "}"
    );

    // Основной макет
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Поле для имени
    QLabel *nameLabel = new QLabel("Название:", this);
    nameEdit = new QLineEdit(this);
    layout->addWidget(nameLabel);
    layout->addWidget(nameEdit);

    // Список категорий
    QLabel *categoryLabel = new QLabel("Категория:", this);
    categoryCombo = new QComboBox(this);
    categoryCombo->addItem("Любая");
    categoryCombo->addItem("Эконом");
    categoryCombo->addItem("Комфорт");
    categoryCombo->addItem("Бизнес");
    layout->addWidget(categoryLabel);
    layout->addWidget(categoryCombo);

    // Поле для выбора трансмиссии
    QLabel *transmissionLabel = new QLabel("Трансмиссия:", this);
    transmissionCombo = new QComboBox(this);
    transmissionCombo->addItem("Любая");
    transmissionCombo->addItem("Автомат");
    transmissionCombo->addItem("Робот");
    transmissionCombo->addItem("Механика");
    layout->addWidget(transmissionLabel);
    layout->addWidget(transmissionCombo);

    // Поле для выбора привода
    QLabel *driveTypeLabel = new QLabel("Привод:", this);
    driveTypeCombo = new QComboBox(this);
    driveTypeCombo->addItem("Любой");
    driveTypeCombo->addItem("Передний");
    driveTypeCombo->addItem("Задний");
    driveTypeCombo->addItem("Полный");
    layout->addWidget(driveTypeLabel);
    layout->addWidget(driveTypeCombo);

    // Чекбоксы для дополнительных опций
    heatedSeatsCheck = new QCheckBox("Наличие подогрева сидений", this);
    parkingSensorsCheck = new QCheckBox("Наличие парктроников", this);
    layout->addWidget(heatedSeatsCheck);
    layout->addWidget(parkingSensorsCheck);

    // Поле для выбора даты
    QLabel *dateLabel = new QLabel("Дата:", this);
    dateEdit = new QDateEdit(QDate::currentDate(), this); // Устанавливаем текущую дату по умолчанию
    dateEdit->setCalendarPopup(true); // Включаем всплывающее окно календаря
    layout->addWidget(dateLabel);
    layout->addWidget(dateEdit);

    // Кнопка "Применить"
    applyButton = new QPushButton("Применить", this);
    applyButton->setFixedHeight(40); // Увеличенный размер
    applyButton->setCursor(Qt::PointingHandCursor); // Эффект курсора
    connect(applyButton, &QPushButton::clicked, this, &QDialog::accept);
    layout->addWidget(applyButton, 0, Qt::AlignCenter);
}

QString FilterDialog::getNameFilter() const { return nameEdit->text(); }
QString FilterDialog::getCategoryFilter() const { return categoryCombo->currentText(); }
QString FilterDialog::getTransmissionFilter() const { return transmissionCombo->currentText(); }
QString FilterDialog::getDriveTypeFilter() const { return driveTypeCombo->currentText(); }
bool FilterDialog::getHeatedSeatsFilter() const { return heatedSeatsCheck->isChecked(); }
bool FilterDialog::getParkingSensorsFilter() const { return parkingSensorsCheck->isChecked(); }
QDate FilterDialog::getDateFilter() const { return dateEdit->date(); }
