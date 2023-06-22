#pragma once
#include"Main.h"

class Assets
{
public:
    string BackgroundIMG;
    string PlayerIMG;
    string HazardIMG;
    string EnemyIMG;

    SDL_Texture* Background = nullptr;
    SDL_Texture* Player = nullptr;
    SDL_Texture* Hazard = nullptr;
    SDL_Texture* Enemy = nullptr;
public:
    Assets(){}
    ~Assets()
    {
        SDL_DestroyTexture(Background);
        SDL_DestroyTexture(Player);
        SDL_DestroyTexture(Hazard);
        SDL_DestroyTexture(Enemy);

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
};