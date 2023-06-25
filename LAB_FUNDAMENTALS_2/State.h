#pragma once
// Include the necessary SDL header files
#include <SDL.h>

class State 
{
public:
    virtual void handleInput(SDL_Event& e) = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual ~State() {}
};

class TitleState : public State 
{
public:
    void handleInput(SDL_Event& e) override;
    void update() override;
    void render() override;
};

class GameState : public State 
{
public:
    void handleInput(SDL_Event& e) override;
    void update() override;
    void render() override;
};

class PauseState : public State 
{
public:
    void handleInput(SDL_Event& e) override;
    void update() override;
    void render() override;
};

class LoseState : public State 
{
public:
    void handleInput(SDL_Event& e) override;
    void update() override;
    void render() override;
};

class WinState : public State 
{
public:
    void handleInput(SDL_Event& e) override;
    void update() override;
    void render() override;
};

class StateMachine
{
private:
    State* currentState;
    TitleState titleState;
    GameState gameState;
    PauseState pauseState;
    LoseState loseState;
    WinState winState;

public:
    StateMachine() : currentState(nullptr) {}

    void changeState(State* state)
    {
        currentState = state;
    }

    void handleInput(SDL_Event& e)
    {
        currentState->handleInput(e);
    }

    void update()
    {
        currentState->update();
    }

    void render()
    {
        currentState->render();
    }
};