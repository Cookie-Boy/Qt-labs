#include "rentdialog.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

RentDialog::RentDialog(QWidget *parent)
    : QDialog(parent), confirmed(false) {

    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("Вы уверены, что хотите арендовать этот автомобиль?");
    layout->addWidget(label);

    QPushButton *confirmButton = new QPushButton("Да");
    QPushButton *cancelButton = new QPushButton("Нет");

    connect(confirmButton, &QPushButton::clicked, this, &RentDialog::onConfirm);
    connect(cancelButton, &QPushButton::clicked, this, &RentDialog::onCancel);

    layout->addWidget(confirmButton);
    layout->addWidget(cancelButton);
}

void RentDialog::onConfirm() {
    confirmed = true;
    accept();
}

void RentDialog::onCancel() {
    reject();
}

bool RentDialog::isConfirmed() const {
    return confirmed;
}
