#include "Gameplay/Player.h"

Player::Player()
{
    board = nullptr;
    nrOfPieces = 0;
}

Player::~Player()
{
    //dtor
}

void Player::setBoard(Board* board)
{
    this->board = board;

    for(int i = 0; i < nrOfPieces; i++)
    {
        //pieces[i].setBoard(board);
    }
}

void Player::draw()
{
    for(int i = 0; i < nrOfPieces; i++)
    {
        //pieces[i].draw();
    }
}
