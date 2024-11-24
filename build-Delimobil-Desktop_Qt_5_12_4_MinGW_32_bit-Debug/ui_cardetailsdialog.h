/********************************************************************************
** Form generated from reading UI file 'cardetailsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDETAILSDIALOG_H
#define UI_CARDETAILSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_CarDetailsDialog
{
public:

    void setupUi(QDialog *CarDetailsDialog)
    {
        if (CarDetailsDialog->objectName().isEmpty())
            CarDetailsDialog->setObjectName(QString::fromUtf8("CarDetailsDialog"));
        CarDetailsDialog->resize(400, 300);

        retranslateUi(CarDetailsDialog);

        QMetaObject::connectSlotsByName(CarDetailsDialog);
    } // setupUi

    void retranslateUi(QDialog *CarDetailsDialog)
    {
        CarDetailsDialog->setWindowTitle(QApplication::translate("CarDetailsDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CarDetailsDialog: public Ui_CarDetailsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDETAILSDIALOG_H
