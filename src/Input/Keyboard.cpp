#include "Keyboard.h"

Keyboard::Keyboard()
{
    device = 1;
}

Keyboard::~Keyboard()
{
    //dtor
}

void Keyboard::handleInput(SDL_Event* event, Input* input)
{
    if(event->key.type == SDL_KEYDOWN)
    {
        switch(event->key.keysym.sym)
        {
            case SDLK_q:
                //input->input = 1;
                break;
            case SDLK_w:
                input->up = Input::pressed;
                break;
            case SDLK_e:
                //input->input = 3;
                break;
            case SDLK_r:
                //input->input = 4;
                break;
            case SDLK_ESCAPE:
                input->quit = Input::pressed;
                break;
        }
    }
    else if(event->button.type == SDL_KEYUP)
    {
         switch(event->key.keysym.sym)
        {
            case SDLK_q:
                //input->input = -1;
                break;
            case SDLK_w:
                input->up = Input::pressed;
                break;
            case SDLK_e:
                //input->input = -3;
                break;
            case SDLK_r:
                //input->input = -4;
                break;
        }
    }
}
