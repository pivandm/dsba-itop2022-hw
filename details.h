#ifndef DETAILS_H
#define DETAILS_H

#include <QDialog>
#include <Game.h>
namespace Ui {
class Details;
}

class Details : public QDialog
{
    Q_OBJECT

public:
    explicit Details(QWidget *parent = nullptr);
    ~Details();
    void getData(Game game);

private:
    Ui::Details *ui; 
};

#endif // DETAILS_H
