/********************************************************************************
** Form generated from reading UI file 'profilewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEWIDGET_H
#define UI_PROFILEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProfileWidget
{
public:
    QVBoxLayout *mainLayout;
    QSpacerItem *verticalSpacerTop;
    QHBoxLayout *horizontalLayoutCenter;
    QSpacerItem *horizontalSpacerLeft;
    QVBoxLayout *centerLayout;
    QFormLayout *formLayout;
    QLabel *label_lastName;
    QLineEdit *lastNameEdit;
    QLabel *label_firstName;
    QLineEdit *firstNameEdit;
    QLabel *label_middleName;
    QLineEdit *middleNameEdit;
    QLabel *label_email;
    QLineEdit *emailEdit;
    QHBoxLayout *buttonLayout;
    QPushButton *editButton;
    QPushButton *saveButton;
    QPushButton *reviewsButton;
    QPushButton *tripsButton;
    QSpacerItem *horizontalSpacerRight;
    QSpacerItem *verticalSpacerBottom;

    void setupUi(QWidget *ProfileWidget)
    {
        if (ProfileWidget->objectName().isEmpty())
            ProfileWidget->setObjectName(QString::fromUtf8("ProfileWidget"));
        ProfileWidget->resize(1280, 720);
        mainLayout = new QVBoxLayout(ProfileWidget);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        verticalSpacerTop = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        mainLayout->addItem(verticalSpacerTop);

        horizontalLayoutCenter = new QHBoxLayout();
        horizontalLayoutCenter->setObjectName(QString::fromUtf8("horizontalLayoutCenter"));
        horizontalSpacerLeft = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutCenter->addItem(horizontalSpacerLeft);

        centerLayout = new QVBoxLayout();
        centerLayout->setObjectName(QString::fromUtf8("centerLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_lastName = new QLabel(ProfileWidget);
        label_lastName->setObjectName(QString::fromUtf8("label_lastName"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_lastName);

        lastNameEdit = new QLineEdit(ProfileWidget);
        lastNameEdit->setObjectName(QString::fromUtf8("lastNameEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lastNameEdit);

        label_firstName = new QLabel(ProfileWidget);
        label_firstName->setObjectName(QString::fromUtf8("label_firstName"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_firstName);

        firstNameEdit = new QLineEdit(ProfileWidget);
        firstNameEdit->setObjectName(QString::fromUtf8("firstNameEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, firstNameEdit);

        label_middleName = new QLabel(ProfileWidget);
        label_middleName->setObjectName(QString::fromUtf8("label_middleName"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_middleName);

        middleNameEdit = new QLineEdit(ProfileWidget);
        middleNameEdit->setObjectName(QString::fromUtf8("middleNameEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, middleNameEdit);

        label_email = new QLabel(ProfileWidget);
        label_email->setObjectName(QString::fromUtf8("label_email"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_email);

        emailEdit = new QLineEdit(ProfileWidget);
        emailEdit->setObjectName(QString::fromUtf8("emailEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, emailEdit);


        centerLayout->addLayout(formLayout);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        editButton = new QPushButton(ProfileWidget);
        editButton->setObjectName(QString::fromUtf8("editButton"));

        buttonLayout->addWidget(editButton);

        saveButton = new QPushButton(ProfileWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        buttonLayout->addWidget(saveButton);


        centerLayout->addLayout(buttonLayout);

        reviewsButton = new QPushButton(ProfileWidget);
        reviewsButton->setObjectName(QString::fromUtf8("reviewsButton"));

        centerLayout->addWidget(reviewsButton);

        tripsButton = new QPushButton(ProfileWidget);
        tripsButton->setObjectName(QString::fromUtf8("tripsButton"));

        centerLayout->addWidget(tripsButton);


        horizontalLayoutCenter->addLayout(centerLayout);

        horizontalSpacerRight = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutCenter->addItem(horizontalSpacerRight);


        mainLayout->addLayout(horizontalLayoutCenter);

        verticalSpacerBottom = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        mainLayout->addItem(verticalSpacerBottom);


        retranslateUi(ProfileWidget);

        QMetaObject::connectSlotsByName(ProfileWidget);
    } // setupUi

    void retranslateUi(QWidget *ProfileWidget)
    {
        label_lastName->setText(QApplication::translate("ProfileWidget", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217:", nullptr));
        label_firstName->setText(QApplication::translate("ProfileWidget", "\320\230\320\274\321\217:", nullptr));
        label_middleName->setText(QApplication::translate("ProfileWidget", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276:", nullptr));
        label_email->setText(QApplication::translate("ProfileWidget", "Email:", nullptr));
        editButton->setText(QApplication::translate("ProfileWidget", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        saveButton->setText(QApplication::translate("ProfileWidget", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        reviewsButton->setText(QApplication::translate("ProfileWidget", "\320\234\320\276\320\270 \320\276\321\202\320\267\321\213\320\262\321\213", nullptr));
        tripsButton->setText(QApplication::translate("ProfileWidget", "\320\234\320\276\320\270 \320\277\320\276\320\265\320\267\320\264\320\272\320\270", nullptr));
        Q_UNUSED(ProfileWidget);
    } // retranslateUi

};

namespace Ui {
    class ProfileWidget: public Ui_ProfileWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEWIDGET_H
