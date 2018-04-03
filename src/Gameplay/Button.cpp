#include "Button.h"

Button::Button()
{
    buttonState = 0;
    title = "Unknown";
}

Button::~Button()
{
    //dtor
}

void Button::setTitle(char* newTitle)
{
    title = newTitle;
    setTexture(title, Drawable::COLOR_WHITE);
}

void Button::update(float deltaTime, Input* input)
{
    if(contains(input->screenX, input->screenY))
    {
        setTexturePosition(32,0);

        if(input->select == Input::pressed)
        {
            buttonState = 1;
            setTexturePosition(64,0);
        }
        else if(input->select == Input::released)
        {
            buttonState = 2;
        }
        else
        {
            buttonState = 0;
        }
    }
    else
    {
        setTexturePosition(0,0);
    }
}

bool Button::buttonPressed() const
{
    return buttonState == 1;
}

bool Button::buttonReleased() const
{
    return buttonState == 2;
}
