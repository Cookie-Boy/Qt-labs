/********************************************************************************
** Form generated from reading UI file 'registrationwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONWIDGET_H
#define UI_REGISTRATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistrationWidget
{
public:
    QTextEdit *textEdit;

    void setupUi(QWidget *RegistrationWidget)
    {
        if (RegistrationWidget->objectName().isEmpty())
            RegistrationWidget->setObjectName(QString::fromUtf8("RegistrationWidget"));
        RegistrationWidget->resize(1280, 720);
        textEdit = new QTextEdit(RegistrationWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(410, 190, 104, 85));

        retranslateUi(RegistrationWidget);

        QMetaObject::connectSlotsByName(RegistrationWidget);
    } // setupUi

    void retranslateUi(QWidget *RegistrationWidget)
    {
        RegistrationWidget->setWindowTitle(QApplication::translate("RegistrationWidget", "Form", nullptr));
        textEdit->setHtml(QApplication::translate("RegistrationWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\224\320\220\320\235\320\230\320\233\320\232\320\220</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistrationWidget: public Ui_RegistrationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONWIDGET_H
