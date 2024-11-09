#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include "ui_loginwidget.h"

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget() override;

protected:
    void paintEvent(QPaintEvent *event) override; // Метод для рисования фона

private:
    Ui::LoginWidget *ui;
};

#endif // LOGINWIDGET_H
