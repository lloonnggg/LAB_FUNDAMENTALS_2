#include"Player.h"

void Player::HandlePlayerInput(SDL_Keycode key)
{
	if (key == SDLK_w)
	{
		PlayerY -= PlayerVel;
	}
	else if (key == SDLK_s)
	{
		PlayerY += PlayerVel;
	}

	if (key == SDLK_a)
	{
		PlayerX -= PlayerVel;
	}
	else if (key == SDLK_d)
	{
		PlayerX += PlayerVel;
	}

	if (key == SDLK_SPACE)
	{
		Shoot = true;
	}
}