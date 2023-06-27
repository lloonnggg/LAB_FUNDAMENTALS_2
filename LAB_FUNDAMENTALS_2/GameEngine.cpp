#include"GameEngine.h"

Game::Game()
{
    // Initialize SDL and create window/renderer
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenWidth, ScreenHeight, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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
    stateMachine.changeState(&titlestate);
    //stateMachine.changeState(&gamestate);
    //gamestate.handleInput(event);
    //stateMachine.update();

}

void Game::Render()
{
    SDL_RenderClear(renderer);

    stateMachine.changeState(&titlestate);
    titlestate.render(renderer);

    //stateMachine.changeState(&gamestate);
    //stateMachine.render(renderer);

    SDL_RenderPresent(renderer);
}