#include "details.h"
#include "ui_details.h"

Details::Details(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Details)
{
    ui->setupUi(this);
}

Details::~Details()
{
    delete ui;
}
void Details::getData(Game game)
{
    ui -> Name -> setText(QString::fromStdString(game.name));
    ui -> Platform -> setText(QString::fromStdString(game.platform));
    ui -> Year -> setText(QString::number(game.year));
    ui -> Genre -> setText(QString::fromStdString(game.genre));
    ui -> Publisher -> setText(QString::fromStdString(game.publisher));
    ui -> NA -> setText(QString::number(game.na));
    ui -> EU -> setText(QString::number(game.eu));
    ui -> JP -> setText(QString::number(game.jp));
    ui -> Other -> setText(QString::number(game.other));

}
