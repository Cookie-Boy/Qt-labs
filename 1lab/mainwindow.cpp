#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/images/images/KVADROBER.png");
    int w = ui->square->width();
    int h = ui->square->height();
    ui->square->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

    connect(ui->a_rect, SIGNAL(textChanged(" ")), this, SLOT(change()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::change()
{
    ui->square_area->setText("Helloooo");
}
