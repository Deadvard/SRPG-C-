#ifndef STATE_MAINMENU_H
#define STATE_MAINMENU_H

#include "State_Base.h"
#include "Button.h"

class State_MainMenu : public State_Base
{
public:
    State_MainMenu(Window* window);
    virtual ~State_MainMenu();

    virtual void update(float deltaTime, Input* input);
    virtual void draw();

private:
    Drawable background;
    Button buttons[3];
};

#endif // STATE_MAINMENU_H
