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

    TTF_Init();
    font16 = TTF_OpenFont("arial.ttf", 16);
    font32 = TTF_OpenFont("arial.ttf", 32);
    font64 = TTF_OpenFont("arial.ttf", 64);

    Drawable::setFonts(font16, font32, font64);

    current = new State_Battle(window);

}

Game::~Game()
{
    TTF_CloseFont(font16);
    TTF_CloseFont(font32);
    TTF_CloseFont(font64);
    TTF_Quit();
    delete window;
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
            current->update(deltaTime);
            render();

            deltaTime = 0.0f;
        }

    }
}
void Game::handleEvent()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        window->handleEvent(&event);

        if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
        {
            quit = true;
        }

        if(event.motion.type == SDL_MOUSEMOTION)
        {
            const int mouseX = window->scaledX(event.motion.x);
            const int mouseY = window->scaledY(event.motion.y);
            current->onCursorMoved(mouseX, mouseY);
        }

        if(event.button.button == SDL_BUTTON_LEFT /*&& event.button.state == SDL_RELEASED*/)
        {
            const int mouseX = window->scaledX(event.button.x);
            const int mouseY = window->scaledY(event.button.y);
            current->onSelect(mouseX, mouseY);
        }
    }
}

void Game::render()
{
    SDL_RenderClear(window->getRenderer());
    current->draw();
    SDL_RenderPresent(window->getRenderer());
}
