#ifndef DEVINPUT_H
#define DEVINPUT_H

#include "InputDevice.h"


class DevInput : public InputDevice
{
public:
    DevInput();
    virtual ~DevInput();
    virtual void handleInput(SDL_Event* event, Input* input);

private:
};

#endif // DEVINPUT_H
