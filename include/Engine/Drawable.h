#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "Window.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Drawable
{
public:
    Drawable();
    virtual ~Drawable();

    void setWindow(Window* window);

    void setTexture(char* filepath);
    void setTexture(char* text, SDL_Color color);

    int getHeight();
    int getWidth();

    void setRenderPosition(float x, float y);
    void setRenderSize(int w, int h);

    void setTexturePosition(int x, int y);
    void setTextureSize(int w, int h);

    float getRenderX() const;
    float getRenderY() const;
    int getRenderW() const;
    int getRenderH() const;

    int getTextureX() const;
    int getTextureY() const;
    int getTextureW() const;
    int getTextureH() const;

    bool contains(int x, int y);

    virtual void draw();

    static void setFonts(TTF_Font* font16, TTF_Font* font32, TTF_Font* font64);

    const static SDL_Color COLOR_BLACK;
    const static SDL_Color COLOR_WHITE;
    const static SDL_Color COLOR_RED;

private:
    static TTF_Font* font16;
    static TTF_Font* font32;
    static TTF_Font* font64;

    Window* window;
    SDL_Texture* texture;
    float positionX;
    float positionY;
    SDL_Rect renderRect;
    SDL_Rect textureRect;

    int width;
    int height;
};

#endif // DRAWABLE_H
