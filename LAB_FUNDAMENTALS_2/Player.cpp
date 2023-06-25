#include"Player.h"

void Player::HandlePlayerInput()
{
	if (KeyDown(SDL_SCANCODE_W))
	{
		PlayerY -= PlayerVel;
	}
	else if (KeyDown(SDL_SCANCODE_S))
	{
		PlayerY += PlayerVel;
	}

	if (KeyDown(SDL_SCANCODE_A))
	{
		PlayerX -= PlayerVel;
	}
	else if (KeyDown(SDL_SCANCODE_D))
	{
		PlayerX += PlayerVel;
	}

	if (KeyDown(SDL_SCANCODE_SPACE))
	{
		Shoot = true;
	}
}