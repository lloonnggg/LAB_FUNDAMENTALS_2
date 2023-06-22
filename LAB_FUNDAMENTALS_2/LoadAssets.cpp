#include"Game.h"

void Game::LoadTexture()
{
	assets->Background = assets->loadImage(assets->BackgroundIMG, renderer);
	assets->Player = assets->loadImage(assets->PlayerIMG, renderer);
	assets->Enemy = assets->loadImage(assets->EnemyIMG, renderer);
	assets->Hazard = assets->loadImage(assets->HazardIMG, renderer);
}

void Game::LoadSoundEffect()
{

}

void Game::LoadMusic()
{

}