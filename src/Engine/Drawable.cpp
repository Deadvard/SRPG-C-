#include "Engine/Drawable.h"

const SDL_Color Drawable::COLOR_BLACK = { 8, 8, 8, 0};
const SDL_Color Drawable::COLOR_WHITE = { 255, 255, 255, 0};
const SDL_Color Drawable::COLOR_RED = { 200, 0, 0, 0};

TTF_Font* Drawable::font16 = nullptr;
TTF_Font* Drawable::font32 = nullptr;
TTF_Font* Drawable::font64 = nullptr;

Drawable::Drawable()
{
    window = nullptr;
    texture = nullptr;
    this->width = 0;
    this->height = 0;

    positionX = 0.0f;
    positionY = 0.0f;

    renderRect.x = 0;
    renderRect.y = 0;
    renderRect.w = 0;
    renderRect.h = 0;

    textureRect.x = 0;
    textureRect.y = 0;
    textureRect.w = 0;
    textureRect.h = 0;
}

Drawable::~Drawable()
{
    if(texture)
    {
        SDL_DestroyTexture(texture);
    }
}

void Drawable::setWindow(Window* window)
{
    this->window = window;
}

void Drawable::setTexture(char* filepath)
{
    if(texture)
    {
        SDL_DestroyTexture(texture);
    }

    SDL_Surface* surface = IMG_Load(filepath);
    texture = SDL_CreateTextureFromSurface(window->getRenderer(), surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

    renderRect.w = width;
    renderRect.h = height;
    textureRect.w = width;
    textureRect.h = height;
}

void Drawable::setTexture(char* text, SDL_Color color)
{
    if(texture)
    {
        SDL_DestroyTexture(texture);
    }

    SDL_Surface* surface = TTF_RenderText_Solid(font32, text, color);
    texture = SDL_CreateTextureFromSurface(window->getRenderer(), surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

    renderRect.w = width;
    renderRect.h = height;
    textureRect.w = width;
    textureRect.h = height;
}

int Drawable::getHeight()
{
    return height;
}

int Drawable::getWidth()
{
    return width;
}

void Drawable::setRenderPosition(float x, float y)
{
    positionX = x;
    positionY = y;
    renderRect.x = x;
    renderRect.y = y;
}

void Drawable::setRenderSize(int w, int h)
{
    renderRect.w = w;
    renderRect.h = h;
}

void Drawable::setTexturePosition(int x, int y)
{
    textureRect.x = x;
    textureRect.y = y;
}

void Drawable::setTextureSize(int w, int h)
{
    textureRect.w = w;
    textureRect.h = h;
}

float Drawable::getRenderX() const
{
    return positionX;
}

float Drawable::getRenderY() const
{
    return positionY;
}

int Drawable::getRenderW() const
{
    return renderRect.w;
}

int Drawable::getRenderH() const
{
    return renderRect.h;
}

int Drawable::getTextureX() const
{
    return textureRect.x;
}

int Drawable::getTextureY() const
{
    return textureRect.y;
}

int Drawable::getTextureW() const
{
    return textureRect.w;
}

int Drawable::getTextureH() const
{
    return textureRect.h;
}

bool Drawable::contains(int x, int y)
{
    return x > renderRect.x && y > renderRect.y && x < (renderRect.x + renderRect.w) && y < (renderRect.y + renderRect.h);
}

void Drawable::draw()
{
    SDL_Rect positionRect;
    positionRect.x = positionX + window->getRenderX();
    positionRect.y = positionY + window->getRenderY();
    positionRect.w = renderRect.w;
    positionRect.h = renderRect.h;

    /*if(renderRect.w >= window->getRenderX() && renderRect.h >= window->getRenderY()
       && renderRect.x <= window->getRenderW() && renderRect.y <= window->getRenderH())
    {*/
        SDL_RenderCopy(window->getRenderer(), texture, &textureRect, &positionRect);
    /*}*/
}

void Drawable::setFonts(TTF_Font* font16, TTF_Font* font32, TTF_Font* font64)
{
        Drawable::font16 = font16;
        Drawable::font32 = font32;
        Drawable::font64 = font64;
}
