#include "gameview.h"
#include "ui_gameview.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <QFile>
#include <QFileDialog>

GameView::GameView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameView)
{
    ui->setupUi(this);
    createList();
    countGames();
}

GameView::~GameView()
{
    delete ui;
}
//parsing initial file and creating the listview
void GameView::createList()
{
    std::ifstream inputFile("vgsales.csv");
    std::string line, token;
    std::getline(inputFile, line);
    while(std::getline(inputFile, line)) // reading line-by-line
    {
        std::istringstream ss(line);
        std::vector<std::string> lineAsVector;
        while(std::getline(ss,token,','))
            lineAsVector.push_back(token); // insert all words of this line in a vector

        Game game;
        game.name = lineAsVector[1];
        game.platform = lineAsVector[2];
        game.year = atoi(lineAsVector[3].c_str());
        game.genre = lineAsVector[4];
        game.publisher = lineAsVector[5];
        game.na = atof(lineAsVector[6].c_str());
        game.eu = atof(lineAsVector[7].c_str());
        game.jp = atof(lineAsVector[8].c_str());
        game.other = atof(lineAsVector[9].c_str());
        this->vec.push_back(game);
    }
    inputFile.close();
    QStringList list;
    for (int i = 0; i < vec.size(); i++)
    {
        list << QString::fromStdString(vec[i].name);
    }
    this -> model = new QStringListModel(this);
    this -> model -> setStringList(list);
    ui -> listView -> setModel(model);
    this->ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}
//showing details of game
void GameView::on_pushButton_clicked()
{
    int gameNum = this->ui->listView->currentIndex().row();
    Details details;
    details.getData(vec[gameNum]);
    details.setModal(true);
    details.exec();
}

//adding new game
void GameView::on_pushButton_2_clicked()
{
    AddWindow addWin;
    Game newGame;
    this->vec.push_back(newGame);

    addWin.setPointers(&vec[vec.size() - 1], model);

    addWin.setModal(true);
    addWin.exec();
    countGames();
}

//deleting
void GameView::on_pushButton_5_clicked()
{
    int gameNum = this->ui->listView->currentIndex().row();
    this->model->removeRows(gameNum, 1);

    // delete game from the vector
    std::vector<Game>::iterator it = this->vec.begin() + gameNum;
    this->vec.erase(it);
    countGames();
}

//saving file
void GameView::on_pushButton_3_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save file", "", ".csv");

    QFile f(filename);
    f.open(QIODevice::WriteOnly);
    f.write("NAME,PLATFORM,YEAR,GENRE,PUBLISHER,NA_SALES,EU_SALES,JP_SALES,OTHER_SALES\n");

    for(int i = 0; i < vec.size(); i++)
    {
        std::stringstream ss;
        ss << vec[i].name << "," << vec[i].platform << "," << vec[i].year << "," << vec[i].genre \
           << "," << vec[i].publisher << "," << vec[i].na << "," << vec[i].eu << "," << vec[i].jp << "," << vec[i].other << '\n';
        f.write(ss.str().c_str());
    }
    f.close();
}

//loading file
void GameView::on_pushButton_4_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, "Open CSV file",("*.csv"));

    std::ifstream newInputFile(file.toStdString());
    std::string line, token;
    std::getline(newInputFile, line);
    int i = vec.size() - 1;
    while(std::getline(newInputFile, line)) // reading line-by-line
    {
        std::istringstream ss(line);
        std::vector<std::string> lineAsVector;
        while(std::getline(ss,token,','))
            lineAsVector.push_back(token); // insert all words of this line in a vector

        Game game;
        game.name = lineAsVector[1];
        game.platform = lineAsVector[2];
        game.year = atoi(lineAsVector[3].c_str());
        game.genre = lineAsVector[4];
        game.publisher = lineAsVector[5];
        game.na = atof(lineAsVector[6].c_str());
        game.eu = atof(lineAsVector[7].c_str());
        game.jp = atof(lineAsVector[8].c_str());
        game.other = atof(lineAsVector[9].c_str());
        this->vec.push_back(game);
        i= i+1;

        int row = model->rowCount();  // get # of rows
        model->insertRows(row, 1);    // add new row

        QModelIndex index = model->index(row, 0, QModelIndex());

        this -> model->setData(index, QString::fromStdString(vec[i].name));
    }
    newInputFile.close();
    countGames();
}
//game counter, executed after every list change(delete, load, add)
void GameView::countGames()
{
    double totalForAll = 0;
    ui ->numofg->setText(QString::number(vec.size()));
    for(int i = 0; i < vec.size(); i++)
    {
        totalForAll += vec[i].na + vec[i].eu + vec[i].jp + vec[i].other;
    }
    ui ->totalVal->setText(QString::number(totalForAll));
}

void GameView::on_button_sort_clicked()
{
    this -> model->sort(0, Qt::AscendingOrder);
}


void GameView::on_button_sort_2_clicked()
{
    this -> model->sort(0, Qt::DescendingOrder);
}

