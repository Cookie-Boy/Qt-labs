/********************************************************************************
** Form generated from reading UI file 'addcardialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCARDIALOG_H
#define UI_ADDCARDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_AddCarDialog
{
public:

    void setupUi(QDialog *AddCarDialog)
    {
        if (AddCarDialog->objectName().isEmpty())
            AddCarDialog->setObjectName(QString::fromUtf8("AddCarDialog"));
        AddCarDialog->resize(600, 400);

        retranslateUi(AddCarDialog);

        QMetaObject::connectSlotsByName(AddCarDialog);
    } // setupUi

    void retranslateUi(QDialog *AddCarDialog)
    {
        AddCarDialog->setWindowTitle(QApplication::translate("AddCarDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\274\320\260\321\210\320\270\320\275\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddCarDialog: public Ui_AddCarDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCARDIALOG_H
