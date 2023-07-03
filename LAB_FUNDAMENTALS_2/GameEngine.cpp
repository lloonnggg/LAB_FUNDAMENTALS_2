#include"GameEngine.h"

Game::Game()
{f
    // Initialize SDL and create window/renderer
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenWidth, ScreenHeight, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    UIButton* titleButton = new UIButton();
    Assets* assets = new Assets();
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
    
        // Update game
        Update(event);
    
        // Render game
        Render();
    }
}

void Game::Update(SDL_Event event)
{
    stateMachine.changeState(&stateMachine.gameState);
    stateMachine.update(event);  
}

void Game::Render()
{
    SDL_RenderClear(renderer);

    stateMachine.changeState(&stateMachine.gameState);
    stateMachine.render(renderer);

    SDL_RenderPresent(renderer);
}