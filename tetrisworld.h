#ifndef TETRISWORLD__H
#define TETRISWORLD__H

#include "tetrisblock.h"

const int gameHeight = 18;
const int gameWidth = 12;

class tetrisworld
{
public:
    tetrisworld();
    char currentWorld[gameHeight][gameWidth];
    bool collisionChk(char (&arr)[4][4], int xOffset, int yOffset);
    void drawWorld(char (&player)[4][4], int xOffset, int yOffset);
    void updateWorld(char (&player)[4][4], int xOffset, int yOffset);
    void checkPoints();
    void reset();
    int getScore();

private:
    void formatColors(char &letter, char &space);
    int score;
};

#endif