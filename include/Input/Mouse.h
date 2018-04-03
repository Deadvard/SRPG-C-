#ifndef MOUSE_H
#define MOUSE_H

#include "InputDevice.h"
#include "Window.h"

class Mouse : InputDevice
{
public:
    Mouse();
    virtual ~Mouse();

    virtual void handleInput(SDL_Event* event, Input* input);

    void setWindow(Window* window);

    void update(float deltaTime, Input* input);

    void edgeScroll(float deltaTime);

    int getMouseX() const;
    int getMouseY() const;
    int getWorldX() const;
    int getWorldY() const;

    void moveView(int x, int y);

private:
    Window* window;
    int mouseX;
    int mouseY;
    int edgeScrollSensitivity;
    int speed;
};

#endif // MOUSE_H
