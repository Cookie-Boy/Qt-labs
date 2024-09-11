#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "figures.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Figure selectedFigure;

private slots:
    void onComboBoxChanged(int index);
//    void changeArea();
};

#endif // MAINWINDOW_H
