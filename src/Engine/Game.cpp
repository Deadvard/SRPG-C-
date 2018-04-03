#include "Engine/Game.h"

Game::Game()
{
    quit = false;
    ticks = 0;
    deltaTime = 0.0f;
    windowWidth = renderWidth;
    windowHeight = renderHeight;

    SDL_Init(SDL_INIT_EVERYTHING);

    window = new Window();
    window->setFullscreen(1);

    mouse = new Mouse();
    mouse->setWindow(window);
    keyboard = new Keyboard();
    controller = new Controller();
    devInput = new DevInput();

    TTF_Init();
    font16 = TTF_OpenFont("arial.ttf", 16);
    font32 = TTF_OpenFont("arial.ttf", 32);
    font64 = TTF_OpenFont("arial.ttf", 64);

    Drawable::setFonts(font16, font32, font64);
    states.setWindow(window);

    input.state = Input::push.mainMenu;
    states.push(&input);
}

Game::~Game()
{
    TTF_CloseFont(font16);
    TTF_CloseFont(font32);
    TTF_CloseFont(font64);
    TTF_Quit();
    delete mouse;
    delete window;
    delete controller;
    delete devInput;
    SDL_Quit();
}

void Game::run()
{
    ticks = SDL_GetTicks();

    while(!quit)
    {
        deltaTime += (SDL_GetTicks() - ticks) / 1000.0f;
        ticks = SDL_GetTicks();

        if(deltaTime >= 1.0/60.0f)
        {
            handleEvent();
            mouse->update(deltaTime, &input);

            if(input.state == Input::pop)
            {
                input.state = 0;
                states.pop();
            }
            states.push(&input);

            states.peek()->update(deltaTime, &input);

            render();

            deltaTime = 0.0f;
        }

    }
}
void Game::handleEvent()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        window->handleEvent(&event);

        mouse->handleInput(&event, &input);
        keyboard->handleInput(&event, &input);
        controller->handleInput(&event, &input);
        devInput->handleInput(&event, &input);

        if(event.type == SDL_QUIT || input.quit == Input::pressed)
        {
            quit = true;
        }
    }
}

void Game::render()
{
    SDL_RenderClear(window->getRenderer());
    states.peek()->draw();
    SDL_RenderPresent(window->getRenderer());
}
