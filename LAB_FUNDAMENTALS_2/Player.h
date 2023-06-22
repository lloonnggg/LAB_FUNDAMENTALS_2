#pragma once
#include"Main.h"

class Player
{
private:
	int PlayerX;
	int PlayerY;
	int PlayerW;
	int PlayerH;
	int PlayerVel;
public:
	Player(int PX, int PY, int PW, int PH, int PV)
	{
		PlayerX = PX;
		PlayerY = PY;
		PlayerW = PW;
		PlayerH = PH;
		PlayerVel = PV;
	}
	void HandlePlayerInput();
};