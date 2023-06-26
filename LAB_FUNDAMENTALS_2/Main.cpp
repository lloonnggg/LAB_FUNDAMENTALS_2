#include"Main.h"
#include"GameEngine.h"

int main(int argc, char* argv[])
{
	Game* game = new Game();
	game->RunGameLoop();
	return 0;
}