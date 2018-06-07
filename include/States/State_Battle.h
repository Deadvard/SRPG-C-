#ifndef STATE_BATTLE_H
#define STATE_BATTLE_H

#include "State.h"
#include "Gameplay/Map.h"
#include "Sprite.h"
#include "Board.h"

class State_Battle : public State
{
public:
    State_Battle(Window* window);
    virtual ~State_Battle();

    virtual void onCursorMoved(int x, int y);
    virtual void onSelect(int x, int y);
    virtual void onCancel(int x, int y);

    virtual void update(float deltaTime);
    virtual void draw();

private:
    Map currentMap;
    Sprite* sprites;
    int spritesCount;

    int turn;

    Drawable test;
    Sprite cursor;
    Sprite arrow;
    Board* board;
    Sprite* selected;
};

#endif // STATE_BATTLE_H
