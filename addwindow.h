#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QDialog>
#include <QStringListModel>
#include <Game.h>
namespace Ui {
class AddWindow;
}

class AddWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddWindow(QWidget *parent = nullptr);
    ~AddWindow();
    void setPointers(Game *game, QStringListModel *model);

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddWindow *ui;
     Game *game;
     QStringListModel *model;
};

#endif // ADDWINDOW_H#include <Game.h>
