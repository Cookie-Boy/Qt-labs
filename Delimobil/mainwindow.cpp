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
            border: 1px solid transparent; /* Прозрачная рамка, чтобы border-radius сработал */
            border-radius: 20px;
            padding: 10px;
            color: black;
            font-weight: bold;
        }
        QPushButton:hover {
            background-color: #87C4AA; /* Более темный цвет при наведении */
        }
    )";

    this->setStyleSheet(buttonStyle);

    setCentralWidget(stackedWidget);
    BaseWidget *baseWidget = new BaseWidget(stackedWidget);
    LoginWidget *loginWidget = new LoginWidget(stackedWidget, baseWidget);
    profileWidget = new ProfileWidget(stackedWidget);

    stackedWidget->addWidget(loginWidget);
    stackedWidget->addWidget(profileWidget);

//    widgetHistory.append(loginWidget);

    connect(loginWidget, &LoginWidget::userNotFound, [=]() {
            RegistrationWidget *registrationWidget = new RegistrationWidget(stackedWidget, baseWidget);
            stackedWidget->addWidget(registrationWidget);
            loginWidget->navigateTo(registrationWidget);
        });

    connect(loginWidget, &LoginWidget::userFound, [=]() {
        CarListWidget *carListWidget = new CarListWidget(stackedWidget, baseWidget);
        stackedWidget->addWidget(carListWidget);

        connect(carListWidget, &BaseWidget::profileIconClicked, this, &MainWindow::showProfileWidget);

        loginWidget->navigateTo(carListWidget);
    });

    stackedWidget->setCurrentWidget(loginWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showProfileWidget() {
    stackedWidget->setCurrentWidget(profileWidget);
}
