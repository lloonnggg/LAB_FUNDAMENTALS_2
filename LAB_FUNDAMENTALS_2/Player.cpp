#include"Player.h"

void Player::HandlePlayerInput(SDL_Scancode key)
{
	switch (key)
	{
	case SDLK_w:
	{
		PlayerY -= PlayerVel;
	}
	break;
	case SDLK_a:
	{
		PlayerX -= PlayerVel;
	}
	break;
	case SDLK_s:
	{
		PlayerY += PlayerVel;
	}
	break;
	case SDLK_d:
	{
		PlayerX += PlayerVel;
	}
	break;
	}
}