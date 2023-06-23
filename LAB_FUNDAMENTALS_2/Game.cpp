#include"Game.h"

Game::Game()
{
    // Initialize SDL and create window/renderer
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenWidth, ScreenHeight, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // Create object
    player = new Player(0, 0, 50, 50, 7, 5);
    playerbullet = new PlayerBullet(0, 0, 20, 30, 10);
    assets = new Assets();

    // Create hazards
    hazards.push_back(new Hazard(100, 100, 20, 20));
    hazards.push_back(new Hazard(200, 200, 30, 30));
}

Game::~Game()
{
    // Clean up player object
    delete player;

    // Clean up hazards
    for (Hazard* hazard : hazards)
        delete hazard;

    // Clean up SDL resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::RunGameLoop()
{
    bool quit = false;
    while (!quit)
    {
        // Handle events
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                quit = true;
        }
    
        // Update game state
        Update(event);
    
        // Render game objects
        Render();
    }
}

void Game::Update(SDL_Event event)
{
    // Update player
    if (event.type == SDL_KEYDOWN)
    {
        player->HandlePlayerInput(event.key.keysym.sym);
    }
    assets->PlayerRect->x = player->PlayerX;
    assets->PlayerRect->y = player->PlayerY;
    assets->PlayerRect->w = player->PlayerW;
    assets->PlayerRect->h = player->PlayerH;

    // Update hazards
}

void Game::Render()
{
    assets->LoadTexture(renderer);
    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, assets->Background, NULL, NULL);
    SDL_RenderCopy(renderer, assets->Player, NULL, assets->PlayerRect);
    SDL_RenderCopy(renderer, assets->PlayerBullet, NULL, NULL);
    // Render player

    // Render hazards

    // Present the rendered frame
    SDL_RenderPresent(renderer);
}