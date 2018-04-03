#include "Text.h"

Texture::Texture()
{
    //ctor
}

Texture::~Texture()
{
    if(sdltexture)
    {
        SDL_DestroyTexture(texture);
    }
}

int Texture::getWidth() const
{
    return width;
}

int Texture::getHeight() const
{
    return height;
}

SDL_Texture* Texture::getTexture() const
{
    return sdltexture;
}

void Texture::setTexture(char* filepath, SDL_Renderer* renderer)
{
    if(sdltexture)
    {
        SDL_DestroyTexture(sdltexture);
    }

    SDL_Surface* surface = IMG_Load(filepath);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
}

void Texture::setFont(char* filepath, int fontSize, SDL_Renderer* renderer)
{
    if(sdltexture)
    {
        SDL_DestroyTexture(sdltexture);
    }

    SDL_Surface* surface = TTF_OpenFont(filepath, 24);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
}
