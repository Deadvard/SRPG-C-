#include "State_Base.h"

State_Base::State_Base(Window* window)
{
    this->window = window;
}

State_Base::~State_Base()
{

}

void State_Base::setWindow(Window* window)
{
    this->window = window;
}



