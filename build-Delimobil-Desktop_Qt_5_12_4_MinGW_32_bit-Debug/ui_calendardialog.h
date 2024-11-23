/********************************************************************************
** Form generated from reading UI file 'calendardialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDARDIALOG_H
#define UI_CALENDARDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CalendarDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *instructionLabel;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *startLayout;
    QLabel *startLabel;
    QCalendarWidget *startCalendar;
    QVBoxLayout *endLayout;
    QLabel *endLabel;
    QCalendarWidget *endCalendar;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CalendarDialog)
    {
        if (CalendarDialog->objectName().isEmpty())
            CalendarDialog->setObjectName(QString::fromUtf8("CalendarDialog"));
        verticalLayout = new QVBoxLayout(CalendarDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        instructionLabel = new QLabel(CalendarDialog);
        instructionLabel->setObjectName(QString::fromUtf8("instructionLabel"));

        verticalLayout->addWidget(instructionLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        startLayout = new QVBoxLayout();
        startLayout->setObjectName(QString::fromUtf8("startLayout"));
        startLabel = new QLabel(CalendarDialog);
        startLabel->setObjectName(QString::fromUtf8("startLabel"));

        startLayout->addWidget(startLabel);

        startCalendar = new QCalendarWidget(CalendarDialog);
        startCalendar->setObjectName(QString::fromUtf8("startCalendar"));

        startLayout->addWidget(startCalendar);


        horizontalLayout->addLayout(startLayout);

        endLayout = new QVBoxLayout();
        endLayout->setObjectName(QString::fromUtf8("endLayout"));
        endLabel = new QLabel(CalendarDialog);
        endLabel->setObjectName(QString::fromUtf8("endLabel"));

        endLayout->addWidget(endLabel);

        endCalendar = new QCalendarWidget(CalendarDialog);
        endCalendar->setObjectName(QString::fromUtf8("endCalendar"));

        endLayout->addWidget(endCalendar);


        horizontalLayout->addLayout(endLayout);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(CalendarDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CalendarDialog);

        QMetaObject::connectSlotsByName(CalendarDialog);
    } // setupUi

    void retranslateUi(QDialog *CalendarDialog)
    {
        CalendarDialog->setWindowTitle(QApplication::translate("CalendarDialog", "\320\222\321\213\320\261\320\276\321\200 \320\277\320\265\321\200\320\270\320\276\320\264\320\260 \320\261\320\273\320\276\320\272\320\270\321\200\320\276\320\262\320\272\320\270", nullptr));
        instructionLabel->setText(QApplication::translate("CalendarDialog", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\264\320\260\321\202\321\203 \320\275\320\260\321\207\320\260\320\273\320\260 \320\270 \320\272\320\276\320\275\321\206\320\260 \320\261\320\273\320\276\320\272\320\270\321\200\320\276\320\262\320\272\320\270:", nullptr));
        startLabel->setText(QApplication::translate("CalendarDialog", "\320\224\320\260\321\202\320\260 \320\275\320\260\321\207\320\260\320\273\320\260:", nullptr));
        endLabel->setText(QApplication::translate("CalendarDialog", "\320\224\320\260\321\202\320\260 \320\272\320\276\320\275\321\206\320\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalendarDialog: public Ui_CalendarDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDARDIALOG_H
