#pragma once
#include"Main.h"
#include"State.h"

class Game
{
private:
	int ScreenWidth = 800;
	int ScreenHeight = 600;
	SDL_Window* window;
	SDL_Renderer* renderer;

    TitleState titlestate;
    GameState gamestate;
    PauseState pausestate;
    WinState winstate;
    LoseState losestate;
    StateMachine stateMachine;
public:
    Game();

    void RunGameLoop();
    void Update(SDL_Event event);
    void Render();
};