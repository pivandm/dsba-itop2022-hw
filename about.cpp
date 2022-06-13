#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
}

About::~About()
{
    delete ui;
}

void About::on_pushButton_clicked()
{
    this->close();
}

void About::paintEvent(QPaintEvent *e)
{
     QPainter painter(this);
     QString lab = "G";

     QPen bluePen(Qt::darkCyan);
     bluePen.setWidth(4);

     painter.setPen(bluePen);

     QPoint a;
     a.setX(150);
     a.setY(140);

     QPoint b;
     b.setX(200);
     b.setY(160);

     QPoint c;
     c.setX(250);
     c.setY(140);

     painter.drawLine(a,b);
     painter.drawLine(b,c);

     QImage image;
     image.load("controller.png");
     QImage scaledImage = image.scaled(100, 100, Qt::KeepAspectRatio);
     painter.drawImage(150, 50, scaledImage);
}
