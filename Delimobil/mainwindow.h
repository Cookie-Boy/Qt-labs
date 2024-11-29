#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "UI/profilewidget.h"
#include "UI/basewidget.h"
#include "UI/loginwidget.h"
#include "UI/registrationwidget.h"
#include "UI/managecarswidget.h"
#include "UI/carlistwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void switchToWidget(QWidget* widget);

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;
    QStack<QWidget*> *widgetHistory;

    ProfileWidget *profileWidget;
    LoginWidget *loginWidget;
    RegistrationWidget *registrationWidget;
    ManageCarsWidget *manageCarsWidget;
    CarListWidget *carListWidget;

    void handleUserFound();
    void connectAllBaseWidgetSignals();
};

#endif // MAINWINDOW_H
