#pragma once
#include"Main.h"
#include"Player.h"
#include"Hazard.h"

class Game
{
private:
	int ScreenWidth = 800;
	int ScreenHeight = 600;
	SDL_Window* window;
	SDL_Renderer* renderer;
    Player* player;
    vector<Hazard*> hazards;
public:
    Game();
    ~Game();

    SDL_Texture* loadImage(const std::string& filename);
    Mix_Music* loadMusic(const std::string& filename);
    Mix_Chunk* loadSoundEffect(const std::string& filename);

    void RunGameLoop();
    void Update();
    void Render();
};