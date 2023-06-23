#pragma once
#include"Main.h"
#include"Player.h"
#include"Hazard.h"
#include"AssetsManager.h"

class Game
{
private:
	int ScreenWidth = 800;
	int ScreenHeight = 600;
	SDL_Window* window;
	SDL_Renderer* renderer;
    Player* player;
    Assets* assets;
    vector<Hazard*> hazards;
public:
    Game();
    ~Game();

    void RunGameLoop();
    void Update();
    void Render();
};