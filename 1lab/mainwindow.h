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
    Figure* figures[8] = {new Square(), new Circle(), new Parallelogram(), new Rhombus, new Triangle, new Rectangle(), new Sector, new Trapezium};
    int SelectedFigureId = 0;


private slots:
    void onComboBoxChanged(int index);
    void changeValues();
    void changeArea();
    void onAuthorsClicked();
    void onClearClicked();
};

#endif // MAINWINDOW_H
