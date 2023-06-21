#include"Main.h"
#include"Game.h"

int main(int argc, char* argv[])
{
	Game* game = new Game();
	game->RunGameLoop();
	SDL_Delay(1000);
	return 0;
}