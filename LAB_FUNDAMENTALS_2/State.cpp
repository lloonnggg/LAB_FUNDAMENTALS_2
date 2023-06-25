#include "state.h"

//--------------------------------------------------------TITLE STATE--------------------------------------------------------
void TitleState::handleInput(SDL_Event& e) 
{
    // Implement input handling for Start Game button
}
void TitleState::update() 
{
    // Implement any necessary updates, if any
}
void TitleState::render(SDL_Renderer* renderer)
{
    assets->LoadTexture(renderer);
    SDL_RenderCopy(renderer, assets->Background, NULL, NULL);
}
//--------------------------------------------------------TITLE STATE--------------------------------------------------------



//--------------------------------------------------------GAME STATE--------------------------------------------------------
void GameState::handleInput(SDL_Event& e) 
{
    player->HandlePlayerInput();
}
void GameState::update() 
{
    // Update game entities
}
void GameState::render(SDL_Renderer* renderer) 
{
    assets->LoadTexture(renderer);
    SDL_RenderCopy(renderer, assets->Background, NULL, NULL);
    SDL_RenderCopy(renderer, assets->Player, NULL, assets->PlayerRect);
    SDL_RenderCopy(renderer, assets->PlayerBullet, NULL, assets->PlayerBulletRect);
}
//--------------------------------------------------------GAME STATE--------------------------------------------------------



//--------------------------------------------------------PAUSE STATE--------------------------------------------------------
void PauseState::handleInput(SDL_Event& e) 
{
    // Implement input handling for Resume button
}
void PauseState::update() 
{
    // No game updates when the game is paused
}
void PauseState::render(SDL_Renderer* renderer)
{
    // Render a transparent rectangle over the game state and a Resume button
}
//--------------------------------------------------------PAUSE STATE--------------------------------------------------------



//--------------------------------------------------------LOSE STATE--------------------------------------------------------
void LoseState::handleInput(SDL_Event& e) 
{
    // Implement input handling for Main Menu button
}
void LoseState::update() 
{
    // Implement any necessary updates, if any
}
void LoseState::render(SDL_Renderer* renderer)
{
    // Render anything you want but keep it clean
}
//--------------------------------------------------------LOSE STATE--------------------------------------------------------



//--------------------------------------------------------WIN STATE--------------------------------------------------------
void WinState::handleInput(SDL_Event& e) 
{
    // Implement input handling for Main Menu button
}
void WinState::update() 
{
    // Implement any necessary updates, if any
}
void WinState::render(SDL_Renderer* renderer)
{
    // Render anything you want but keep it clean
}
//--------------------------------------------------------WIN STATE--------------------------------------------------------