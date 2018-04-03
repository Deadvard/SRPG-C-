#ifndef INPUTDEVICE_H
#define INPUTDEVICE_H

#include <SDL2/SDL.h>

struct States
{
    const static int editor = 2;
    const static int mainMenu = 3;
    const static int war = 4;
    const static int battle = 5;
    const static int combat = 6;
};

struct Input
{
    int screenX = 0;
    int screenY = 0;
    int worldX = 0;
    int worldY = 0;

    int up = 0;
    int down = 0;
    int left = 0;
    int right = 0;
    int select = 0;
    int cancel = 0;

    int quit = 0;

    int state = 0;

    const static int pop = 1;
    const static States push;

    const static int pressed = 1;
    const static int released = 2;
};



class InputDevice
{
public:
    InputDevice();
    virtual ~InputDevice();

    virtual void handleInput(SDL_Event* event, Input* input) = 0;

protected:
    /* Device: mouse = 0, keyboard = 1, controller = 2 */
    int device;
};

#endif // INPUTDEVICE_H
