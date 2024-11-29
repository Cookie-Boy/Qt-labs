#ifndef REGISTRATIONWIDGET_H
#define REGISTRATIONWIDGET_H

#include <QWidget>
#include "basewidget.h"

namespace Ui {
class RegistrationWidget;
}

class RegistrationWidget : public BaseWidget
{
    Q_OBJECT

public:
    explicit RegistrationWidget(QStackedWidget *stackedWidget, QStack<QWidget*> *widgetHistory, QWidget *parent = nullptr);
    ~RegistrationWidget() override;

    void updateFields();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::RegistrationWidget *ui;

private slots:
    void onRegistrationButtonClicked();
};

#endif // REGISTRATIONWIDGET_H
