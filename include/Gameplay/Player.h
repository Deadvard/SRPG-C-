#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"

class Player
{
public:
    Player();
    virtual ~Player();

    void setBoard(Board* board);

    virtual void update(float deltaTime) = 0;
    void draw();

private:
    Board* board;
    int nrOfPieces;
};

#endif // PLAYER_H
