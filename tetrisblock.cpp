#include "tetrisblock.h"

#include <cstdlib>
#include <time.h>

tetrisblocks::tetrisblocks() : m_xPos(4), m_yPos(1)
{
    // std::srand(time(NULL));
    randomize();
}

tetrisblocks::~tetrisblocks() {}

void tetrisblocks::randomize()
{
    const int blocktype = std::rand() % 7;
    for (int i = 0; i < 4; i++)
    {
        for (int k = 0; k < 4; k++)
        {
            switch (blocktype)
            {
            case 0:
                m_activeBlock[i][k] = tetrisblocks::blockLine[i][k];
                break;
            case 1:
                m_activeBlock[i][k] = tetrisblocks::blockSquare[i][k];
                break;
            case 2:
                m_activeBlock[i][k] = tetrisblocks::blockT[i][k];
                break;
            case 3:
                m_activeBlock[i][k] = tetrisblocks::blockLL[i][k];
                break;
            case 4:
                m_activeBlock[i][k] = tetrisblocks::blockLR[i][k];
                break;
            case 5:
                m_activeBlock[i][k] = tetrisblocks::blockZagL[i][k];
                break;
            case 6:
                m_activeBlock[i][k] = tetrisblocks::blockZagR[i][k];
                break;
            default:
                break;
            }
        }
    }
}

void tetrisblocks::rotate()
{
    // Inplace Rotation of the current player matrix
    for (int x = 0; x < 2; x++)
    {
        for (int y = x; y < 3 - x; y++)
        {
            int temp = m_activeBlock[x][y];
            m_activeBlock[x][y] = m_activeBlock[y][3 - x];
            m_activeBlock[y][3 - x] = m_activeBlock[3 - x][3 - y];
            m_activeBlock[3 - x][3 - y] = m_activeBlock[3 - y][x];
            m_activeBlock[3 - y][x] = temp;
        }
    }
}

int tetrisblocks::getXpos()
{
    return m_xPos;
}

int tetrisblocks::getYpos()
{
    return m_yPos;
}

void tetrisblocks::setPosition(int x, int y)
{
    m_xPos = x;
    m_yPos = y;
}

void tetrisblocks::reset()
{
    m_xPos = 4;
    m_yPos = 1;
    randomize();
}

char tetrisblocks::blockLine[4][4] = {
    {' ', ' ', 'X', ' '},
    {' ', ' ', 'X', ' '},
    {' ', ' ', 'X', ' '},
    {' ', ' ', 'X', ' '}};

char tetrisblocks::blockSquare[4][4] = {
    {' ', ' ', ' ', ' '},
    {' ', 'B', 'B', ' '},
    {' ', 'B', 'B', ' '},
    {' ', ' ', ' ', ' '}};

char tetrisblocks::blockT[4][4] = {
    {' ', ' ', ' ', ' '},
    {' ', ' ', 'D', ' '},
    {' ', 'D', 'D', ' '},
    {' ', ' ', 'D', ' '}};

char tetrisblocks::blockLL[4][4] = {
    {' ', ' ', ' ', ' '},
    {' ', 'M', 'M', ' '},
    {' ', ' ', 'M', ' '},
    {' ', ' ', 'M', ' '}};

char tetrisblocks::blockLR[4][4] = {
    {' ', ' ', ' ', ' '},
    {' ', 'N', 'N', ' '},
    {' ', 'N', ' ', ' '},
    {' ', 'N', ' ', ' '}};

char tetrisblocks::blockZagL[4][4] = {
    {' ', ' ', ' ', ' '},
    {' ', 'U', ' ', ' '},
    {' ', 'U', 'U', ' '},
    {' ', ' ', 'U', ' '}};

char tetrisblocks::blockZagR[4][4] = {
    {' ', ' ', ' ', ' '},
    {' ', ' ', 'E', ' '},
    {' ', 'E', 'E', ' '},
    {' ', 'E', ' ', ' '}};