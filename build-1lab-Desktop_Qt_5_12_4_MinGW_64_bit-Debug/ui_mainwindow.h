/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QWidget *centralWidget;
    QLineEdit *a_rect;
    QLabel *square_area;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *square;
    QComboBox *comboBox;
    QLineEdit *b_rect;
    QLineEdit *c_rect;
    QLabel *label_5;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1304, 633);
        MainWindow->setStyleSheet(QString::fromUtf8("none"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QString::fromUtf8("action_5"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        a_rect = new QLineEdit(centralWidget);
        a_rect->setObjectName(QString::fromUtf8("a_rect"));
        a_rect->setGeometry(QRect(370, 70, 113, 24));
        a_rect->setStyleSheet(QString::fromUtf8("0"));
        a_rect->setMaxLength(33);
        square_area = new QLabel(centralWidget);
        square_area->setObjectName(QString::fromUtf8("square_area"));
        square_area->setGeometry(QRect(540, 360, 261, 61));
        QFont font;
        font.setPointSize(20);
        square_area->setFont(font);
        square_area->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(370, 50, 55, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(510, 50, 55, 16));
        square = new QLabel(centralWidget);
        square->setObjectName(QString::fromUtf8("square"));
        square->setGeometry(QRect(370, 110, 271, 241));
        square->setPixmap(QPixmap(QString::fromUtf8("images/KVADROBER.png")));
        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(370, 380, 151, 41));
        b_rect = new QLineEdit(centralWidget);
        b_rect->setObjectName(QString::fromUtf8("b_rect"));
        b_rect->setGeometry(QRect(510, 70, 113, 24));
        b_rect->setStyleSheet(QString::fromUtf8("0"));
        b_rect->setMaxLength(32);
        c_rect = new QLineEdit(centralWidget);
        c_rect->setObjectName(QString::fromUtf8("c_rect"));
        c_rect->setGeometry(QRect(640, 70, 113, 24));
        c_rect->setStyleSheet(QString::fromUtf8("0"));
        c_rect->setInputMethodHints(Qt::ImhNone);
        c_rect->setMaxLength(32767);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(640, 50, 55, 16));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1304, 25));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action_3);
        menu->addAction(action_4);
        menu->addAction(action_5);

        retranslateUi(MainWindow);
        QObject::connect(action_5, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action_3->setText(QApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200\321\213", nullptr));
        action_4->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        action_5->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        a_rect->setInputMask(QString());
        a_rect->setText(QString());
        square_area->setText(QApplication::translate("MainWindow", "S = 0", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "a", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "b", nullptr));
        square->setText(QString());
        comboBox->setItemText(0, QApplication::translate("MainWindow", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "\320\232\321\200\321\203\320\263", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\273\320\273\320\265\320\273\320\276\320\263\321\200\320\260\320\274\320\274", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "\320\240\320\276\320\274\320\261", nullptr));
        comboBox->setItemText(4, QApplication::translate("MainWindow", "\320\242\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        comboBox->setItemText(5, QApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        comboBox->setItemText(6, QApplication::translate("MainWindow", "\320\241\320\265\320\272\321\202\320\276\321\200", nullptr));
        comboBox->setItemText(7, QApplication::translate("MainWindow", "\320\242\321\200\320\260\320\277\320\265\321\206\320\270\321\217", nullptr));

        b_rect->setInputMask(QString());
        c_rect->setInputMask(QString());
        c_rect->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "\321\201", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
