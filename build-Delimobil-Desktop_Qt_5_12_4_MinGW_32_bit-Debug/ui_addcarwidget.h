/********************************************************************************
** Form generated from reading UI file 'addcarwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCARWIDGET_H
#define UI_ADDCARWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddCarWidget
{
public:

    void setupUi(QWidget *AddCarWidget)
    {
        if (AddCarWidget->objectName().isEmpty())
            AddCarWidget->setObjectName(QString::fromUtf8("AddCarWidget"));
        AddCarWidget->resize(1280, 720);

        retranslateUi(AddCarWidget);

        QMetaObject::connectSlotsByName(AddCarWidget);
    } // setupUi

    void retranslateUi(QWidget *AddCarWidget)
    {
        AddCarWidget->setWindowTitle(QApplication::translate("AddCarWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddCarWidget: public Ui_AddCarWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCARWIDGET_H
