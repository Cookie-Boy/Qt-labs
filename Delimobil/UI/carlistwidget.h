#ifndef CARLISTWIDGET_H
#define CARLISTWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include "basewidget.h"
#include "models/car.h"

namespace Ui {
class CarListWidget;
}

class CarListWidget : public BaseWidget
{
    Q_OBJECT

public:
    explicit CarListWidget(QStackedWidget *stackedWidget, QWidget *parent = nullptr);
    ~CarListWidget() override;

private:
    Ui::CarListWidget *ui;
    void createFilterButton();
    void createCarCard(const Car &car, QGridLayout *layout, int row, int col);
    void displayCars();
    void openFilterDialog();
    void updateCarList(const QVector<Car> &cars);
};

#endif // CARLISTWIDGET_H
