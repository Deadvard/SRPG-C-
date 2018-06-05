#include "State_Battle.h"
#include <iostream>

State_Battle::State_Battle(Window* window)
    : State(window)
{
    int m[500];
    for(int i = 0; i < 500; i++)
    {
        m[i] = 0;
    }
    m[50 * 5 + 6] = 1;

    currentMap = Map();
    currentMap.setWindow(window);
    currentMap.setMapLayout(m, 50, 10);
    currentMap.setTexture("resources/tiles.png");
    currentMap.setRenderSize(32,32);
    currentMap.setTextureSize(32,32);

     int n[500];
    for(int i = 0; i < 500; i++)
    {
        n[i] = 3;
    }
    n[50 * 5 + 6] = 2000;

    board = new Board(n, 50,10);

    test.setWindow(window);
    test.setTexture("resources/RGB.png");
    test.setTexturePosition(64,0);
    test.setTextureSize(32,32);
    test.setRenderSize(32,32);
    test.setRenderPosition(5 * 32,5 * 32);

    cursor.setWindow(window);
    cursor.setTexture("resources/cursor.png");
    cursor.setTextureSize(32,32);
    cursor.setRenderSize(32,32);
    cursor.setRenderPosition(5 * 32,5 * 32);
    cursor.setBoard(board);

    arrow.setWindow(window);
    arrow.setTexture("resources/arrow.png");
    arrow.setTextureSize(32,32);
    arrow.setRenderSize(32,32);
    arrow.setRenderPosition(5 * 32,5 * 32);
    arrow.setBoard(board);

    spritesCount = 10;
    sprites = new Sprite[spritesCount];

    for(int i = 0; i < spritesCount; i++)
    {
        sprites[i].setWindow(window);
        sprites[i].setTexture("resources/hero.png");
        sprites[i].setTextureSize(32,32);
        sprites[i].setRenderSize(32,32);
        sprites[i].setBoard(board);
        sprites[i].setBlocked(i + 1);
        sprites[i].initialBoardPosition((3 + i), 3);
    }

    stop = false;
    selected = nullptr;
}

State_Battle::~State_Battle()
{
    delete board;
    delete[] sprites;
}

void State_Battle::onCursorMoved(int x, int y)
{
    board->clear();
    cursor.setRenderPosition((x / 32) * 32, (y / 32) * 32);

    Position* to = board->getPosition(x / 32, y / 32);
    board->calculateShortestPath(to);
}

void State_Battle::onSelect(int x, int y)
{
    if(selected)
    {
        selected->tryPosition(x / 32, y / 32);
        selected->selected = false;
    }

    for(int i = 0; i < spritesCount; i++)
    {
        if(!sprites[i].selected)
        {
            sprites[i].select(x, y);
            if(sprites[i].selected)
            {
                selected = &sprites[i];
            }
        }
    }
}

void State_Battle::onCancel(int x, int y)
{

}

void State_Battle::update(float deltaTime)
{
    for(int i = 0; i < spritesCount; i++)
    {
        sprites[i].update(deltaTime);
    }
}

void State_Battle::draw()
{
    currentMap.draw();

    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(board->getPosition(i,j)->fromX != -1)
            {
                test.setRenderPosition(board->getPosition(i,j)->x * 32, board->getPosition(i,j)->y * 32);
                test.draw();
            }
            if(board->getPosition(i,j)->fastest != Arrow::none)
            {
                arrow.setTexturePosition(32 * board->getPosition(i,j)->fastest, 0);
                arrow.setRenderPosition(board->getPosition(i,j)->x * 32, board->getPosition(i,j)->y * 32);
                arrow.draw();
            }
        }
    }

    for(int i = 0; i < spritesCount; i++)
    {
        sprites[i].draw();
    }
    cursor.draw();
}
