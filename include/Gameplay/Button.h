#ifndef BUTTON_H
#define BUTTON_H

#include "Drawable.h"
#include "InputDevice.h"

typedef char string16[16];

class Button : public Drawable
{
public:
    Button();
    virtual ~Button();

    void setTitle(char* newTitle);

    void update(float deltaTime);

    bool buttonPressed() const;
    bool buttonReleased() const;

private:
    int buttonState;
    char* title;
};

#endif // BUTTON_H
