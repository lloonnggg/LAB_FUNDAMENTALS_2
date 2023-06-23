#pragma once
#include"Main.h"

class Assets
{
public:
    string BackgroundIMG = "./Asset/stopscreen.png";
    string PlayerIMG = "./Asset/player.png";
    string HazardIMG = "./Asset/obstacle.png";
    string EnemyIMG = "./Asset/enemy.png";
    string BossIMG = "./Asset/boss.png";
    SDL_Texture* Background = nullptr;
    SDL_Texture* Player = nullptr;
    SDL_Texture* Hazard = nullptr;
    SDL_Texture* Enemy = nullptr;
    SDL_Texture* Boss = nullptr;
    SDL_Rect PlayerRect;
    SDL_Rect HazardRect;
    SDL_Rect EnemyRect;
    SDL_Rect BossRect;
    
    string PlayerBulletIMG = "C./Asset/player.png";
    string EnemyBulletIMG = "./Asset/enemy.png";
    string BossBulletIMG = "./Asset/boss.png";
    SDL_Texture* PlayerBullet = nullptr;
    SDL_Texture* EnemyBullet = nullptr;
    SDL_Texture* BossBullet = nullptr;
    SDL_Rect PlayerBulletRect;
    SDL_Rect EnemyBulletRect;
    SDL_Rect BossBulletRect;
public:
    Assets(){}
    ~Assets()
    {
        SDL_DestroyTexture(Background);
        SDL_DestroyTexture(Player);
        SDL_DestroyTexture(Hazard);
        SDL_DestroyTexture(Enemy);
        SDL_DestroyTexture(Boss);
        SDL_DestroyTexture(PlayerBullet);
        SDL_DestroyTexture(EnemyBullet);
        SDL_DestroyTexture(BossBullet);
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
        Background = loadImage(BackgroundIMG, renderer);
        Player = loadImage(PlayerIMG, renderer);
        Enemy = loadImage(EnemyIMG, renderer);
        Hazard = loadImage(HazardIMG, renderer);
        Boss = loadImage(BossIMG, renderer);

        PlayerBullet = loadImage(PlayerBulletIMG, renderer);
        EnemyBullet = loadImage(EnemyBulletIMG, renderer);
        BossBullet = loadImage(BossBulletIMG, renderer);
    }

    void LoadSound()
    {

    }

    void LoadMusic()
    {

    }
};