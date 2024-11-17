#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "UI/profilewidget.h"
#include "UI/basewidget.h"
#include "UI/loginwidget.h"
#include "UI/registrationwidget.h"

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

    ProfileWidget *profileWidget;
    LoginWidget *loginWidget;
    RegistrationWidget *registrationWidget;

    QList<QWidget*> widgetHistory;

    void handleUserFound(BaseWidget *sourceWidget);

private slots:
    void showProfileWidget();
};

#endif // MAINWINDOW_H
