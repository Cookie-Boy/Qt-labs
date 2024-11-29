#ifndef PROFILEWIDGET_H
#define PROFILEWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include "basewidget.h"
#include "../models/user.h"
#include "../models/authorizeduser.h"
#include "../services/userservice.h"

class ProfileWidget : public BaseWidget
{
    Q_OBJECT

public:
    explicit ProfileWidget(QStackedWidget *stackedWidget, QStack<QWidget*> *widgetHistory, QWidget *parent = nullptr);
    void fillFields();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void onEditButtonClicked();
    void onSaveButtonClicked();

private:
    QLineEdit *lastNameEdit;
    QLineEdit *firstNameEdit;
    QLineEdit *middleNameEdit;
    QLineEdit *emailEdit;
    QPushButton *editButton;
    QPushButton *saveButton;
//    QPushButton *tripsButton;
//    QPushButton *reviewsButton;
};

#endif // PROFILEWIDGET_H
