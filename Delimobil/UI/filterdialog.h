#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QPushButton>
#include "models/car.h"

class FilterDialog : public QDialog
{
    Q_OBJECT

private:
    QLineEdit *nameEdit;
    QComboBox *categoryCombo;
    QCheckBox *heatedSeatsCheck;
    QCheckBox *parkingSensorsCheck;
    QPushButton *applyButton;

public:
    explicit FilterDialog(QWidget *parent = nullptr);
    QString getNameFilter() const;
    QString getCategoryFilter() const;
    bool getHeatedSeatsFilter() const;
    bool getParkingSensorsFilter() const;
};

#endif // FILTERDIALOG_H
