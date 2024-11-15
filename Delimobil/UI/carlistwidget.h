#ifndef CARLISTWIDGET_H
#define CARLISTWIDGET_H

#include <QWidget>
#include "basewidget.h"

namespace Ui {
class CarListWidget;
}

class CarListWidget : public BaseWidget
{
    Q_OBJECT

public:
    explicit CarListWidget(QStackedWidget *stackedWidget, QWidget *parent = nullptr);
    ~CarListWidget() override;

protected:
    void paintEvent(QPaintEvent *event) override; // Метод для рисования фона

private:
    Ui::CarListWidget *ui;
    void displayCars();
};

#endif // CARLISTWIDGET_H
