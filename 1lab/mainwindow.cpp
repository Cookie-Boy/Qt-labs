#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <stdio.h>
#include <QPixmap>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/images/images/KVADROBER.png");
    int w = ui->square->width();
    int h = ui->square->height();
    ui->square->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
                this, &MainWindow::onComboBoxChanged);

//    connect(ui->a_rect, &QLineEdit::textChanged, this, &MainWindow::changeArea);
//    connect(ui->b_rect, &QLineEdit::textChanged, this, &MainWindow::changeArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onComboBoxChanged(int index)
{
    // Здесь можно обрабатывать изменение индекса
        QString selectedItem = ui->comboBox->itemText(index);
        cout << index << endl;
//        qDebug() << "Выбранный элемент:" << selectedItem;
}

//void MainWindow::changeArea()
//{
//    double a = ui->a_rect->text().toDouble();
//    double b = ui->b_rect->text().toDouble();
//    figures[0].setA(a);
//    ui->square_area->setText("S = " + QString::number(figures[0].getArea()));
//}
