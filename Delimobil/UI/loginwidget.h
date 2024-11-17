#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include "basewidget.h"
#include "ui_loginwidget.h"

namespace Ui {
class LoginWidget;
}

class LoginWidget : public BaseWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QStackedWidget *stackedWidget, QWidget *parent = nullptr);
    ~LoginWidget() override;

protected:
    void paintEvent(QPaintEvent *event) override; // Метод для рисования фона

private:
    Ui::LoginWidget *ui;

private slots:
    void onLoginButtonClicked();
};

#endif // LOGINWIDGET_H
