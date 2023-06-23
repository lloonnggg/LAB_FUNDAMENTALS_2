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
	bool Shoot = false;
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
	void HandlePlayerInput(SDL_Keycode key);
};


class PlayerBullet
{
public:
	int Player_bullet_X;
	int Player_bullet_Y;
	int Player_bullet_W;
	int Player_bullet_H;
	int Player_bullet_Vel;
public:
	PlayerBullet(int PBX, int PBY, int PBW, int PBH, int PBV)
	{
		Player_bullet_X = PBX;
		Player_bullet_Y = PBY;
		Player_bullet_W = PBW;
		Player_bullet_H = PBH;
		Player_bullet_Vel = PBV;
	}
};