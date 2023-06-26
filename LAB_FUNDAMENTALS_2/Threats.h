#pragma once
#include"Main.h"

class Mobs
{
public:
	int MobX;
	int MobY;
	int MobW;
	int MobH;
	int MobVel;
	int MobHP;
	struct EnemyBullet
	{
		int Enemy_bullet_X;
		int Enemy_bullet_Y;
		int Enemy_bullet_W = 10;
		int Enemy_bullet_H = 20;
		int Enemy_bullet_Vel = 5;
	};
	EnemyBullet Ebullet;
public:
	Mobs(){}

	void MobCoordinateGenerator(int i)
	{
		srand(time(NULL));
		int X = 0;
		int Y = 0;
		X = rand() % (ScreenWidth - 100) + 50;
		Y = (rand() % (ScreenHeight / 4 + 1)) - (ScreenHeight / 4);
		int a = 0;
		for (a = 1; a <= 5; a++)
		{
			while (abs(X - MobX) < 70 || abs(Y - MobY) < 70)
			{
				X = rand() % (ScreenWidth - 100) + 50;
				Y = (rand() % (ScreenHeight / 4 + 1)) - (ScreenHeight / 4);
			}
		}
		MobX = X;
		MobY = Y;
	}
};

class Boss
{
public:
	int BossX;
	int BossY;
	int BossW;
	int BossH;
	int BossVel;
	int BossHP;
	struct BossBullet
	{
		int Boss_bullet_X;
		int Boss_bullet_Y;
		int Boss_bullet_W = 50;
		int Boss_bullet_H = 20;
		int Boss_bullet_Vel;
	};
	BossBullet Bbullet;
public:
	Boss(int bX, int bY, int bW, int bH, int bVel, int bHP)
	{
		BossX = bX;
		BossY = bY;
		BossW = bW;
		BossH = bH;
		BossVel = bVel;
		BossHP = bHP;
	}
};