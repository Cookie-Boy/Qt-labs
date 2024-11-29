#ifndef CURRENTRENTALDIALOG_H
#define CURRENTRENTALDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTimer>
#include <QInputDialog>
#include <QMessageBox>
#include "../models/authorizeduser.h"
#include "../services/carservice.h"

namespace Ui {
class CurrentRentalDialog;
}

class CurrentRentalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CurrentRentalDialog(QWidget *parent = nullptr);
    ~CurrentRentalDialog() override;

private slots:
    void onEndRentalClicked();
    void onPauseRentalClicked();
    void updateRentalPrice(double newPrice);

private:
    void setupUI();
    bool finishHourlyRental();

    QLabel *carImageLabel;
    QLabel *carNameLabel;
    QLabel *rentalCostLabel;
    QPushButton *endRentalButton;
    QPushButton *pauseRentalButton;
    QVBoxLayout *mainLayout;

    Ui::CurrentRentalDialog *ui;
};

#endif // CURRENTRENTALDIALOG_H
