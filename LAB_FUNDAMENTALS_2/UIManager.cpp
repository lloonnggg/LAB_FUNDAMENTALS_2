#include "UIManager.h"

// Constructor - initializes health values and button surface/texture pointers
UIManager::UIManager() : currentHealth(0), maxHealth(0), buttonSurface(nullptr), buttonTexture(nullptr) {}

// Destructor - frees the surface and destroys the texture
UIManager::~UIManager() {
    SDL_FreeSurface(buttonSurface);
    SDL_DestroyTexture(buttonTexture);
}

// Initialize the health bar
void UIManager::initHealthBar(int maxHealth, int x, int y, int width, int height) {
    this->maxHealth = maxHealth;
    this->currentHealth = maxHealth;

    healthBar.x = x;
    healthBar.y = y;
    healthBar.w = width;
    healthBar.h = height;
}

// Update the health value
void UIManager::updateHealth(int newHealth) {
    currentHealth = newHealth;
}

// Render the health bar on a given SDL_Renderer
void UIManager::renderHealthBar(SDL_Renderer* renderer) {
    SDL_Rect currentHealthBar = healthBar;
    currentHealthBar.w = (int)((double)currentHealth / maxHealth * healthBar.w);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Set to red
    SDL_RenderFillRect(renderer, &currentHealthBar);
}

// Initialize the button with an image path and position
void UIManager::initButton(const std::string& buttonImagePath, int x, int y, SDL_Renderer* renderer) {
    buttonSurface = SDL_LoadBMP(buttonImagePath.c_str());
    buttonTexture = SDL_CreateTextureFromSurface(renderer, buttonSurface);

    SDL_QueryTexture(buttonTexture, NULL, NULL, &button.w, &button.h);

    button.x = x;
    button.y = y;
}

// Render the button on a given SDL_Renderer
void UIManager::renderButton(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, buttonTexture, NULL, &button);
}

// Check if a given point (x, y) is within the button area
bool UIManager::isButtonClicked(int x, int y) {
    return x >= button.x && x <= button.x + button.w && y >= button.y && y <= button.y + button.h;
}