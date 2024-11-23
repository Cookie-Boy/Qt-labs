#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <QStack>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include "models/car.h"

namespace Ui {
class BaseWidget;
}

class BaseWidget : public QWidget
{
    Q_OBJECT

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    QStackedWidget *stackedWidget;
    QStack<QWidget*> history;

private:
    Ui::BaseWidget *ui;

signals:
    void profileIconClicked();
    void exitIconClicked();
    void adminIconClicked();
    void rentIconClicked();

    void userNotFound();
    void userFound();

public:
    explicit BaseWidget(QStackedWidget *stackedWidget, QWidget *parent = nullptr);
    ~BaseWidget() override;
    void navigateTo(QWidget *widget);
    void goBack();
    void setAllTools(BaseWidget *widget);
};

#endif // BASEWIDGET_H
