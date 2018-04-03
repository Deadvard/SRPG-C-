#include "DevInput.h"

DevInput::DevInput()
{
    //ctor
}

DevInput::~DevInput()
{
    //dtor
}

void DevInput::handleInput(SDL_Event* event, Input* input)
{
    if(event->key.type == SDL_KEYUP)
    {
        switch(event->key.keysym.sym)
        {
            case SDLK_F1:
                input->state = Input::pop;
                break;
            case SDLK_F2:
                input->state = Input::push.editor;
                break;
            case SDLK_F3:
                input->state = Input::push.mainMenu;
                break;
            case SDLK_F4:
                break;
            case SDLK_F5:
                input->state = Input::push.battle;
                break;
            case SDLK_F6:
                break;
            input->state = 0;
        }
    }
}
