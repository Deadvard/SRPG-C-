#ifndef SPRITE_H
#define SPRITE_H

#include "Engine/Drawable.h"
#include "Board.h"
#include "Equipment.hpp"

class Sprite : public Drawable
{
public:
    Sprite();
    virtual ~Sprite();

    bool isMoving() const;
    bool isTeam(int team) const;

    void initialBoardPosition(int x, int y);

    void setBoard(Board* board);
    void setDistance(int distance);
    void setBlocked(int blocked);

    void select(int x, int y);
    void tryPosition(int x, int y);
    void update(float deltaTime);

    int dealDamage() const;
    void takeDamage(int damage);

    bool selected;

private:
    static const int inventorySize = 5;
    Equipment inventory[inventorySize];
    int equipped;

    int experience;
    int level;
    int health;

    int strength;
    int magic;
    int skill;
    int speedstat;
    int luck;
    int defense;
    int resistance;

    Board* board;
    Position* from;
    Position* to;
    int movementLeft;
    int distance;
    int blocked;
    int range;
    float timeSinceMoveX;
    float timeSinceMoveY;

    float frameTime;
    float timeSinceFrame;
    int currentFrame;
    int startFrame;
    int stopFrame;

    float newX;
    float newY;
    float moveStartX;
    float moveStartY;

    float speed;

    void onHover(int x, int y);

    void moveTo(int x, int y);
    void startMove();
    void moveSprite(float deltaTime);
    void nextFrame(float deltaTime);
};

void battle(Sprite& left, Sprite& right);

#endif // SPRITE_H
