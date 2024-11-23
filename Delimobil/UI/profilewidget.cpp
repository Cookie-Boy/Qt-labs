#include "ProfileWidget.h"

ProfileWidget::ProfileWidget(QStackedWidget *stackedWidget, QWidget *parent)
    : BaseWidget(stackedWidget, parent),
      lastNameEdit(new QLineEdit(this)),
      firstNameEdit(new QLineEdit(this)),
      middleNameEdit(new QLineEdit(this)),
      emailEdit(new QLineEdit(this)),
      editButton(new QPushButton("Редактировать", this)),
      saveButton(new QPushButton("Сохранить", this)),
      tripsButton(new QPushButton("Мои поездки", this)),
      reviewsButton(new QPushButton("Мои отзывы", this))
{
    lastNameEdit->setReadOnly(true);
    firstNameEdit->setReadOnly(true);
    middleNameEdit->setReadOnly(true);
    emailEdit->setReadOnly(true);

    // Установка цветовой схемы и стилей
    setStyleSheet("QWidget { background-color: #D3D3D3; }"
                  "QLineEdit { background-color: #ffffff; border-radius: 5px; padding: 5px; }"
                  "QPushButton { background-color: #A0EACD; border-radius: 5px; padding: 10px; }"
                  "QPushButton:hover { background-color: #7FC5A8; }");

    // Создание лейблов
    QLabel *lastNameLabel = new QLabel("Фамилия:", this);
    QLabel *firstNameLabel = new QLabel("Имя:", this);
    QLabel *middleNameLabel = new QLabel("Отчество:", this);
    QLabel *emailLabel = new QLabel("Email:", this);

    // Установка лейблов и полей ввода
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(lastNameLabel);
    layout->addWidget(lastNameEdit);
    layout->addWidget(firstNameLabel);
    layout->addWidget(firstNameEdit);
    layout->addWidget(middleNameLabel);
    layout->addWidget(middleNameEdit);
    layout->addWidget(emailLabel);
    layout->addWidget(emailEdit);
    layout->addWidget(editButton);
    layout->addWidget(saveButton);
    layout->addWidget(reviewsButton);
    layout->addWidget(tripsButton);

    saveButton->setVisible(false);

    connect(editButton, &QPushButton::clicked, this, &ProfileWidget::onEditButtonClicked);
    connect(saveButton, &QPushButton::clicked, this, &ProfileWidget::onSaveButtonClicked);
}

void ProfileWidget::onEditButtonClicked()
{
    lastNameEdit->setReadOnly(false);
    firstNameEdit->setReadOnly(false);
    middleNameEdit->setReadOnly(false);
    emailEdit->setReadOnly(false);

    editButton->setVisible(false);
    saveButton->setVisible(true);
}

void ProfileWidget::onSaveButtonClicked()
{
    lastNameEdit->setReadOnly(true);
    firstNameEdit->setReadOnly(true);
    middleNameEdit->setReadOnly(true);
    emailEdit->setReadOnly(true);

    editButton->setVisible(true);
    saveButton->setVisible(false);
}
