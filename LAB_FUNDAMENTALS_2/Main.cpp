#include"Main.h"
#include"Game.h"

int main(int argc, char* argv[])
{
	Game* game = new Game();
	game->RunGameLoop();
	return 0;
}