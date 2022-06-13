#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

namespace Ui {
class About;
}

class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = nullptr);
    ~About();
    void paintEvent(QPaintEvent *e);

private slots:
    void on_pushButton_clicked();

private:
    Ui::About *ui;
};

#endif // ABOUT_H
