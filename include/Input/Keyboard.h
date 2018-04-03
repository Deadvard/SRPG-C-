#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "InputDevice.h"

class Keyboard : InputDevice
{
public:
    Keyboard();
    virtual ~Keyboard();
    virtual void handleInput(SDL_Event* event, Input* input);

private:

};

#endif // KEYBOARD_H
