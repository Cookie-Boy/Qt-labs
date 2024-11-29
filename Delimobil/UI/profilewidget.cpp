#include "profilewidget.h"

ProfileWidget::ProfileWidget(QStackedWidget *stackedWidget, QStack<QWidget*> *widgetHistory, QWidget *parent)
    : BaseWidget(stackedWidget, widgetHistory, parent),
      lastNameEdit(new QLineEdit(this)),
      firstNameEdit(new QLineEdit(this)),
      middleNameEdit(new QLineEdit(this)),
      emailEdit(new QLineEdit(this)),
      editButton(new QPushButton("Редактировать", this)),
      saveButton(new QPushButton("Сохранить", this))
{

    lastNameEdit->setReadOnly(true);
    firstNameEdit->setReadOnly(true);
    middleNameEdit->setReadOnly(true);
    emailEdit->setReadOnly(true);

    // Установка цветовой схемы и стилей
    setStyleSheet("QLineEdit { background-color: #ffffff; border-radius: 5px; padding: 5px; }"
                  "QPushButton { background-color: #A0EACD; border-radius: 5px; padding: 10px; }"
                  "QPushButton:hover { background-color: #7FC5A8; }");

    // Создание лейблов
    QLabel *lastNameLabel = new QLabel("Фамилия:", this);
    QLabel *firstNameLabel = new QLabel("Имя:", this);
    QLabel *middleNameLabel = new QLabel("Отчество:", this);
    QLabel *emailLabel = new QLabel("Email:", this);

    // Центрирование содержимого и использование пропорциональной ширины
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QVBoxLayout *formLayout = new QVBoxLayout();

    lastNameEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    firstNameEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    middleNameEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    emailEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    formLayout->addWidget(lastNameLabel);
    formLayout->addWidget(lastNameEdit);
    formLayout->addWidget(firstNameLabel);
    formLayout->addWidget(firstNameEdit);
    formLayout->addWidget(middleNameLabel);
    formLayout->addWidget(middleNameEdit);
    formLayout->addWidget(emailLabel);
    formLayout->addWidget(emailEdit);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(editButton);
    buttonLayout->addWidget(saveButton);

    formLayout->addLayout(buttonLayout);

    QWidget *formWidget = new QWidget(this);
    formWidget->setLayout(formLayout);
    formWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    mainLayout->addStretch();
    mainLayout->addWidget(formWidget, 0, Qt::AlignHCenter);
    mainLayout->addStretch();

    saveButton->setVisible(false);

    editButton->setCursor(Qt::PointingHandCursor);
    saveButton->setCursor(Qt::PointingHandCursor);

    connect(editButton, &QPushButton::clicked, this, &ProfileWidget::onEditButtonClicked);
    connect(saveButton, &QPushButton::clicked, this, &ProfileWidget::onSaveButtonClicked);
}

void ProfileWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    // Рассчитать ширину полей и кнопок как 75% от ширины окна
    int widgetWidth = static_cast<int>(width() * 0.75);

    lastNameEdit->setMinimumWidth(widgetWidth);
    firstNameEdit->setMinimumWidth(widgetWidth);
    middleNameEdit->setMinimumWidth(widgetWidth);
    emailEdit->setMinimumWidth(widgetWidth);
    editButton->setMinimumWidth(widgetWidth / 2); // Например, кнопки чуть меньше
    saveButton->setMinimumWidth(widgetWidth / 2);
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

    User *oldUser = AuthorizedUser::instance().getUser();

    User newUser = User(firstNameEdit->text(),
                        lastNameEdit->text(),
                        middleNameEdit->text(),
                        emailEdit->text(),
                        oldUser->getRegistrationDate(),
                        oldUser->getDrivingExperience(),
                        oldUser->getRole());

    UserService::instance().updateUser(oldUser->getId(), newUser);
}

void ProfileWidget::fillFields() {
    User *user = AuthorizedUser::instance().getUser();
    if (user) {
        lastNameEdit->setText(user->getLastName());
        firstNameEdit->setText(user->getFirstName());
        middleNameEdit->setText(user->getMiddleName());
        emailEdit->setText(user->getEmail());
    } else {
        qWarning() << "Пользователь не найден. Убедитесь, что пользователь авторизован.";
    }
}
