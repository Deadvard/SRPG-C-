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


void Board::showPath(int x, int y, int distance, int blocked)
{
    hidePath();
    path = getPosition(x, y);

    if(path)
    {
        path->fromX = none;
        path->fromY = none;
        path->distance = distance;
        path->blocked = blocked;

        createPath(path, getPosition(path->x - 1, path->y));
        createPath(path, getPosition(path->x, path->y - 1));
        createPath(path, getPosition(path->x + 1, path->y));
        createPath(path, getPosition(path->x, path->y + 1));
    }
}

void Board::hidePath()
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
        path->blocked = none;

        path = nullptr;
    }
}

void Board::createPath(Position* from, Position* to)
{
    if(to)
    {
        if(from->distance >= to->distance)
        {
            to->distance = from->distance - to->weight;

            if(to->distance >= 0 && (to->blocked == none || from->blocked == to->blocked))
            {
                to->fromX = from->x;
                to->fromY = from->y;
                to->blocked = from->blocked;

                createPath(to, getPosition(to->x - 1, to->y));
                createPath(to, getPosition(to->x, to->y - 1));
                createPath(to, getPosition(to->x + 1, to->y));
                createPath(to, getPosition(to->x, to->y + 1));
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
            to->distance = none;
            to->blocked = none;
        }
    }
}
