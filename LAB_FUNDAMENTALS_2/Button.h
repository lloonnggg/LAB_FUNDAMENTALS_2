#pragma once
#include"Main.h"

class Button {
private:
    SDL_Rect rect; // Rectangle representing the size and position of the button
    SDL_Surface* normalState; // Surface for the normal state of the button
    SDL_Surface* hoverState; // Surface for the hover state of the button
    SDL_Surface* activeState; // Surface for the active state of the button
    bool isHovered = false; // Flag to indicate if the button is currently being hovered over
    bool isActive = false; // Flag to indicate if the button is currently active (pressed)

public:
    // Constructor for Button class that initializes button with position, size and image paths for the three states
    Button(int x, int y, int w, int h, const std::string& normalImagePath, const std::string& hoverImagePath, const std::string& activeImagePath);

    // Destructor for Button class that will free the surfaces when button object is destroyed
    ~Button();

    // Handle event function that takes an SDL_Event as input and updates the button state accordingly
    void handleEvent(SDL_Event* e);

    // Render function that takes an SDL_Surface as input and draws the button on it depending on the button state
    void render(SDL_Surface* display);
};