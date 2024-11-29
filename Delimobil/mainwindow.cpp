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
    stackedWidget(new QStackedWidget()),
    widgetHistory(new QStack<QWidget*>())
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
    loginWidget = new LoginWidget(stackedWidget, widgetHistory);
    profileWidget = new ProfileWidget(stackedWidget, widgetHistory);
    registrationWidget = new RegistrationWidget(stackedWidget, widgetHistory);
    manageCarsWidget = new ManageCarsWidget(stackedWidget, widgetHistory);
    carListWidget = new CarListWidget(stackedWidget, widgetHistory);

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
            stackedWidget->setCurrentWidget(registrationWidget);
        });

    connect(loginWidget, &BaseWidget::userFound, [=]() {
        loginWidget->clearFields();
        handleUserFound();
    });

    connect(registrationWidget, &BaseWidget::userFound, [=]() {
        handleUserFound();
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

void MainWindow::handleUserFound() {
    carListWidget->setAllTools(carListWidget);
    carListWidget->displayCars();
    stackedWidget->setCurrentWidget(carListWidget);
}

void MainWindow::connectAllBaseWidgetSignals() {
    QList<BaseWidget *> baseWidgets = findChildren<BaseWidget *>();
    for (BaseWidget *widget : baseWidgets) {
        connect(widget, &BaseWidget::profileIconClicked, [this]() {
            BaseWidget* currentWidget = qobject_cast<BaseWidget*>(stackedWidget->currentWidget());
            if (currentWidget == profileWidget)
                return;
            profileWidget->fillFields();
            currentWidget->navigateTo(profileWidget);
        });

        connect(widget, &BaseWidget::exitIconClicked, [this]() {
            stackedWidget->setCurrentWidget(loginWidget);
            AuthorizedUser::instance().setUser(nullptr);
            AuthorizedUser::instance().setCar(nullptr);
        });

        connect(widget, &BaseWidget::adminIconClicked, [this]() {
            BaseWidget* currentWidget = qobject_cast<BaseWidget*>(stackedWidget->currentWidget());
            if (currentWidget == manageCarsWidget)
                return;
            manageCarsWidget->displayCars();
            currentWidget->navigateTo(manageCarsWidget);
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

        connect(widget, &BaseWidget::arrowIconClicked, [this]() {
            BaseWidget* currentWidget = qobject_cast<BaseWidget*>(stackedWidget->currentWidget());
            currentWidget->goBack();
//            currentWidget->setAllTools(currentWidget);
            currentWidget = qobject_cast<BaseWidget*>(stackedWidget->currentWidget());

            if (auto* carListWidget = dynamic_cast<CarListWidget*>(currentWidget)) {
                carListWidget->displayCars();
            } else if (auto* manageCarsWidget = dynamic_cast<ManageCarsWidget*>(currentWidget)) {
                manageCarsWidget->displayCars();
            }
        });
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
