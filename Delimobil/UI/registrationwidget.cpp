#include "registrationwidget.h"
#include "ui_registrationwidget.h"
#include "../services/userservice.h"
#include "../models/authorizeduser.h"
#include <QPainter>
#include <QDebug>
#include "../models/authorizeduser.h"
#include "UI/loginwidget.h"

RegistrationWidget::RegistrationWidget(QStackedWidget *stackedWidget, QStack<QWidget*> *widgetHistory, QWidget *parent) :
    BaseWidget(stackedWidget, widgetHistory, parent),
    ui(new Ui::RegistrationWidget)
{
    ui->setupUi(this);
    foreach (QPushButton *button, this->findChildren<QPushButton*>()) {
        button->setCursor(Qt::PointingHandCursor);
    }

    connect(ui->regButton, &QPushButton::clicked, this, &RegistrationWidget::onRegistrationButtonClicked);
}

RegistrationWidget::~RegistrationWidget()
{
    delete ui;
}

void RegistrationWidget::updateFields() {
    QString email = AuthorizedUser::instance().getUser()->getEmail();
    ui->email->setText(email);

    ui->name->clear();
    ui->surname->clear();
    ui->surname2->clear();
    ui->drivingExp->clear();
}

void RegistrationWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // Установка основного фона
    painter.fillRect(rect(), QColor("#D3D3D3"));  // светло-серый фон

    // Серый треугольник (на заднем плане)
    painter.setBrush(QColor("#ffffff"));
    painter.setPen(Qt::NoPen);
    QPolygon greyTriangle;
    greyTriangle << QPoint(width() / 2, height())       // верхняя точка немного ниже верха
                 << QPoint(0, height() / 2)           // нижний левый угол
                 << QPoint(0, height());    // нижний правый угол
    painter.drawPolygon(greyTriangle);

    // Мятный треугольник (на переднем плане)
    painter.setBrush(QColor("#A0EACD"));
    QPolygon mintTriangle;
    mintTriangle << QPoint(width() / 2, height()) // нижняя точка по центру
                 << QPoint(width(), height() / 2) // точка справа в середине высоты
                 << QPoint(width(), height());    // нижний правый угол
    painter.drawPolygon(mintTriangle);
}

void RegistrationWidget::onRegistrationButtonClicked() {
    QString email = ui->email->text();
    QString lastName = ui->surname->text();
    QString firstName = ui->name->text();
    QString middleName = ui->surname2->text();
    short drivingExperience = ui->drivingExp->text().toShort();

    if (!UserService::instance().registerUser(email, lastName, firstName, middleName, drivingExperience)) {
        // throw something, because there is an error
        return;
    }
    emit userFound();
}
