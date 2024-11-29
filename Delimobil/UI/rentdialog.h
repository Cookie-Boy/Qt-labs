#ifndef RENTDIALOG_H
#define RENTDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "../models/car.h"
#include "../models/authorizeduser.h"

class RentDialog : public QDialog {
    Q_OBJECT

public:
    explicit RentDialog(const Car &car, QWidget *parent = nullptr);
    bool isConfirmed() const;

private slots:
    void onCancel();

private:
    bool confirmed;

    QLabel *carImageLabel;
    QLabel *carNameLabel;
    QLabel *carDetailsLabel;
    QLabel *tariffDescriptionLabel;

    QPushButton *minuteButton;
    QPushButton *hourButton;
    QPushButton *cancelButton;
};

#endif // RENTDIALOG_H
