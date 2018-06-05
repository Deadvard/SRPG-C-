#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "States/State.h"
#include "States/State_MainMenu.h"
#include "Gameplay/Map.h"
#include "Gameplay/Sprite.h"
#include "States/State_Battle.h"

class Game
{
public:
    Game();
    virtual ~Game();

    void run();
    void handleEvent();
    void render();

private:
    Window* window;

    TTF_Font* font16;
    TTF_Font* font32;
    TTF_Font* font64;

    State* current;

    bool quit;

    float deltaTime;
    unsigned int ticks;

    int windowWidth;
    int windowHeight;

    const static int renderWidth = 1280;
    const static int renderHeight = 720;
};

#endif // GAME_H
