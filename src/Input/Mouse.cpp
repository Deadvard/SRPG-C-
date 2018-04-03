#include "Mouse.h"

Mouse::Mouse()
{
    device = 0;
    window = nullptr;
    mouseX = 0;
    mouseY = 0;

    edgeScrollSensitivity = 0;
    speed = 1000;
}

Mouse::~Mouse()
{
    //dtor
}

void Mouse::handleInput(SDL_Event* event, Input* input)
{
    if(event->button.type == SDL_MOUSEBUTTONDOWN)
    {
        switch(event->button.button)
        {
            case SDL_BUTTON_LEFT:
                input->select = Input::pressed;
                break;
            case SDL_BUTTON_RIGHT:
                input->cancel = Input::pressed;
                break;
            case SDL_BUTTON_MIDDLE:
                //input->input = Input::pressed;
                break;
        }
    }
    else if(event->button.type == SDL_MOUSEBUTTONUP)
    {
        switch(event->button.button)
        {
            case SDL_BUTTON_LEFT:
                input->select = Input::released;
                break;
            case SDL_BUTTON_RIGHT:
                input->cancel = Input::released;
                break;
            case SDL_BUTTON_MIDDLE:
                //input->input = Input::released;
                break;
        }
    }
    else
    {
        input->select = 0;
        input->cancel = 0;
    }
}

void Mouse::setWindow(Window* window)
{
    this->window = window;
}

void Mouse::update(float deltaTime, Input* input)
{
    SDL_GetMouseState(&mouseX, &mouseY);

    if(input->state == Input::push.war || input->state == Input::push.battle || input->state == Input::push.editor)
    {
        edgeScrollSensitivity = 0;//ändra här för att fixa
    }
    else if(input->state != 0)
    {
        edgeScrollSensitivity = 0;
    }

    input->screenX = getMouseX();
    input->screenY = getMouseY();
    input->worldX = getWorldX();
    input->worldY = getWorldY();

    edgeScroll(deltaTime);
}

void Mouse::edgeScroll(float deltaTime)
{
    if(edgeScrollSensitivity)
    {
        if(mouseX < window->getWindowW() / edgeScrollSensitivity)
        {
            window->moveView(1*speed*deltaTime, 0);
        }
        if(mouseY < window->getWindowH() / edgeScrollSensitivity)
        {
            window->moveView(0, 1*speed*deltaTime);
        }
        if(mouseX > window->getWindowW() - (window->getWindowW() / edgeScrollSensitivity))
        {
            window->moveView(-1*speed*deltaTime, 0);
        }
        if(mouseY > window->getWindowH() - (window->getWindowH() / edgeScrollSensitivity))
        {
            window->moveView(0, -1*speed*deltaTime);
        }
    }
}

int Mouse::getMouseX() const
{
    return window->scaledX(mouseX);
}

int Mouse::getMouseY() const
{
    return window->scaledY(mouseY);
}

int Mouse::getWorldX() const
{
    return window->scaledX(mouseX - window->getRenderX());
}

int Mouse::getWorldY() const
{
    return window->scaledY(mouseY - window->getRenderY());
}



