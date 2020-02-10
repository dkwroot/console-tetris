#ifndef TETRISBLOCKS__H
#define TETRISBLOCKS__H

class tetrisblocks
{
public:
    tetrisblocks();
    ~tetrisblocks();

    void rotate();
    int getXpos();
    int getYpos();
    void setPosition(int, int); // x,y
    void randomize();
    void reset();

    char m_activeBlock[4][4];

private:
    int m_xPos;
    int m_yPos;
    static char blockLine[4][4];
    static char blockSquare[4][4];
    static char blockT[4][4];
    static char blockLL[4][4];
    static char blockLR[4][4];
    static char blockZagL[4][4];
    static char blockZagR[4][4];
};

#endif