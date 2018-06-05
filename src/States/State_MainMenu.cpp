#include "State_MainMenu.h"
#include <iostream>

State_MainMenu::State_MainMenu(Window* window)
    : State(window)
{
    background.setWindow(window);
    background.setTexture("resources/menuBG.png");
    background.setRenderSize(1280,720);



    for(int i = 0; i < 3; i++)
    {
        buttons[i].setWindow(window);

        buttons[i].setTexture("resources/RGB.png");
        buttons[i].setTexturePosition(i * 32, 0);
        buttons[i].setTextureSize(32, 32);

        buttons[i].setRenderSize(320,60);
        buttons[i].setRenderPosition(window->getRenderW()/2 - buttons[i].getRenderW()/2, window->getRenderH()/2 + i * buttons[i].getRenderH() * 1.5f);
    }
}

State_MainMenu::~State_MainMenu()
{
    //dtor
}

void State_MainMenu::update(float deltaTime)
{
    for(int i = 0; i < 3; i++)
    {
        buttons[i].update(deltaTime);
    }

    if(buttons[0].buttonReleased())
    {

    }
    if(buttons[1].buttonReleased())
    {

    }
    if(buttons[2].buttonReleased())
    {

    }
}

void State_MainMenu::draw()
{
    background.draw();

    for(int i = 0; i < 3; i++)
    {
        buttons[i].draw();
    }
}
