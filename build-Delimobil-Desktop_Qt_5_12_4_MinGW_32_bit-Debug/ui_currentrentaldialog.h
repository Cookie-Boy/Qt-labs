/********************************************************************************
** Form generated from reading UI file 'currentrentaldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURRENTRENTALDIALOG_H
#define UI_CURRENTRENTALDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_CurrentRentalDialog
{
public:

    void setupUi(QDialog *CurrentRentalDialog)
    {
        if (CurrentRentalDialog->objectName().isEmpty())
            CurrentRentalDialog->setObjectName(QString::fromUtf8("CurrentRentalDialog"));
        CurrentRentalDialog->resize(400, 300);

        retranslateUi(CurrentRentalDialog);

        QMetaObject::connectSlotsByName(CurrentRentalDialog);
    } // setupUi

    void retranslateUi(QDialog *CurrentRentalDialog)
    {
        CurrentRentalDialog->setWindowTitle(QApplication::translate("CurrentRentalDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CurrentRentalDialog: public Ui_CurrentRentalDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURRENTRENTALDIALOG_H
