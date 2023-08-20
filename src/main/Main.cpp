#include <src/game.h>

Game* game = nullptr;

float delta;
int a = SDL_GetTicks();
int b = SDL_GetTicks();

float fpslimit = 60.0;

int main(int argc, char* argv[]) {
	game = new Game();

	game->init("A Bad Engine Creation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);

	while (game->running()) {
		a = SDL_GetTicks();
		delta += a - b;

		if (delta > 100000 / fpslimit) {

			b = a;

			game->handleEvents();
			game->update(delta);
			game->render(delta);

			delta = 0;

		}
		
	}

	game->clean();

	return 0;
}