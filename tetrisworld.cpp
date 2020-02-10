#include "tetrisworld.h"
#include <iostream>

#include <curses.h>

tetrisworld::tetrisworld() : score(0)
{
    // Create game space
    reset();
}

void tetrisworld::reset()
{
    this->score = 0;
    for (int i = 0; i < gameHeight; i++)
    {
        for (int k = 0; k < gameWidth; k++)
        {
            if (i == 0 || i == gameHeight - 1 || k == 0 || k == gameWidth - 1)
            {
                currentWorld[i][k] = '#';
            }
            else
            {
                currentWorld[i][k] = ' ';
            }
        }
    }
}

void tetrisworld::updateWorld(char (&player)[4][4], int xOffset, int yOffset)
{
    for (int i = 0; i < 4; i++)
    {
        for (int k = 0; k < 4; k++)
        {
            if (player[i][k] != ' ')
            {
                currentWorld[i + yOffset][k + xOffset] = player[i][k];
            }
        }
    }
}

void tetrisworld::checkPoints()
{
    for (int i = 1; i < gameHeight - 1; i++)
    {
        bool fullrow = true;
        for (int k = 1; k < gameWidth - 1; k++)
        {
            if (currentWorld[i][k] == ' ')
            {
                fullrow = false;
                break;
            }
        }

        if (fullrow)
        {
            score = score + 1;
            for (int j = i; j > 1; j--)
            {
                for (int k = 1; k < gameWidth - 1; k++)
                {
                    currentWorld[j][k] = currentWorld[j - 1][k];
                }
            }
        }
    }
}

void tetrisworld::drawWorld(char (&player)[4][4], int xOffset, int yOffset)
{
    for (int i = 0; i < gameHeight; i++)
    {
        for (int k = 0; k < gameWidth; k++)
        {
            if (i >= yOffset && i < yOffset + 4 && k >= xOffset && k < xOffset + 4)
            {
                formatColors(player[i - yOffset][k - xOffset], currentWorld[i][k]);
            }
            else
            {
                formatColors(currentWorld[i][k], currentWorld[i][k]);
            }
        }
        move(i + 1, 0);
    }
    refresh();
}

int tetrisworld::getScore()
{
    return score;
}

void tetrisworld::formatColors(char &text, char &space)
{
    if (text == ' ')
    {
        if (space == ' ')
            printw("%c", space);
        else
            formatColors(space, space);
    }
    else if (text == '#')
    {
        attron(COLOR_PAIR(1));
        printw("%c", text);
        attroff(COLOR_PAIR(1));
    }
    else if (text == 'X')
    {
        attron(COLOR_PAIR(2));
        printw("%c", text);
        attroff(COLOR_PAIR(2));
    }
    else if (text == 'B')
    {
        attron(COLOR_PAIR(3));
        printw("%c", text);
        attroff(COLOR_PAIR(3));
    }
    else if (text == 'D')
    {
        attron(COLOR_PAIR(4));
        printw("%c", text);
        attroff(COLOR_PAIR(4));
    }
    else if (text == 'M')
    {
        attron(COLOR_PAIR(5));
        printw("%c", text);
        attroff(COLOR_PAIR(5));
    }
    else if (text == 'N')
    {
        attron(COLOR_PAIR(6));
        printw("%c", text);
        attroff(COLOR_PAIR(6));
    }
    else if (text == 'U')
    {
        attron(COLOR_PAIR(7));
        printw("%c", text);
        attroff(COLOR_PAIR(7));
    }
    else if (text == 'E')
    {
        attron(COLOR_PAIR(8));
        printw("%c", text);
        attroff(COLOR_PAIR(8));
    }
}

bool tetrisworld::collisionChk(char (&arr)[4][4], int xOffset, int yOffset)
{
    for (int i = 0; i < 4; i++)
    {
        for (int k = 0; k < 4; k++)
        {
            if (arr[i][k] != ' ' && currentWorld[i + yOffset][k + xOffset] != ' ')
            {
                return true;
            }
        }
    }
    return false;
}