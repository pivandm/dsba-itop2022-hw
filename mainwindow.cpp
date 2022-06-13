#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <gameview.h>
#include <about.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    GameView gmv;
    gmv.setModal(true);
    gmv.exec();
}



void MainWindow::on_pushButton_2_clicked()
{
    About abt;
    abt.setModal(true);
    abt.exec();
}

