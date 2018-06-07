#include "Gameplay/Board.h"
#include <iostream>

Board::Board(int layout[], int width, int height)
{
    this->positions = new Position[width * height];
    this->width = width;
    this->height = height;

    for(int x = 0; x < width; x++)
    {
        for(int y = 0; y < height; y++)
        {
            getPosition(x, y)->weight = layout[x + y * width];
            getPosition(x, y)->x = x;
            getPosition(x, y)->y = y;
            getPosition(x, y)->fromX = none;
            getPosition(x, y)->fromY = none;
            getPosition(x, y)->distance = none;
            getPosition(x, y)->blocked = none;

        }
    }
}

Board::~Board()
{
    delete this->positions;
}

void Board::clear()
{
    for(int x = 0; x < width; x++)
    {
        for(int y = 0; y < height; y++)
        {
            getPosition(x, y)->fastest = Arrow::none;
        }
    }
}

Position* Board::getPosition(int x, int y) const
{
    return (x >= 0 && y >= 0 && x < width && y < height) ? &positions[x + y * width] : nullptr;
}

Position* Board::moveTo(int fromX, int fromY, int toX, int toY) const
{
    Position* from = getPosition(fromX, fromY);
    Position* to = getPosition(toX, toY);

    if(!from || (to && to->fromX == none) || from == to)
    {
        to = nullptr;
    }
    while(to && (from->x != to->fromX || from->y != to->fromY))
    {
        to = getPosition(to->fromX, to->fromY);
    }

    return to;
}

void Board::calculateShortestPath(Position* to)
{
    Arrow last = Arrow::none;

    while(to && (to->fromX > 0 || to->fromY > 0))
    {

        if(to->fromX == to->x && to->fromY > to->y)
        {
            switch(last)
            {
                case Arrow::down: to->fastest = Arrow::upDown; break;
                case Arrow::right: to->fastest = Arrow::downRight; break;
                case Arrow::left: to->fastest = Arrow::downLeft; break;
                case Arrow::none:  to->fastest = Arrow::up; break;
            }
            last = Arrow::down;
        }

        else if(to->fromX == to->x && to->fromY < to->y)
        {
            switch(last)
            {
                case Arrow::up: to->fastest = Arrow::upDown; break;
                case Arrow::right: to->fastest = Arrow::upRight; break;
                case Arrow::left: to->fastest = Arrow::upLeft; break;
                case Arrow::none:  to->fastest = Arrow::down; break;
            }
            last = Arrow::up;
        }

        else if(to->fromX > to->x && to->fromY == to->y)
        {
            switch(last)
            {
                case Arrow::down: to->fastest = Arrow::upRight; break;
                case Arrow::up: to->fastest = Arrow::downRight; break;
                case Arrow::left: to->fastest = Arrow::leftRight; break;
                case Arrow::none:  to->fastest = Arrow::left; break;
            }
            last = Arrow::left;
        }

        else if(to->fromX < to->x && to->fromY == to->y)
        {
            switch(last)
            {
                case Arrow::down: to->fastest = Arrow::upLeft; break;
                case Arrow::up: to->fastest = Arrow::downLeft; break;
                case Arrow::right: to->fastest = Arrow::leftRight; break;
                case Arrow::none:  to->fastest = Arrow::right; break;
            }
            last = Arrow::right;
        }

        to = getPosition(to->fromX, to->fromY);
    }
}

Position* Board::calculateRange(Position* to, int range)
{
    Position* result = to;
    range--;

    if(result && result->fromX == none && range >= 0)
    {

        result = calculateRange(getPosition(result->x - 1, result->y), range);
        result = result ? result : to;
    }

    if(result && result->fromX == none && range >= 0)
    {
        result = calculateRange(getPosition(result->x, result->y - 1), range);
        result = result && result->fromX != none ? result : to;
    }

    if(result && result->fromX == none && range >= 0)
    {
        result = calculateRange(getPosition(result->x + 1, result->y), range);
        result = result && result->fromX != none ? result : to;
    }

    if(result && result->fromX == none && range >= 0)
    {
        result = calculateRange(getPosition(result->x, result->y + 1), range);
        result = result && result->fromX != none ? result : to;
    }

    return result;
}

void Board::showPath(int x, int y, int distance, int blocked)
{
    hidePath(blocked);
    path = getPosition(x, y);

    if(path)
    {
        path->fromX = none;
        path->fromY = none;
        path->distance = distance;
        path->blocked = blocked;

        createPath(path, getPosition(path->x - 1, path->y), blocked);
        createPath(path, getPosition(path->x, path->y - 1), blocked);
        createPath(path, getPosition(path->x + 1, path->y), blocked);
        createPath(path, getPosition(path->x, path->y + 1), blocked);
    }
}

void Board::hidePath(int blocked)
{
    if(path)
    {
        const int distance = path->distance;
        removePath(path, getPosition(path->x - 1, path->y));

        path->distance = distance;
        removePath(path, getPosition(path->x, path->y - 1));

        path->distance = distance;
        removePath(path, getPosition(path->x + 1, path->y));

        path->distance = distance;
        removePath(path, getPosition(path->x, path->y + 1));

        path->fromX = none;
        path->fromY = none;
        path->distance = none;
        path->blocked = blocked;

        path = nullptr;
    }
}

void Board::createPath(Position* from, Position* to, int blocked)
{
    if(to)
    {
        if(from->distance >= to->distance)
        {
            to->distance = from->distance - to->weight;

            if(to->distance >= 0 && (to->blocked == none || blocked == to->blocked))
            {
                to->fromX = from->x;
                to->fromY = from->y;

                createPath(to, getPosition(to->x - 1, to->y), blocked);
                createPath(to, getPosition(to->x, to->y - 1), blocked);
                createPath(to, getPosition(to->x + 1, to->y), blocked);
                createPath(to, getPosition(to->x, to->y + 1), blocked);
            }
        }
    }
}

void Board::removePath(Position* from, Position* to)
{
    if(to)
    {
        to->distance = from->distance - to->weight;
        if(to->distance >= 0)
        {
            const int distance = to->distance;
            removePath(to, getPosition(to->x - 1, to->y));

            to->distance = distance;
            removePath(to, getPosition(to->x, to->y - 1));

            to->distance = distance;
            removePath(to, getPosition(to->x + 1, to->y));

            to->distance = distance;
            removePath(to, getPosition(to->x, to->y + 1));

            to->fromX = none;
            to->fromY = none;
        }
    }
}
