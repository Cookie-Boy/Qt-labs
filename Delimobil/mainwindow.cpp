#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "UI/loginwidget.h"
#include "UI/registrationwidget.h"
#include "UI/carlistwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    stackedWidget(new QStackedWidget(this))
{
    ui->setupUi(this);

    QString buttonStyle = R"(
        QPushButton {
            background-color: #a6f2d1; /* Основной цвет кнопки */
            border: none;
            border-radius: 20px;
            padding: 10px;
            color: black;
            font-weight: bold;
        }
        QPushButton:hover {
            background-color: #496B5C; /* Более темный цвет при наведении */
        }
    )";
    this->setStyleSheet(buttonStyle);

    setCentralWidget(stackedWidget);
    LoginWidget *loginWidget = new LoginWidget(stackedWidget);

    stackedWidget->addWidget(loginWidget);
//    stackedWidget->addWidget(registrationWidget);

    // Подключаем сигнал к слоту для обработки переходов
//    connect(loginWidget, &LoginWidget::switchToRegistration, this, [=]() {
//        switchToWidget(registrationWidget);
//    });

    // Добавляем начальный виджет
    widgetHistory.append(loginWidget);
    stackedWidget->setCurrentWidget(loginWidget);

    connect(loginWidget, &LoginWidget::userNotFound, [=]() {
            RegistrationWidget *registrationWidget = new RegistrationWidget(stackedWidget);
            stackedWidget->addWidget(registrationWidget);
            loginWidget->navigateTo(registrationWidget);
        });

    connect(loginWidget, &LoginWidget::userFound, [=]() {
        CarListWidget *carListWidget = new CarListWidget(stackedWidget);
        stackedWidget->addWidget(carListWidget);
        loginWidget->navigateTo(carListWidget);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
