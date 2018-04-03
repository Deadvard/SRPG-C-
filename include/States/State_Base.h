#ifndef STATE_BASE_H
#define STATE_BASE_H

#include "Window.h"
#include "InputDevice.h"

class State_Base
{
public:
    State_Base(Window* window);
    virtual ~State_Base();

    void setWindow(Window* window);

    virtual void update(float deltaTime, Input* input) = 0;
    virtual void draw() = 0;

protected:
    Window* window;

};

#endif // STATE_BASE_H
