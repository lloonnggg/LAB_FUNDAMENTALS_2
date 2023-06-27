#pragma once
#include"Main.h"

class Hazard
{
public:
	int HazardX;
	int HazardY;
	int HazardW;
	int HazardH;
	int HazardVel;
public:
	Hazard(){}
    void HazardCoordinateGenerator(int i)
    {
        srand(time(NULL));
        int X = 0;
        int Y = 0;
        X = rand() % (ScreenWidth - 100) + 50;
        Y = (rand() % (ScreenHeight / 4 + 1)) - (ScreenHeight);
        int a = 0;
        for (a = 1; a <= 2; a++)
        {
            while (abs(X - HazardX) < 70 || abs(Y - HazardY) < 70)
            {
                X = rand() % (ScreenWidth - 100) + 50;
                Y = (rand() % (ScreenHeight / 4 + 1)) - (ScreenHeight);
            }
        }
        HazardX = X;
        HazardY = Y;
    }
};