#pragma once
#include"Main.h"
#include"Player.h"
#include"AssetsManager.h"
#include"Hazard.h"
#include"Threats.h"

//Abstract class
class State 
{
public:
    virtual void handleInput(SDL_Event e) = 0;
    virtual void update() = 0;
    virtual void render(SDL_Renderer* renderer) = 0;
    virtual void changestate() = 0;
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
    void handleInput(SDL_Event e) override;
    void update() override;
    void render(SDL_Renderer* renderer) override;
    void changestate() override;
};

class GameState : public State 
{
public:
    Assets* assets;
    Player* player;
    Hazard* hazard[2];
    int maxHazards = 2;
    Mobs* mob[5];
    int maxMobs = 5;
    Boss* boss;
public:
    GameState()
    {
        assets = new Assets();
        player = new Player(ScreenWidth / 2, ScreenHeight * 3 / 4, 50, 50, 7, 5);

        //hazards and mobs generator
        for (int i = 0; i < maxHazards; i++)
        {
            hazard[i] = new Hazard();
            hazard[i]->HazardCoordinateGenerator(i);
            hazard[i]->HazardW = 50;
            hazard[i]->HazardH = 50;
        }
        for (int i = 0; i < maxMobs; i++)
        {
            mob[i] = new Mobs();
            mob[i]->MobCoordinateGenerator(i);
            mob[i]->MobW = 30;
            mob[i]->MobH = 30;
        }
    }
    void handleInput(SDL_Event e) override;
    void update() override;
    void render(SDL_Renderer* renderer) override;
    void changestate() override;
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
    void handleInput(SDL_Event e) override;
    void update() override;
    void render(SDL_Renderer* renderer) override;
    void changestate() override;
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
    void handleInput(SDL_Event e) override;
    void update() override;
    void render(SDL_Renderer* renderer) override;
    void changestate() override;
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
    void handleInput(SDL_Event e) override;
    void update() override;
    void render(SDL_Renderer* renderer) override;
    void changestate() override;
};

class StateMachine
{
public:
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