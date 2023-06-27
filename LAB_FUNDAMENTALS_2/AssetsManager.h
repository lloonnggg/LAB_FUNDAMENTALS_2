#pragma once
#include"Main.h"

class Assets
{
public:
    string PlayerIMG = "./Asset/player.png";
    string PlayerBulletIMG = "./Asset/player_bullet.png";
    string PlayerHpIMG = "./Asset/PlayerHP.jpg";
    string HazardIMG = "./Asset/obstacle.png";
    string EnemyIMG = "./Asset/enemy.png";
    string EnemyBulletIMG = "./Asset/enemy_bullet.png";
    string BossIMG = "./Asset/boss.png";
    string BossBulletIMG = "./Asset/boss_bullet.png";

    string StopScreenIMG = "./Asset/stopscreen.png";
    string BackgroundIMG = "./Asset/background.png";
    string GameNameIMG = "./Asset/GameName.png";
    string GameOverIMG = "./Asset/gameover.jpg";
    string YouWinIMG = "./Asset/youwin.jpg";
    string GetReadyIMG = "./Asset/getready.png";
    string Number3IMG = "./Asset/number 3.png";
    string Number2IMG = "./Asset/number 2.png";
    string Number1IMG = "./Asset/number 1.png";


    
    SDL_Texture* Player = nullptr;
    SDL_Texture* PlayerBullet = nullptr;
    SDL_Texture* PlayerHp = nullptr;
    SDL_Texture* Hazard = nullptr;
    SDL_Texture* Enemy = nullptr;
    SDL_Texture* EnemyBullet = nullptr;
    SDL_Texture* Boss = nullptr;
    SDL_Texture* BossBullet = nullptr;

    SDL_Texture* StopScreen = nullptr;
    SDL_Texture* GameName = nullptr;
    SDL_Texture* GameOver = nullptr;
    SDL_Texture* YouWin = nullptr;
    SDL_Texture* GetReady = nullptr;
    SDL_Texture* Number3 = nullptr;
    SDL_Texture* Number2 = nullptr;
    SDL_Texture* Number1 = nullptr;



    SDL_Rect* PlayerRect = new SDL_Rect();
    SDL_Rect* PlayerBulletRect = new SDL_Rect();
    SDL_Rect* PlayerHpRect = new SDL_Rect();
    SDL_Rect* HazardRect = new SDL_Rect();
    SDL_Rect* EnemyRect = new SDL_Rect();
    SDL_Rect* EnemyBulletRect = new SDL_Rect();
    SDL_Rect* BossRect = new SDL_Rect();
    SDL_Rect* BossBulletRect = new SDL_Rect();

    SDL_Rect* GameNameRect = new SDL_Rect();
    SDL_Rect* GameOverRect = new SDL_Rect();
    SDL_Rect* YouWinRect = new SDL_Rect();
    SDL_Rect* GetReadyRect = new SDL_Rect();
    SDL_Rect* Number3Rect = new SDL_Rect();
    SDL_Rect* Number2Rect = new SDL_Rect();
    SDL_Rect* Number1Rect = new SDL_Rect();

public:
    Assets(){}

    void ScrollingBG(SDL_Renderer* renderer,string background)
    {
        SDL_Surface* imageSurface = IMG_Load(background.c_str());
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
        scrollPos -= SCROLL_SPEED;
        if (scrollPos <= 0)
        {
            scrollPos = BackgroundHeight - 800;
        }
        SDL_Rect sourceRect = { 0, scrollPos, ScreenWidth, ScreenHeight };
        SDL_Rect destRect = { 0, 0, ScreenWidth, ScreenHeight };
        SDL_RenderCopy(renderer, texture, &sourceRect, &destRect);
    }

    SDL_Texture* loadImage(const string& filename, SDL_Renderer* renderer)
    {
        SDL_Surface* surface = IMG_Load(filename.c_str());
        if (surface == nullptr)
        {
            cerr << "Failed to load image: " << IMG_GetError() << endl;
            return nullptr;
        }
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        return texture;
    }
    Mix_Music* loadMusic(const string& filename)
    {
        Mix_Music* music = Mix_LoadMUS(filename.c_str());
        if (music == nullptr)
        {
            cerr << "Failed to load music: " << Mix_GetError() << endl;
            return nullptr;
        }
        return music;
    }
    Mix_Chunk* loadSoundEffect(const string& filename)
    {
        Mix_Chunk* chunk = Mix_LoadWAV(filename.c_str());
        if (chunk == nullptr)
        {
            cerr << "Failed to load sound effect: " << Mix_GetError() << endl;
            return nullptr;
        }
        return chunk;
    }

    void LoadTexture(SDL_Renderer* renderer)
    {
        Player = loadImage(PlayerIMG, renderer);
        PlayerBullet = loadImage(PlayerBulletIMG, renderer);
        PlayerHp = loadImage(PlayerHpIMG, renderer);
        Hazard = loadImage(HazardIMG, renderer);
        Enemy = loadImage(EnemyIMG, renderer);
        EnemyBullet = loadImage(EnemyBulletIMG, renderer);
        Boss = loadImage(BossIMG, renderer);
        BossBullet = loadImage(BossBulletIMG, renderer);

        StopScreen = loadImage(StopScreenIMG, renderer);
        GameName = loadImage(GameNameIMG, renderer);
        GameOver = loadImage(GameOverIMG, renderer);
        GetReady = loadImage(GetReadyIMG, renderer);
        Number3 = loadImage(Number3IMG, renderer);
        Number2 = loadImage(Number2IMG, renderer);
        Number1 = loadImage(Number1IMG, renderer);
    }

    void LoadSound()
    {

    }

    void LoadMusic()
    {

    }
};