#include "State_Battle.h"
#include <iostream>

State_Battle::State_Battle(Window* window)
    : State_Base(window)
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
    currentMap.setTexture("tiles.png");
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
    test.setTexture("RGB.png");
    test.setTexturePosition(64,0);
    test.setTextureSize(32,32);
    test.setRenderSize(32,32);
    test.setRenderPosition(5 * 32,5 * 32);

    test2.setWindow(window);
    test2.setTexture("hero.png");
    test2.setTextureSize(32,32);
    test2.setRenderSize(32,32);
    test2.setRenderPosition(5 * 32,5 * 32);
    test2.setBoard(board);

    cursor.setWindow(window);
    cursor.setTexture("cursor.png");
    cursor.setTextureSize(32,32);
    cursor.setRenderSize(32,32);
    cursor.setRenderPosition(5 * 32,5 * 32);
    cursor.setBoard(board);

    stop = false;
    charpos = board->getPosition(5,5);
    //board->showPath(5,5,10,1);
    selected = false;
}

State_Battle::~State_Battle()
{
    delete board;
    //dtor
}

void State_Battle::update(float deltaTime, Input* input)
{
    board->clear();

    test2.update(deltaTime);

    cursor.setRenderPosition((int)(input->worldX/32) * 32, (int)(input->worldY/32) * 32);

    if(input->select == Input::pressed)
    {
        if(!stop)
        {
            if(!selected)
            {
                test2.select(input->worldX,input->worldY);
                selected = true;
            }


            if(selected)
            {
                test2.tryPosition((int)(input->worldX/32), (int)(input->worldY/32));
                selected = false;
            }

            stop = true;
        }
    }
    else
    {
        stop = false;
    }

    Position* to = board->getPosition((int)(input->worldX/32), (int)(input->worldY/32));
    board->calculateShortestPath(to);
}

void State_Battle::draw()
{
    currentMap.draw();

    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(board->getPosition(i,j)->fastest)
            {
                test.setTexturePosition(32, 0);
                test.setRenderPosition(board->getPosition(i,j)->x * 32, board->getPosition(i,j)->y * 32);
                test.draw();
            }
            else if(board->getPosition(i,j)->fromX != -1)
            {
                test.setTexturePosition(64, 0);
                test.setRenderPosition(board->getPosition(i,j)->x * 32, board->getPosition(i,j)->y * 32);
                test.draw();
            }
        }
    }
    test2.draw();
    cursor.draw();
}
