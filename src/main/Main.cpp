#include <game.h>

Game* game = nullptr;

float delta;
int a = SDL_GetTicks();
int b = SDL_GetTicks();

int main(int argc, char* argv[]) {
	game = new Game();

	game->init("How to basically cook", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running()) {
		a = SDL_GetTicks();
		delta += a - b;

		if (delta > 100000 / 61.0) {

			b = a;

			game->handleEvents();
			game->update();
			game->render(delta);

			delta = 0;

		}
		
	}

	game->clean();

	return 0;
}