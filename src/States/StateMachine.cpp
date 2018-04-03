#include "StateMachine.h"

StateMachine::StateMachine()
{
    this->window = nullptr;
    states = new State_Base*[10];
    nrOfStates = 0;
}

StateMachine::~StateMachine()
{
    for(int i = 0; i < nrOfStates; i++)
    {
        delete states[i];
    }
    delete[] states;
}

void StateMachine::setWindow(Window* window)
{
    this->window = window;
}

void StateMachine::push(Input* input)
{
    if(input->state > 1)
    {
        switch(input->state)
        {
        case 2:
            states[nrOfStates] = new State_Editor(window);
            break;
        case 3:
            states[nrOfStates] = new State_MainMenu(window);
            break;
        case 4:
            //states[nrOfStates] = new State_Battle(window);
            break;
        case 5:
            states[nrOfStates] = new State_Battle(window);
            break;
        case 6:
            //states[nrOfStates] = new State_Battle(window);
            break;
        }
        window->setRenderPosition(0,0);
        input->state = 0;
        nrOfStates++;
    }

}

State_Base* StateMachine::pop()
{
    window->setRenderPosition(0,0);
    nrOfStates--;
    delete states[nrOfStates];
    return states[nrOfStates - 1];
}

State_Base* StateMachine::peek() const
{
    return states[nrOfStates - 1];
}
