#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

class Window
{
public:
    Window();
    virtual ~Window();

    void handleEvent(SDL_Event* event);

    void setFullscreen(int mode);
    void resizeWindow();
    void setWindow(SDL_Window* sdlwindow);
    void setRenderer(SDL_Renderer* renderer);
    void setRenderPosition(int x, int y);
    void setRenderSize(int w, int h);

    int scaledX(int x);
    int scaledY(int y);

    SDL_Window* getWindow() const;
    SDL_Renderer* getRenderer() const;
    SDL_Rect& getViewport();
    int getWindowW() const;
    int getWindowH() const;
    int getRenderX() const;
    int getRenderY() const;
    int getRenderW() const;
    int getRenderH() const;

    void moveView(int x, int y);

private:
    SDL_Window* sdlwindow;
    SDL_Renderer* renderer;
    int windowWidth;
    int windowHeight;
    int renderWidth;
    int renderHeight;
    int renderX;
    int renderY;
};

#endif // WINDOW_H
