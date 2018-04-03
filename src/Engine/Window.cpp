#include "Window.h"

Window::Window()
{
    windowWidth = 1280;
    windowHeight = 720;
    renderWidth = 1280;
    renderHeight = 720;
    renderX = 0;
    renderY = 0;

    sdlwindow = SDL_CreateWindow("Fire Emblem", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(sdlwindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetWindowGrab(sdlwindow, SDL_TRUE);
}

Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(sdlwindow);
}

void Window::handleEvent(SDL_Event* event)
{
    if(event->type == SDL_WINDOWEVENT)
    {
        switch(event->window.event)
        {
            case SDL_WINDOWEVENT_RESIZED:
                this->resizeWindow();
                break;
            case SDL_WINDOWEVENT_SIZE_CHANGED:
                this->resizeWindow();
                break;
            case SDL_WINDOWEVENT_MAXIMIZED:
                this->resizeWindow();
                break;
        }
    }
}

void Window::setFullscreen(int mode)
{
    switch(mode)
    {
        case 0:
            SDL_SetWindowFullscreen(sdlwindow, 0);
            break;
        case 1:
            SDL_SetWindowFullscreen(sdlwindow, SDL_WINDOW_FULLSCREEN_DESKTOP);
            break;
        case 2:
            SDL_SetWindowFullscreen(sdlwindow, SDL_WINDOW_FULLSCREEN);
            break;
    }
    this->resizeWindow();
}

void Window::resizeWindow()
{
    SDL_GetWindowSize(sdlwindow, &windowWidth, &windowHeight);
    SDL_RenderSetScale(renderer, (float)windowWidth / renderWidth, (float)windowHeight / renderHeight);
}

void Window::setWindow(SDL_Window* sdlwindow)
{
    this->sdlwindow = sdlwindow;
    SDL_GetWindowSize(sdlwindow, &windowWidth, &windowHeight);
    SDL_RenderSetScale(renderer, (float)windowWidth / renderWidth, (float)windowHeight / renderHeight);
}
void Window::setRenderer(SDL_Renderer* renderer)
{
    this->renderer = renderer;
}

void Window::setRenderPosition(int x, int y)
{
    renderX = x;
    renderY = y;
}

void Window::setRenderSize(int w, int h)
{
    renderWidth = w;
    renderHeight = h;
}

int Window::scaledX(int x)
{
    return x * ((float)renderWidth / windowWidth);
}

int Window::scaledY(int y)
{
    return y * ((float)renderHeight / windowHeight);
}

SDL_Window* Window::getWindow() const
{
    return this->sdlwindow;
}

SDL_Renderer* Window::getRenderer() const
{
    return this->renderer;
}

int Window::getWindowW() const
{
    return this->windowWidth;
}

int Window::getWindowH() const
{
    return this->windowHeight;
}

int Window::getRenderX() const
{
    return this->renderX;
}

int Window::getRenderY() const
{
    return this->renderY;
}

int Window::getRenderW() const
{
    return this->renderWidth;
}

int Window::getRenderH() const
{
    return this->renderHeight;
}

void Window::moveView(int x, int y)
{
    renderX += x;
    renderY += y;
}
