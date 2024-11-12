/********************************************************************************
** Form generated from reading UI file 'carlistwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARLISTWIDGET_H
#define UI_CARLISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CarListWidget
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *layout;

    void setupUi(QWidget *CarListWidget)
    {
        if (CarListWidget->objectName().isEmpty())
            CarListWidget->setObjectName(QString::fromUtf8("CarListWidget"));
        CarListWidget->resize(1280, 720);
        CarListWidget->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font-size: 18px;\n"
"}"));
        scrollArea = new QScrollArea(CarListWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 1280, 720));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"	margin-top: 70 px;\n"
"	background: transparent;\n"
"	border: none;\n"
"}"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1140, 580));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background: transparent;\n"
"}"));
        layout = new QGridLayout(scrollAreaWidgetContents);
        layout->setObjectName(QString::fromUtf8("layout"));
        layout->setHorizontalSpacing(25);
        layout->setVerticalSpacing(40);
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(CarListWidget);

        QMetaObject::connectSlotsByName(CarListWidget);
    } // setupUi

    void retranslateUi(QWidget *CarListWidget)
    {
        CarListWidget->setWindowTitle(QApplication::translate("CarListWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CarListWidget: public Ui_CarListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARLISTWIDGET_H
