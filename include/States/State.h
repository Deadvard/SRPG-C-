#ifndef STATE_H
#define STATE_H

#include "Window.h"

class State
{
public:
    State(Window* window);
    virtual ~State();

    void setWindow(Window* window);

    virtual void onCursorMoved(int x, int y) {};
    virtual void onSelect(int x, int y) {};
    virtual void onCancel(int x, int y) {};

    virtual void update(float deltaTime) = 0;
    virtual void draw() = 0;

protected:
    Window* window;

};

#endif // STATE_BASE_H
