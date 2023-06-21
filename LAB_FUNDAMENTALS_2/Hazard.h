#pragma once
#include"Main.h"

class Hazard
{
private:
	int HazardX;
	int HazardY;
	int HazardW;
	int HazardH;
public:
	Hazard(int HX, int HY, int HW, int HH)
	{
		HazardX = HX;
		HazardY = HY;
		HazardW = HW;
		HazardH = HH;
	}
};