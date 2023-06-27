#pragma once
#include"Main.h"

class UIButton 
{
public:
    int x;
    int y;
    int w;
    int h;
    bool isPressed;
public:
    UIButton(){}

    bool isMouseInside(int mouseX, int mouseY) const 
    {
        return mouseX >= x && mouseX <= (x + w) && mouseY >= y && mouseY <= (y + h);
    }
    bool isButtonPressed() const 
    {
        return isPressed;
    }

    void handleEvent(SDL_Event& e) 
    {
        if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) 
        {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            if (isMouseInside(mouseX, mouseY)) 
            {
                isPressed = true;
            }
        }
    }
};



