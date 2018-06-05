#include "Gameplay/Sprite.h"
#include <iostream>

Sprite::Sprite()
{
    board = nullptr;
    from = nullptr;
    to = nullptr;
    distance = 10;

    blocked = -1;

    frameTime = 0.25f;
    timeSinceFrame = 0.0f;
    currentFrame = 0;
    startFrame = 0;
    stopFrame = 1;
    speed = 0.1;
    newX = 0;
    newY = 0;

    timeSinceMoveX = 0.0f;
    timeSinceMoveY = 0.0f;
    moveStartX = 0.0f;
    moveStartY = 0.0f;

    selected = false;
}

Sprite::~Sprite()
{
    //dtor
}

void Sprite::initialBoardPosition(int x, int y)
{
    newX = x * 32;
    newY = y * 32;
    setRenderPosition(x * getRenderW() * 32, y * getRenderH() * 32);
    if(board && board->getPosition(x, y))
    {
        board->getPosition(x, y)->blocked = blocked;
    }
}

void Sprite::setBoard(Board* board)
{
    this->board = board;
    //from = board->getPosition(5,5);
}

void Sprite::setDistance(int distance)
{
    this->distance = distance;
}

void Sprite::setBlocked(int blocked)
{
    this->blocked = blocked;
}

void Sprite::select(int x, int y)
{
    if(contains(x,y))
    {
        from = board->getPosition(getRenderX()/getRenderW(),getRenderY()/getRenderH());
        board->showPath(from->x, from->y, distance, blocked);
        selected = true;
    }

}

void Sprite::tryPosition(int x, int y)
{
    if(!to)
    {
        to = board->getPosition(x,y);
        if(to && to->fromX == -1)
        {
            to = nullptr;
            board->hidePath();
        }
    }
}

void Sprite::update(float deltaTime)
{
    startMove();
    moveSprite(deltaTime);
    nextFrame(deltaTime);
}

void Sprite::onHover(int x, int y)
{

}

void Sprite::moveTo(int x, int y)
{
    newX = x;
    newY = y;
    moveStartX = getRenderX();
    moveStartY = getRenderY();
}

void Sprite::startMove()
{
    if(from && to && board)
    {
        if(getRenderX() == newX && getRenderY() == newY)
        {
            if(from == to)
            {
                to = nullptr;
                board->hidePath();
            }
            else
            {
                from = board->moveTo(from->x, from->y, to->x, to->y);
                moveTo(from->x * getRenderW(),from->y * getRenderH());
            }
        }
    }
}

void Sprite::moveSprite(float deltaTime)
{
    float x = getRenderX();
    float y = getRenderY();

    if(getRenderX() != newX)
    {
        timeSinceMoveX += deltaTime;
        x = moveStartX + (newX - moveStartX) * timeSinceMoveX / speed;

        if(timeSinceMoveX > speed)
        {
            x = newX;
            timeSinceMoveX = 0.0f;
            moveStartX = 0.0f;
        }
    }

    if(getRenderY() != newY)
    {
        timeSinceMoveY += deltaTime;
        y = moveStartY + (newY - moveStartY) * timeSinceMoveY / speed;

        if(timeSinceMoveY > speed)
        {
            y = newY;
            timeSinceMoveY = 0.0f;
            moveStartY = 0.0f;
        }
    }

     setRenderPosition(x, y);
}

void Sprite::nextFrame(float deltaTime)
{
    timeSinceFrame += deltaTime;

    if(timeSinceFrame >= frameTime)
    {
        timeSinceFrame = 0.0f;

        currentFrame = currentFrame >= stopFrame ? startFrame : currentFrame + 1;

        const int tilesW = getWidth() / getRenderW();
        setTexturePosition(getTextureW() * (currentFrame % tilesW), getTextureH() * (currentFrame / tilesW));
    }
}
