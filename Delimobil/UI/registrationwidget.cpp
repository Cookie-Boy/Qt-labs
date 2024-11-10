#include "registrationwidget.h"
#include "ui_registrationwidget.h"

RegistrationWidget::RegistrationWidget(QStackedWidget *stackedWidget, QWidget *parent) :
    BaseWidget(stackedWidget, parent),
    ui(new Ui::RegistrationWidget)
{
    ui->setupUi(this);
}

RegistrationWidget::~RegistrationWidget()
{
    delete ui;
}
