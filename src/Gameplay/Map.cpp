#include "Gameplay/Map.h"

Map::Map()
{
    this->mapLayout = nullptr;
    this->tilesX = 0;
    this->tilesY = 0;
}

Map::~Map()
{
    if(this->mapLayout)
    {
        delete this->mapLayout;
    }
}

void Map::setMapLayout(int mapLayout[], int tilesX, int tilesY)
{
    if(this->mapLayout)
    {
        delete this->mapLayout;
    }

    this->mapLayout = new int[tilesX * tilesY];
    this->tilesX = tilesX;
    this->tilesY = tilesY;

    for(int i = 0; i < tilesX * tilesY; i++)
    {
        this->mapLayout[i] = mapLayout[i];
    }
}

void Map::draw()
{
    for(int x = 0; x < tilesX; x++)
    {
        for(int y = 0; y < tilesY; y++)
        {
            setRenderPosition(getRenderW() * x, getRenderH() * y);

            const int tilesW = getWidth() / getRenderW();
            setTexturePosition(getTextureW() * (getTile(x,y) % tilesW), getTextureH() * (getTile(x,y) / tilesW));

            Drawable::draw();
        }
    }
}

int Map::getTile(int x, int y)
{
    return mapLayout[x + y * tilesX];
}

