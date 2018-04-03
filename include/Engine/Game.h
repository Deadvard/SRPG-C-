#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "States/State_Base.h"
#include "States/State_MainMenu.h"
#include "Gameplay/Map.h"
#include "Gameplay/Sprite.h"
#include "StateMachine.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Controller.h"
#include "DevInput.h"

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
    Mouse* mouse;
    Controller* controller;
    Keyboard* keyboard;
    DevInput* devInput;

    Input input;

    TTF_Font* font16;
    TTF_Font* font32;
    TTF_Font* font64;

    StateMachine states;

    bool quit;

    float deltaTime;
    unsigned int ticks;

    int windowWidth;
    int windowHeight;

    const static int renderWidth = 1280;
    const static int renderHeight = 720;
};

#endif // GAME_H
