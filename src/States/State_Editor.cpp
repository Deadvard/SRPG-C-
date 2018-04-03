#include "State_Editor.h"

State_Editor::State_Editor(Window* window)
    :State_Base(window)
{
    background.setWindow(window);
    background.setTexture("Editor_BG.png");
    background.setRenderSize(1280,720);
}

State_Editor::~State_Editor()
{
    //dtor
}

void State_Editor::update(float deltaTime, Input* input)
{

}

void State_Editor::draw()
{
    background.draw();
}
