#ifndef MAP_H
#define MAP_H

#include "Engine/Drawable.h"

class Map : public Drawable
{
public:
    Map();
    virtual ~Map();

    void setMapLayout(int mapLayout[], int tilesX, int tilesY);

    virtual void draw();

private:
    int* mapLayout;
    int tilesX;
    int tilesY;

    int getTile(int x, int y);
};

#endif // MAP_H
