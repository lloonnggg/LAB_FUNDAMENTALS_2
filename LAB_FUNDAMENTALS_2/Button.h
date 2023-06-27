#pragma once
#include"Main.h"

class Button 
{
private:
    SDL_Renderer* renderer;
    std::string imagePath;
    SDL_Surface* surface;
    SDL_Texture* texture;
    int x;
    int y;
    int width;
    int height;
    bool isPressed;
public:
    Button(SDL_Renderer* renderer, const std::string& imagePath, int x, int y, int width, int height)
        : renderer(renderer), imagePath(imagePath), x(x), y(y), width(width), height(height), isPressed(false) {
        // Load the button image
        surface = IMG_Load(imagePath.c_str());
        if (surface != nullptr) {
            texture = SDL_CreateTextureFromSurface(renderer, surface);
        }
    }

    ~Button() {
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }

    void render() {
        // Render the button image
        SDL_Rect buttonRect = { x, y, width, height };
        SDL_RenderCopy(renderer, texture, nullptr, &buttonRect);
    }

    bool isMouseInside(int mouseX, int mouseY) {
        return mouseX >= x && mouseX <= (x + width) && mouseY >= y && mouseY <= (y + height);
    }

    void handleEvent(SDL_Event& e) {
        if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            isPressed = isMouseInside(mouseX, mouseY);
        }
    }

    bool isButtonPressed() const {
        return isPressed;
    }

};