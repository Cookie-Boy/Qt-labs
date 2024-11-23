/********************************************************************************
** Form generated from reading UI file 'careditordialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAREDITORDIALOG_H
#define UI_CAREDITORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_CarEditorDialog
{
public:

    void setupUi(QDialog *CarEditorDialog)
    {
        if (CarEditorDialog->objectName().isEmpty())
            CarEditorDialog->setObjectName(QString::fromUtf8("CarEditorDialog"));
        CarEditorDialog->resize(800, 800);

        retranslateUi(CarEditorDialog);

        QMetaObject::connectSlotsByName(CarEditorDialog);
    } // setupUi

    void retranslateUi(QDialog *CarEditorDialog)
    {
        CarEditorDialog->setWindowTitle(QApplication::translate("CarEditorDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CarEditorDialog: public Ui_CarEditorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAREDITORDIALOG_H
