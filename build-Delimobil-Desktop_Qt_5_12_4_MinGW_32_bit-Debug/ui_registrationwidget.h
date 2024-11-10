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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistrationWidget
{
public:
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QLineEdit *name;
    QLineEdit *surname;
    QLineEdit *drivingExp;
    QLineEdit *email;
    QPushButton *regButton;
    QLineEdit *surname2;

    void setupUi(QWidget *RegistrationWidget)
    {
        if (RegistrationWidget->objectName().isEmpty())
            RegistrationWidget->setObjectName(QString::fromUtf8("RegistrationWidget"));
        RegistrationWidget->resize(1280, 720);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RegistrationWidget->sizePolicy().hasHeightForWidth());
        RegistrationWidget->setSizePolicy(sizePolicy);
        RegistrationWidget->setStyleSheet(QString::fromUtf8(""));
        gridLayoutWidget_2 = new QWidget(RegistrationWidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(0, 0, 1281, 721));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout_3->setContentsMargins(500, -1, 500, -1);
        name = new QLineEdit(gridLayoutWidget_2);
        name->setObjectName(QString::fromUtf8("name"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(30);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy1);
        name->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ddd;\n"
"    border-radius: 15px;\n"
"    padding: 10px;\n"
"    background-color: white;\n"
"}"));
        name->setMaxLength(11);

        gridLayout_3->addWidget(name, 4, 0, 1, 1);

        surname = new QLineEdit(gridLayoutWidget_2);
        surname->setObjectName(QString::fromUtf8("surname"));
        sizePolicy1.setHeightForWidth(surname->sizePolicy().hasHeightForWidth());
        surname->setSizePolicy(sizePolicy1);
        surname->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ddd;\n"
"    border-radius: 15px;\n"
"    padding: 10px;\n"
"    background-color: white;\n"
"}"));
        surname->setMaxLength(11);

        gridLayout_3->addWidget(surname, 1, 0, 1, 1);

        drivingExp = new QLineEdit(gridLayoutWidget_2);
        drivingExp->setObjectName(QString::fromUtf8("drivingExp"));
        sizePolicy1.setHeightForWidth(drivingExp->sizePolicy().hasHeightForWidth());
        drivingExp->setSizePolicy(sizePolicy1);
        drivingExp->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ddd;\n"
"    border-radius: 15px;\n"
"    padding: 10px;\n"
"    background-color: white;\n"
"}"));
        drivingExp->setMaxLength(11);

        gridLayout_3->addWidget(drivingExp, 7, 0, 1, 1);

        email = new QLineEdit(gridLayoutWidget_2);
        email->setObjectName(QString::fromUtf8("email"));
        sizePolicy1.setHeightForWidth(email->sizePolicy().hasHeightForWidth());
        email->setSizePolicy(sizePolicy1);
        email->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ddd;\n"
"    border-radius: 15px;\n"
"    padding: 10px;\n"
"    background-color: white;\n"
"}"));
        email->setMaxLength(11);

        gridLayout_3->addWidget(email, 0, 0, 1, 1);

        regButton = new QPushButton(gridLayoutWidget_2);
        regButton->setObjectName(QString::fromUtf8("regButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(regButton->sizePolicy().hasHeightForWidth());
        regButton->setSizePolicy(sizePolicy2);
        regButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(regButton, 8, 0, 1, 1);

        surname2 = new QLineEdit(gridLayoutWidget_2);
        surname2->setObjectName(QString::fromUtf8("surname2"));
        sizePolicy1.setHeightForWidth(surname2->sizePolicy().hasHeightForWidth());
        surname2->setSizePolicy(sizePolicy1);
        surname2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ddd;\n"
"    border-radius: 15px;\n"
"    padding: 10px;\n"
"    background-color: white;\n"
"}"));
        surname2->setMaxLength(11);

        gridLayout_3->addWidget(surname2, 5, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);


        retranslateUi(RegistrationWidget);

        QMetaObject::connectSlotsByName(RegistrationWidget);
    } // setupUi

    void retranslateUi(QWidget *RegistrationWidget)
    {
        RegistrationWidget->setWindowTitle(QApplication::translate("RegistrationWidget", "Form", nullptr));
        name->setText(QString());
        name->setPlaceholderText(QApplication::translate("RegistrationWidget", "\320\230\320\274\321\217", nullptr));
        surname->setText(QString());
        surname->setPlaceholderText(QApplication::translate("RegistrationWidget", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        drivingExp->setText(QString());
        drivingExp->setPlaceholderText(QApplication::translate("RegistrationWidget", "\320\236\320\277\321\213\321\202 \320\262\320\276\320\266\320\264\320\265\320\275\320\270\321\217 (\320\273\320\265\321\202)", nullptr));
        email->setText(QString());
        email->setPlaceholderText(QApplication::translate("RegistrationWidget", "Email", nullptr));
        regButton->setText(QApplication::translate("RegistrationWidget", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        surname2->setText(QString());
        surname2->setPlaceholderText(QApplication::translate("RegistrationWidget", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistrationWidget: public Ui_RegistrationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONWIDGET_H
