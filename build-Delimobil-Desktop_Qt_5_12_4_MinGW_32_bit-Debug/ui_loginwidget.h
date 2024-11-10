/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit_4;
    QPushButton *loginButton;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName(QString::fromUtf8("LoginWidget"));
        LoginWidget->resize(1280, 720);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginWidget->sizePolicy().hasHeightForWidth());
        LoginWidget->setSizePolicy(sizePolicy);
        LoginWidget->setStyleSheet(QString::fromUtf8(""));
        gridLayoutWidget_2 = new QWidget(LoginWidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(0, 0, 1281, 721));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout_3->setContentsMargins(500, -1, 500, -1);
        lineEdit_4 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(30);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy1);
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ddd;\n"
"    border-radius: 15px;\n"
"    padding: 10px;\n"
"    background-color: white;\n"
"}"));
        lineEdit_4->setMaxLength(11);

        gridLayout_3->addWidget(lineEdit_4, 0, 0, 1, 1);

        loginButton = new QPushButton(gridLayoutWidget_2);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(loginButton->sizePolicy().hasHeightForWidth());
        loginButton->setSizePolicy(sizePolicy2);
        loginButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(loginButton, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);


        retranslateUi(LoginWidget);

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QApplication::translate("LoginWidget", "Form", nullptr));
        lineEdit_4->setText(QString());
        lineEdit_4->setPlaceholderText(QApplication::translate("LoginWidget", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 email", nullptr));
        loginButton->setText(QApplication::translate("LoginWidget", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
