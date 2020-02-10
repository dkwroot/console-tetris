#include "tetrisblock.h"
#include "tetrisworld.h"

#include <iostream>
#include <string>
#include <curses.h>
#include <thread>
#include <chrono>

int main()
{
    tetrisworld gameworld = tetrisworld();
    tetrisblocks player = tetrisblocks();

    std::srand(time(NULL));
    initscr();
    noecho();
    start_color();

    //Color Pairs
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLUE);
    init_pair(3, COLOR_RED, COLOR_RED);
    init_pair(4, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(5, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(6, COLOR_CYAN, COLOR_CYAN);
    init_pair(7, COLOR_GREEN, COLOR_GREEN);
    init_pair(8, COLOR_WHITE, COLOR_WHITE);

    char ch;
    bool gameOn = true;
    bool gameOver = false;
    cbreak();
    nodelay(stdscr, TRUE);
    while (gameOn)
    {
        while (gameOver == true)
        {
            move(2, 2);
            printw("GAME OVER. Continue? y/n \n TOTAL SCORE: %d", gameworld.getScore());
            refresh();
            ch = getch();
            if (ch == 'y')
            {
                gameOver = false;
                gameworld.reset();
                nodelay(stdscr, TRUE);
            }
            else if (ch == 'n')
            {
                gameOver = false;
                gameOn = false;
            }
        }
        int sideMove = 0;
        // User Controls
        ch = getch();
        if (ch == 'k')
        {
            gameOn = false;
        }
        else if (ch == 's')
        {
            player.rotate();
            // Check if rotation causes rotation and offset player accordingly
            if (gameworld.collisionChk(player.m_activeBlock, player.getXpos(), player.getYpos() + 1))
            {
                if (player.getXpos() < 3)
                    player.setPosition(player.getXpos() + 1, player.getYpos());
                else
                    player.setPosition(player.getXpos() - 1, player.getYpos());
            }
        }
        else if (ch == 'a')
        {
            sideMove = -1;
        }
        else if (ch == 'd')
        {
            sideMove = 1;
        }

        if (!gameworld.collisionChk(player.m_activeBlock, player.getXpos() + sideMove, player.getYpos() + 1))
        {
            // Check if movement collides with anything while including side movement. If clear, then include side movement.
            player.setPosition(player.getXpos() + sideMove, player.getYpos() + 1);
        }
        else if (!gameworld.collisionChk(player.m_activeBlock, player.getXpos(), player.getYpos() + 1))
        {
            // Check if area below player is clear. If so, then move down.
            player.setPosition(player.getXpos(), player.getYpos() + 1);
        }
        else
        {
            // Collision occured
            gameworld.updateWorld(player.m_activeBlock, player.getXpos(), player.getYpos());
            player.reset();
            if (gameworld.collisionChk(player.m_activeBlock, player.getXpos(), player.getYpos()))
            {
                gameOver = true;
            }
            else
            {
                gameworld.checkPoints();
            }
        }

        gameworld.drawWorld(player.m_activeBlock, player.getXpos(), player.getYpos());

        move(22, 1);
        printw("SCORE: %d", gameworld.getScore());
        move(0, 0);
        refresh();

        flushinp();
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        clear();
        refresh();
    }

    endwin();
    return 0;
}