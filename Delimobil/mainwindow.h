#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

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
    QList<QWidget*> widgetHistory;
};

#endif // MAINWINDOW_H
