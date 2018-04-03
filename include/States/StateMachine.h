#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "State_Base.h"
#include "State_Editor.h"
#include "State_MainMenu.h"
#include "State_Battle.h"

class StateMachine
{
public:
    StateMachine();
    virtual ~StateMachine();

    void setWindow(Window* window);

    void push(Input* input);
    State_Base* pop();
    State_Base* peek() const;

private:
    Window* window;
    State_Base** states;
    int nrOfStates;
};

#endif // STATEMACHINE_H
