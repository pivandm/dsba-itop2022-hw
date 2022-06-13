#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QDialog>
#include <Game.h>
#include <vector>
#include <QStringListModel>
#include "addwindow.h"
#include "details.h"

namespace Ui {
class GameView;
}

class GameView : public QDialog
{
    Q_OBJECT

public:
    explicit GameView(QWidget *parent = nullptr);
    ~GameView();
    void createList();
    void countGames();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_button_sort_clicked();

    void on_button_sort_2_clicked();

private:
    Ui::GameView *ui;
    std::vector<Game> vec;
    QStringListModel* model;
};

#endif // GAMEVIEW_H
