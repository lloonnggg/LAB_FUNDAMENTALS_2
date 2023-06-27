#pragma once
#include"Main.h"

class Player
{
public:
	int PlayerX;
	int PlayerY;
	int PlayerW;
	int PlayerH;
	int PlayerVel;
	int PlayerHP;
	struct PlayerBullet
	{
		int Player_bullet_X;
		int Player_bullet_Y;
		int Player_bullet_W = 10;
		int Player_bullet_H = 30;
		int Player_bullet_Vel = 15;
	};
	PlayerBullet Pbullet;
public:
	Player(int PX, int PY, int PW, int PH, int PV, int PHp)
	{
		PlayerX = PX;
		PlayerY = PY;
		PlayerW = PW;
		PlayerH = PH;
		PlayerVel = PV;
		PlayerHP = PHp;
	}
	void GetBulletCoordinate()
	{
		Pbullet.Player_bullet_X = PlayerX + PlayerW / 2 - Pbullet.Player_bullet_W / 2;
		Pbullet.Player_bullet_Y = PlayerY - Pbullet.Player_bullet_H;
	}
	void HandlePlayerInput(SDL_Event event)
	{
		if (event.type == SDL_KEYDOWN) 
		{
			const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

			if (currentKeyStates[SDL_SCANCODE_UP]) 
			{
				if (PlayerY - PlayerVel >= 0) 
				{
					PlayerY -= PlayerVel;
				}
			}
			else if (currentKeyStates[SDL_SCANCODE_DOWN]) 
			{
				if (PlayerY + PlayerVel < ScreenHeight-PlayerH) 
				{
					PlayerY += PlayerVel;
				}
			}

			if (currentKeyStates[SDL_SCANCODE_LEFT]) 
			{
				if (PlayerX - PlayerVel >= 0) 
				{
					PlayerX -= PlayerVel;
				}
			}
			else if (currentKeyStates[SDL_SCANCODE_RIGHT]) 
			{
				if (PlayerX + PlayerVel < ScreenWidth-PlayerW) 
				{
					PlayerX += PlayerVel;
				}
			}
		}
	}
};