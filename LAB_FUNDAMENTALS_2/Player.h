#pragma once
#include"Main.h"

class Player
{
private:
	int PlayerX;
	int PlayerY;
	int PlayerW;
	int PlayerH;
public:
	Player(int PX, int PY, int PW, int PH)
	{
		PlayerX = PX;
		PlayerY = PY;
		PlayerW = PW;
		PlayerH = PH;
	}
	void HandlePlayerInput();
};