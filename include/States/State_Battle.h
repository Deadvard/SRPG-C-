#ifndef STATE_BATTLE_H
#define STATE_BATTLE_H

#include "State_Base.h"
#include "Gameplay/Map.h"
#include "Sprite.h"
#include "Board.h"

class State_Battle : public State_Base
{
public:
    State_Battle(Window* window);
    virtual ~State_Battle();

    virtual void update(float deltaTime, Input* input);
    virtual void draw();

private:
    Map currentMap;
    Drawable test;
    Sprite test2;
    Sprite cursor;
    Board* board;
    Position* charpos;
    bool stop;
    bool selected;
};

#endif // STATE_BATTLE_H
