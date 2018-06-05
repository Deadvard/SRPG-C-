#include "State.h"

State::State(Window* window)
{
    this->window = window;
}

State::~State()
{

}

void State::setWindow(Window* window)
{
    this->window = window;
}



