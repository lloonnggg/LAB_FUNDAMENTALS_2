#pragma once
#include"Main.h"
#include"State.h"
#include"AssetsManager.h"
#include"Button.h"

class Game
{
private:
	int ScreenWidth = 800;
	int ScreenHeight = 600;
	SDL_Window* window;
	SDL_Renderer* renderer;
    Assets* assets;
    
    StateMachine stateMachine;
    UIButton titleButton;
public:
    Game();

    void RunGameLoop();
    void Update(SDL_Event event);
    void Render();
};