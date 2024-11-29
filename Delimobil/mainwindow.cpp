#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "UI/loginwidget.h"
#include "UI/registrationwidget.h"
#include "UI/carlistwidget.h"
#include "models/authorizeduser.h"
#include "UI/careditordialog.h"
#include "UI/currentrentaldialog.h"

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
    manageCarsWidget = new ManageCarsWidget(stackedWidget);
    carListWidget = new CarListWidget(stackedWidget);

    stackedWidget->addWidget(loginWidget);
    stackedWidget->addWidget(profileWidget);
    stackedWidget->addWidget(registrationWidget);
    stackedWidget->addWidget(manageCarsWidget);
    stackedWidget->addWidget(carListWidget);

    stackedWidget->setCurrentWidget(loginWidget);

//    widgetHistory.append(loginWidget);

    connect(loginWidget, &LoginWidget::userNotFound, [=]() {
            loginWidget->clearFields();
            registrationWidget->updateFields();
            loginWidget->navigateTo(registrationWidget);
        });

    connect(loginWidget, &BaseWidget::userFound, [=]() {
        loginWidget->clearFields();
        handleUserFound(loginWidget);
    });

    connect(registrationWidget, &BaseWidget::userFound, [=]() {
        handleUserFound(registrationWidget);
    });

    connect(carListWidget, &BaseWidget::rentStarted, [=]() {
        stackedWidget->setCurrentWidget(loginWidget);
        carListWidget->setAllTools(carListWidget);
        carListWidget->displayCars();
        stackedWidget->setCurrentWidget(carListWidget);

        CarService::instance().startRent();
    });

    connectAllBaseWidgetSignals();
}

void MainWindow::handleUserFound(BaseWidget *sourceWidget) {
    carListWidget->setAllTools(carListWidget);
    carListWidget->displayCars();
    stackedWidget->setCurrentWidget(carListWidget);
}

void MainWindow::connectAllBaseWidgetSignals() {
    QList<BaseWidget *> baseWidgets = findChildren<BaseWidget *>();
    for (BaseWidget *widget : baseWidgets) {
        connect(widget, &BaseWidget::profileIconClicked, this, &MainWindow::showProfileWidget);

        connect(widget, &BaseWidget::exitIconClicked, [this]() {
            stackedWidget->setCurrentWidget(loginWidget);
            AuthorizedUser::instance().setUser(nullptr);
            AuthorizedUser::instance().setCar(nullptr);
        });

        connect(widget, &BaseWidget::adminIconClicked, [this]() {
            manageCarsWidget->setAllTools(static_cast<BaseWidget*>(manageCarsWidget));
            manageCarsWidget->displayCars();
            stackedWidget->setCurrentWidget(manageCarsWidget);
        });

        connect(widget, &BaseWidget::rentIconClicked, [this]() {
            CurrentRentalDialog currentRentalDialog(this);
            if (currentRentalDialog.exec() == QDialog::Accepted) {
                BaseWidget* currentWidget = qobject_cast<BaseWidget*>(stackedWidget->currentWidget());
                if (!currentWidget) {
                    qDebug() << "Current widget is not a BaseWidget!";
                    return;
                }

                currentWidget->setAllTools(currentWidget);

                if (auto* carListWidget = dynamic_cast<CarListWidget*>(currentWidget)) {
                    carListWidget->displayCars();
                } else if (auto* manageCarsWidget = dynamic_cast<ManageCarsWidget*>(currentWidget)) {
                    manageCarsWidget->displayCars();
                }

                stackedWidget->setCurrentWidget(loginWidget);
                stackedWidget->setCurrentWidget(currentWidget);
            }
        });
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showProfileWidget() {
    stackedWidget->setCurrentWidget(profileWidget);
}
