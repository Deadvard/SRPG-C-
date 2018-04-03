#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "InputDevice.h"

class Controller : InputDevice
{
public:
    Controller();
    virtual ~Controller();
    virtual void handleInput(SDL_Event* event, Input* input);

private:
};

#endif // CONTROLLER_H
