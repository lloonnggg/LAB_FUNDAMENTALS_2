#include "Button.h"

// Constructor - Initializes button with given position, size and image paths for the three states
Button::Button(int x, int y, int w, int h, const std::string& normalImagePath, const std::string& hoverImagePath, const std::string& activeImagePath) {
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    // Load images for each state of the button
    normalState = SDL_LoadBMP(normalImagePath.c_str());
    hoverState = SDL_LoadBMP(hoverImagePath.c_str());
    activeState = SDL_LoadBMP(activeImagePath.c_str());
}

// Destructor - Frees the surfaces when the button object is destroyed
Button::~Button() {
    SDL_FreeSurface(normalState);
    SDL_FreeSurface(hoverState);
    SDL_FreeSurface(activeState);
}

// Handles events such as mouse motion, button press, and button release to update button state
void Button::handleEvent(SDL_Event* e) {
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP) {
        int x, y;
        // Get the current mouse position
        SDL_GetMouseState(&x, &y);

        bool wasHovered = isHovered;
        // Check if the mouse is over the button
        isHovered = (x >= rect.x && x < rect.x + rect.w && y >= rect.y && y < rect.y + rect.h);

        // Check if the button was just pressed
        if (!wasHovered && isHovered && e->type == SDL_MOUSEBUTTONDOWN) {
            isActive = true;
        }
        // Check if the button was just released
        else if (wasHovered && isHovered && e->type == SDL_MOUSEBUTTONUP) {
            if (isActive) {
                // If the button was active, then it was clicked. Handle click event here.
            }
            isActive = false;
        }
        // Check if the mouse just left the button
        else if (wasHovered && !isHovered) {
            isActive = false;
        }
    }
}

// Render the button on the display surface
void Button::render(SDL_Surface* display) {
    SDL_Surface* currentState = normalState; // The surface for the current state of the button
    if (isActive) {
        currentState = activeState;
    }
    else if (isHovered) {
        currentState = hoverState;
    }
    // Draw the current state of the button on the display surface
    SDL_BlitSurface(currentState, NULL, display, &rect);
}