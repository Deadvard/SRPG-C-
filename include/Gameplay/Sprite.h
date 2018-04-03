#ifndef SPRITE_H
#define SPRITE_H

#include "Engine/Drawable.h"
#include "Board.h"

class Sprite : public Drawable
{
public:
    Sprite();
    virtual ~Sprite();

    void setBoard(Board* board);
    void setDistance(int distance);
    void setBlocked(int blocked);

    void select(int x, int y);
    void tryPosition(int x, int y);
    void update(float deltaTime);


private:
    Board* board;
    Position* from;
    Position* to;
    int distance;
    int blocked;
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

#endif // SPRITE_H
