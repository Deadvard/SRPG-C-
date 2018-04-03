#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


class Texture
{
public:
    Texture();
    virtual ~Texture();

    int getWidth() const;
    int getHeight() const;
    SDL_Texture* getTexture() const;

    virtual void setTexture(char* filepath, SDL_Renderer* renderer);
    virtual void setFont(char* filepath, int fontSize, SDL_Renderer* renderer);

private:
    SDL_Texture* sdltexture;
    int width;
    int height;
};

#endif // TEXTURE_H
