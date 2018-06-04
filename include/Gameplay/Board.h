#ifndef BOARD_H
#define BOARD_H

enum Arrow
{
    up,
    down,
    right,
    left,
    downLeft,
    downRight,
    upLeft,
    upRight,
    leftRight,
    upDown,
    none
};

struct Position
{
    int weight = 0;
    int distance = 0;
    int blocked = 0;

    int x = 0;
    int y = 0;
    int fromX = 0;
    int fromY = 0;

    Arrow fastest = none;
};

class Board
{
public:
    Board(int layout[], int width, int height);
    virtual ~Board();

    void clear();

    Position* getPosition(int x, int y) const;
    Position* moveTo(int fromX, int fromY, int toX, int toY) const;

    void calculateShortestPath(Position* to);

    void showPath(int x, int y, int distance, int blocked);
    void hidePath();


private:
    static const int none = -1;

    Position* positions;
    Position* path;
    int width;
    int height;

    void createPath(Position* from, Position* to);
    void removePath(Position* from, Position* to);
};

#endif // BOARD_H
