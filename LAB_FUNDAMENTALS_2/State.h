#pragma once
#include"Main.h"
#include"Player.h"
#include"AssetsManager.h"
#include"Hazard.h"

//Abstract class
class State 
{
public:
    virtual void handleInput(SDL_Event& e) = 0;
    virtual void update() = 0;
    virtual void render(SDL_Renderer* renderer) = 0;
    virtual ~State() {}
};

//main classes
class TitleState : public State 
{
public:
    Assets* assets;
public:
    TitleState()
    {
        assets = new Assets();
    }
    void handleInput(SDL_Event& e) override;
    void update() override;
    void render(SDL_Renderer* renderer) override;
};

class GameState : public State 
{
public:
    Assets* assets;
    Player* player;
    PlayerBullet* playerbullet;
    vector<Hazard*> hazards;
public:
    GameState()
    {
        assets = new Assets();
        player = new Player(0, 0, 50, 50, 7, 5);
        playerbullet = new PlayerBullet(0, 0, 20, 30, 10);

        hazards.push_back(new Hazard(100, 100, 20, 20));
        hazards.push_back(new Hazard(200, 200, 30, 30));
    }
    void handleInput(SDL_Event& e) override;
    void update() override;
    void render(SDL_Renderer* renderer) override;
};

class PauseState : public State 
{
public:
    Assets* assets;
public:
    PauseState()
    {
        assets = new Assets();
    }
    void handleInput(SDL_Event& e) override;
    void update() override;
    void render(SDL_Renderer* renderer) override;
};

class LoseState : public State 
{
public:
    Assets* assets;
public:
    LoseState()
    {
        assets = new Assets();
    }
    void handleInput(SDL_Event& e) override;
    void update() override;
    void render(SDL_Renderer* renderer) override;
};

class WinState : public State 
{
public:
    Assets* assets;
public:
    WinState()
    {
        assets = new Assets();
    }
    void handleInput(SDL_Event& e) override;
    void update() override;
    void render(SDL_Renderer* renderer) override;
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

    void update() 
    {
        currentState->update();
    }

    void render(SDL_Renderer* renderer) 
    {
        currentState->render(renderer);
    }
};