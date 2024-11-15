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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistrationWidget
{
public:
    QVBoxLayout *mainVerticalLayout;
    QSpacerItem *verticalSpacerTop;
    QHBoxLayout *horizontalCenterLayout;
    QSpacerItem *horizontalSpacerLeft;
    QVBoxLayout *centerContentLayout;
    QLineEdit *email;
    QLineEdit *name;
    QLineEdit *surname;
    QLineEdit *surname2;
    QLineEdit *drivingExp;
    QPushButton *regButton;
    QSpacerItem *horizontalSpacerRight;
    QSpacerItem *verticalSpacerBottom;

    void setupUi(QWidget *RegistrationWidget)
    {
        if (RegistrationWidget->objectName().isEmpty())
            RegistrationWidget->setObjectName(QString::fromUtf8("RegistrationWidget"));
        RegistrationWidget->resize(1280, 720);
        mainVerticalLayout = new QVBoxLayout(RegistrationWidget);
        mainVerticalLayout->setObjectName(QString::fromUtf8("mainVerticalLayout"));
        verticalSpacerTop = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        mainVerticalLayout->addItem(verticalSpacerTop);

        horizontalCenterLayout = new QHBoxLayout();
        horizontalCenterLayout->setObjectName(QString::fromUtf8("horizontalCenterLayout"));
        horizontalSpacerLeft = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalCenterLayout->addItem(horizontalSpacerLeft);

        centerContentLayout = new QVBoxLayout();
        centerContentLayout->setObjectName(QString::fromUtf8("centerContentLayout"));
        email = new QLineEdit(RegistrationWidget);
        email->setObjectName(QString::fromUtf8("email"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(30);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(email->sizePolicy().hasHeightForWidth());
        email->setSizePolicy(sizePolicy);
        email->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ddd;\n"
"    border-radius: 15px;\n"
"    padding: 10px;\n"
"    background-color: white;\n"
"}"));

        centerContentLayout->addWidget(email);

        name = new QLineEdit(RegistrationWidget);
        name->setObjectName(QString::fromUtf8("name"));
        sizePolicy.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy);
        name->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ddd;\n"
"    border-radius: 15px;\n"
"    padding: 10px;\n"
"    background-color: white;\n"
"}"));

        centerContentLayout->addWidget(name);

        surname = new QLineEdit(RegistrationWidget);
        surname->setObjectName(QString::fromUtf8("surname"));
        sizePolicy.setHeightForWidth(surname->sizePolicy().hasHeightForWidth());
        surname->setSizePolicy(sizePolicy);
        surname->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ddd;\n"
"    border-radius: 15px;\n"
"    padding: 10px;\n"
"    background-color: white;\n"
"}"));

        centerContentLayout->addWidget(surname);

        surname2 = new QLineEdit(RegistrationWidget);
        surname2->setObjectName(QString::fromUtf8("surname2"));
        sizePolicy.setHeightForWidth(surname2->sizePolicy().hasHeightForWidth());
        surname2->setSizePolicy(sizePolicy);
        surname2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ddd;\n"
"    border-radius: 15px;\n"
"    padding: 10px;\n"
"    background-color: white;\n"
"}"));

        centerContentLayout->addWidget(surname2);

        drivingExp = new QLineEdit(RegistrationWidget);
        drivingExp->setObjectName(QString::fromUtf8("drivingExp"));
        sizePolicy.setHeightForWidth(drivingExp->sizePolicy().hasHeightForWidth());
        drivingExp->setSizePolicy(sizePolicy);
        drivingExp->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ddd;\n"
"    border-radius: 15px;\n"
"    padding: 10px;\n"
"    background-color: white;\n"
"}"));

        centerContentLayout->addWidget(drivingExp);

        regButton = new QPushButton(RegistrationWidget);
        regButton->setObjectName(QString::fromUtf8("regButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(regButton->sizePolicy().hasHeightForWidth());
        regButton->setSizePolicy(sizePolicy1);

        centerContentLayout->addWidget(regButton);


        horizontalCenterLayout->addLayout(centerContentLayout);

        horizontalSpacerRight = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalCenterLayout->addItem(horizontalSpacerRight);


        mainVerticalLayout->addLayout(horizontalCenterLayout);

        verticalSpacerBottom = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        mainVerticalLayout->addItem(verticalSpacerBottom);


        retranslateUi(RegistrationWidget);

        QMetaObject::connectSlotsByName(RegistrationWidget);
    } // setupUi

    void retranslateUi(QWidget *RegistrationWidget)
    {
        RegistrationWidget->setWindowTitle(QApplication::translate("RegistrationWidget", "Registration", nullptr));
        email->setPlaceholderText(QApplication::translate("RegistrationWidget", "Email", nullptr));
        name->setPlaceholderText(QApplication::translate("RegistrationWidget", "\320\230\320\274\321\217", nullptr));
        surname->setPlaceholderText(QApplication::translate("RegistrationWidget", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        surname2->setPlaceholderText(QApplication::translate("RegistrationWidget", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        drivingExp->setPlaceholderText(QApplication::translate("RegistrationWidget", "\320\236\320\277\321\213\321\202 \320\262\320\276\320\266\320\264\320\265\320\275\320\270\321\217 (\320\273\320\265\321\202)", nullptr));
        regButton->setText(QApplication::translate("RegistrationWidget", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistrationWidget: public Ui_RegistrationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONWIDGET_H
