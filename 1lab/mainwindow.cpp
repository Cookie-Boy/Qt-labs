#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <stdio.h>
#include <QPixmap>
#include <QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/images/images/0.png");
    int w = ui->square->width();
    int h = ui->square->height();
    ui->square->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

    ui->b_rect->setVisible(0);
    ui->c_rect->setVisible(0);
    ui->label_4->setVisible(0);
    ui->label_5->setVisible(0);
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
                this, &MainWindow::onComboBoxChanged);
    connect(ui->a_rect, &QLineEdit::textEdited, this, &MainWindow::changeValues);
    connect(ui->b_rect, &QLineEdit::textEdited, this, &MainWindow::changeValues);
    connect(ui->c_rect, &QLineEdit::textEdited, this, &MainWindow::changeValues);

    connect(ui->menu->actions().first(), &QAction::triggered, this, &MainWindow::onAuthorsClicked);
    connect(ui->menu->actions()[1], &QAction::triggered, this, &MainWindow::onClearClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onComboBoxChanged(int index)
{
    // Здесь можно обрабатывать изменение индекса
//        qDebug() << "Выбранный элемент:" << selectedItem

        QString PictureName = ":/images/images/" + QString::number(index) + ".png";
        QPixmap pix(PictureName);
        int w = ui->square->width();
        int h = ui->square->height();
        ui->square->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
        SelectedFigureId = index;
        if(index < 2)
        {
            ui->b_rect->setVisible(0);
            ui->c_rect->setVisible(0);
            ui->label_4->setVisible(0);
            ui->c_rect->setVisible(0);
            if(index == 0)
                ui->label_3->setText("a");
            else
                ui->label_3->setText("r");
        }
        else
        {
            ui->b_rect->setVisible(1);
            ui->label_4->setVisible(1);
            ui->c_rect->setVisible(0);
            ui->label_5->setVisible(0);

            if(index < 5)
            {
                ui->label_3->setText("a");
                ui->label_4->setText("h");
            }
            else if(index == 5)
            {
                ui->label_4->setText("b");
            }
            else if(index == 6)
            {
                ui->label_3->setText("r");
                ui->label_4->setText("α");
            }
            else
            {
                ui->c_rect->setVisible(1);
                ui->label_5->setVisible(1);

                ui->label_3->setText("a");
                ui->label_4->setText("b");
                ui->label_5->setText("h");
            }
        }
        ui->a_rect->clear();
        ui->b_rect->clear();
        ui->c_rect->clear();
        changeArea();
}

void MainWindow::changeValues()
{
    figures[SelectedFigureId]->setA(ui->a_rect->text().toDouble());
    figures[SelectedFigureId]->setB(ui->b_rect->text().toDouble());
    figures[SelectedFigureId]->setC(ui->c_rect->text().toDouble());
    changeArea();
}

void MainWindow::changeArea()
{
    ui->square_area->setText("S = " + QString::number(figures[SelectedFigureId]->getArea()));
    ui->a_rect->setText(QString::number(figures[SelectedFigureId]->getA()));
    ui->b_rect->setText(QString::number(figures[SelectedFigureId]->getB()));
    ui->c_rect->setText(QString::number(figures[SelectedFigureId]->getC()));
}

void MainWindow::onAuthorsClicked()
{
    QMessageBox::about(this, "Авторы", "Медведенко Виталий и Ефимов Евгений");
}

void MainWindow::onClearClicked()
{
    for (int i = 0; i < 8; i++)
    {
        figures[i]->setA(0);
        figures[i]->setB(0);
        figures[i]->setC(0);
        ui->a_rect->setText("0");
        ui->b_rect->setText("0");
        ui->c_rect->setText("0");
        ui->square_area->setText("S = 0");
        ui->comboBox->setCurrentIndex(0);
    }
}
