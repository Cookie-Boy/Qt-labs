#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <QStack>

namespace Ui {
class BaseWidget;
}

class BaseWidget : public QWidget
{
    Q_OBJECT

protected:
    QStackedWidget *stackedWidget;
    QStack<QWidget*> history;

private:
    Ui::BaseWidget *ui;

public:
    explicit BaseWidget(QStackedWidget *stackedWidget, QWidget *parent = nullptr);
    ~BaseWidget();
    void navigateTo(QWidget *widget);
    void goBack();
};

#endif // BASEWIDGET_H
