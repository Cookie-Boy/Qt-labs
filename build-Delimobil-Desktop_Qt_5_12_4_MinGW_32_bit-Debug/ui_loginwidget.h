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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    QVBoxLayout *mainVerticalLayout;
    QSpacerItem *verticalSpacerTop;
    QVBoxLayout *contentVerticalLayout;
    QHBoxLayout *horizontalCenterLayout;
    QSpacerItem *horizontalSpacerLeft;
    QVBoxLayout *centerContentLayout;
    QLineEdit *lineEdit_email;
    QPushButton *loginButton;
    QSpacerItem *horizontalSpacerRight;
    QSpacerItem *verticalSpacerBottom;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName(QString::fromUtf8("LoginWidget"));
        LoginWidget->resize(1280, 720);
        mainVerticalLayout = new QVBoxLayout(LoginWidget);
        mainVerticalLayout->setObjectName(QString::fromUtf8("mainVerticalLayout"));
        verticalSpacerTop = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        mainVerticalLayout->addItem(verticalSpacerTop);

        contentVerticalLayout = new QVBoxLayout();
        contentVerticalLayout->setObjectName(QString::fromUtf8("contentVerticalLayout"));
        horizontalCenterLayout = new QHBoxLayout();
        horizontalCenterLayout->setObjectName(QString::fromUtf8("horizontalCenterLayout"));
        horizontalSpacerLeft = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalCenterLayout->addItem(horizontalSpacerLeft);

        centerContentLayout = new QVBoxLayout();
        centerContentLayout->setObjectName(QString::fromUtf8("centerContentLayout"));
        lineEdit_email = new QLineEdit(LoginWidget);
        lineEdit_email->setObjectName(QString::fromUtf8("lineEdit_email"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_email->sizePolicy().hasHeightForWidth());
        lineEdit_email->setSizePolicy(sizePolicy);
        lineEdit_email->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ddd;\n"
"    border-radius: 15px;\n"
"    padding: 10px;\n"
"    background-color: white;\n"
"}"));

        centerContentLayout->addWidget(lineEdit_email);

        loginButton = new QPushButton(LoginWidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        sizePolicy.setHeightForWidth(loginButton->sizePolicy().hasHeightForWidth());
        loginButton->setSizePolicy(sizePolicy);
        loginButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 1px solid #ddd;\n"
"    border-radius: 15px;\n"
"    padding: 10px;\n"
"    background-color: #A0EACD;\n"
"	color: black;\n"
"}"));

        centerContentLayout->addWidget(loginButton);


        horizontalCenterLayout->addLayout(centerContentLayout);

        horizontalSpacerRight = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalCenterLayout->addItem(horizontalSpacerRight);


        contentVerticalLayout->addLayout(horizontalCenterLayout);


        mainVerticalLayout->addLayout(contentVerticalLayout);

        verticalSpacerBottom = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        mainVerticalLayout->addItem(verticalSpacerBottom);


        retranslateUi(LoginWidget);

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        lineEdit_email->setPlaceholderText(QApplication::translate("LoginWidget", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 email", nullptr));
        loginButton->setText(QApplication::translate("LoginWidget", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214", nullptr));
        Q_UNUSED(LoginWidget);
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
