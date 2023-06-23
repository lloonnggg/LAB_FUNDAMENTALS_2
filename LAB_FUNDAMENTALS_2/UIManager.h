#pragma once
#include"Main.h"

class UIManager {
private:
    SDL_Rect healthBar;  // SDL_Rect to represent the health bar
    int currentHealth;  // Current health value
    int maxHealth;  // Maximum health value

    SDL_Rect button;  // SDL_Rect to represent the button
    SDL_Surface* buttonSurface;  // SDL_Surface to hold the button image
    SDL_Texture* buttonTexture;  // SDL_Texture created from the button surface

public:
    UIManager();  // Constructor
    ~UIManager();  // Destructor

    // Initialize the health bar with a maximum health value and position/size
    void initHealthBar(int maxHealth, int x, int y, int width, int height);

    // Update the health value
    void updateHealth(int newHealth);

    // Render the health bar on a given SDL_Renderer
    void renderHealthBar(SDL_Renderer* renderer);

    // Initialize the button with an image path and position
    void initButton(const std::string& buttonImagePath, int x, int y, SDL_Renderer* renderer);

    // Render the button on a given SDL_Renderer
    void renderButton(SDL_Renderer* renderer);

    // Check if a given point (x, y) is within the button area
    bool isButtonClicked(int x, int y);
};