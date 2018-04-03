#ifndef STATE_EDITOR_H
#define STATE_EDITOR_H

#include "State_Base.h"
#include "Drawable.h"


class State_Editor : public State_Base
{
public:
    State_Editor(Window* window);
    virtual ~State_Editor();

    virtual void update(float deltaTime, Input* input);
    virtual void draw();

private:
    Drawable background;
};

#endif // STATE_EDITOR_H
