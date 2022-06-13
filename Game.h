#ifndef GAME_H
#define GAME_H
#include <iostream>
struct Game
{
public:
    std::string name;
    std::string platform;
    int year;
    std::string genre;
    std::string publisher;
    double na;
    double eu;
    double jp;
    double other;
    double global;
};
#endif // GAME_H
