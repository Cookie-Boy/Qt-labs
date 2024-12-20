#ifndef MANAGECARSWIDGET_H
#define MANAGECARSWIDGET_H

#include "basewidget.h"
#include "../models/car.h"
#include <QVector>
#include <QGridLayout>

namespace Ui {
class ManageCarsWidget;
}

class ManageCarsWidget : public BaseWidget
{
    Q_OBJECT

public:
    explicit ManageCarsWidget(QStackedWidget *stackedWidget, QStack<QWidget*> *widgetHistory, QWidget *parent = nullptr);
    ~ManageCarsWidget();

    void displayCars();
    void updateCarList(const QVector<Car> &cars);

private:
    Ui::ManageCarsWidget *ui;

    void createCarCard(Car &car, QGridLayout *layout, int row, int col);
    void openAddCarWidget(const Car *car = nullptr); // nullptr - для добавления новой машины
    void confirmDeleteCar(const Car &car);
    void createFilterButton();
    void openFilterDialog();

private slots:
    void onAddCarButtonClicked();
};

#endif // MANAGECARSWIDGET_H
