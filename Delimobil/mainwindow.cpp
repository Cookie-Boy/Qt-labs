#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "UI/loginwidget.h"
#include "UI/registrationwidget.h"
#include "UI/carlistwidget.h"
#include "models/authorizeduser.h"

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
//    BaseWidget *baseWidget = new BaseWidget(stackedWidget);
    loginWidget = new LoginWidget(stackedWidget);
    profileWidget = new ProfileWidget(stackedWidget);
    registrationWidget = new RegistrationWidget(stackedWidget);

    stackedWidget->addWidget(loginWidget);
    stackedWidget->addWidget(profileWidget);
    stackedWidget->addWidget(registrationWidget);

    stackedWidget->setCurrentWidget(loginWidget);

//    widgetHistory.append(loginWidget);

    connect(loginWidget, &LoginWidget::userNotFound, [=]() {
            registrationWidget->fillFields();
            loginWidget->navigateTo(registrationWidget);
        });

    connect(loginWidget, &BaseWidget::userFound, [=]() {
        handleUserFound(loginWidget);
    });

    connect(registrationWidget, &BaseWidget::userFound, [=]() {
        handleUserFound(registrationWidget);
    });
}

void MainWindow::handleUserFound(BaseWidget *sourceWidget) {
    CarListWidget *carListWidget = new CarListWidget(stackedWidget);
    stackedWidget->addWidget(carListWidget);

    connect(carListWidget, &BaseWidget::profileIconClicked, this, &MainWindow::showProfileWidget);
    connect(carListWidget, &BaseWidget::exitIconClicked, [=]() {
        stackedWidget->setCurrentWidget(loginWidget);
        AuthorizedUser::instance().setUser(nullptr);
    });
    connect(carListWidget, &BaseWidget::adminIconClicked, [=]() {
        stackedWidget->setCurrentWidget(profileWidget);
    });

    sourceWidget->navigateTo(carListWidget);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showProfileWidget() {
    stackedWidget->setCurrentWidget(profileWidget);
}
