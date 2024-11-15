#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "UI/profilewidget.h"

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
    QList<QWidget*> widgetHistory;

private slots:
    void showProfileWidget();
};

#endif // MAINWINDOW_H
