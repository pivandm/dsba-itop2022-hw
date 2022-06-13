#include "addwindow.h"
#include "ui_addwindow.h"

AddWindow::AddWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWindow)
{
    ui->setupUi(this);
}

AddWindow::~AddWindow()
{
    delete ui;
}

void AddWindow::setPointers(Game *game, QStringListModel *model)
{
    this-> game = game;
    this->model = model;

}

void AddWindow::on_pushButton_clicked()
{
    this -> game ->name = ui->name->text().toStdString();
    this -> game ->platform = ui->platform->text().toStdString();
    this -> game ->year = ui->year->text().toInt();
    this -> game ->genre = ui->genre->text().toStdString();
    this -> game ->publisher = ui->publisher->text().toStdString();
    this -> game ->na = ui->na->text().toDouble();
    this -> game ->eu = ui->eu->text().toDouble();
    this -> game ->jp = ui->jp->text().toDouble();
    this -> game ->other = ui->other->text().toDouble();

    // update model
    int row = model->rowCount();  // get # of rows
    model->insertRows(row, 1);    // add new row

    QModelIndex index = model->index(row, 0, QModelIndex());  // "iterator"
    model->setData(index, ui->name->text());                  // insert text at position index

    this->close();
}

