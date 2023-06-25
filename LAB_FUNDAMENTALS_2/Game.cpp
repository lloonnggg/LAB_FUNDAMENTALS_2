#include"Game.h"

Game::Game()
{
    // Initialize SDL and create window/renderer
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenWidth, ScreenHeight, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // Create States:
    //titlestate = new TitleState();
    //gamestate = new GameState();
    //pausestate = new PauseState();
    //winstate = new WinState();
    //losestate = new LoseState();
    //stateMachine = new StateMachine();

    // Create hazards
    
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

}

void Game::Render()
{
    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    stateMachine.changeState(&gamestate);
    stateMachine.render(renderer);

    SDL_RenderPresent(renderer);
}