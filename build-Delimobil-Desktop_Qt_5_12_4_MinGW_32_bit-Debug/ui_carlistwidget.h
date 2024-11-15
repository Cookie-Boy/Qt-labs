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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CarListWidget
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *layout;

    void setupUi(QWidget *CarListWidget)
    {
        if (CarListWidget->objectName().isEmpty())
            CarListWidget->setObjectName(QString::fromUtf8("CarListWidget"));
        CarListWidget->resize(1280, 720);
        CarListWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background: transparent;\n"
"}"));
        verticalLayout = new QVBoxLayout(CarListWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(CarListWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"	border: none;\n"
"	margin-top: 60px;\n"
"}"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1138, 578));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background: transparent;\n"
"}"));
        layout = new QGridLayout(scrollAreaWidgetContents);
        layout->setObjectName(QString::fromUtf8("layout"));
        layout->setHorizontalSpacing(18);
        layout->setVerticalSpacing(20);
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(CarListWidget);

        QMetaObject::connectSlotsByName(CarListWidget);
    } // setupUi

    void retranslateUi(QWidget *CarListWidget)
    {
        CarListWidget->setWindowTitle(QApplication::translate("CarListWidget", "Car List", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CarListWidget: public Ui_CarListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARLISTWIDGET_H
