#include "game.h"
#include <baseobject.h>

Thing* bg;
Thing* bowl;
Thing* egg;
Thing* butter;

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialised" << "\n";

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window created" << "\n";
		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << "\n";
		}

		isRunning = true;

	}
	else {
		isRunning = false;
	}
	bg = new Thing("res/background/kitchen.png", renderer, 0, 0, 800, 600);
	bowl = new Thing("res/items/bowl.png", renderer, 0, 0, 800, 600);
	egg = new Thing("res/ingredients/egg.png", renderer, (800 / 4) * 3, (600 / 3) * 2, 42, 55);
	butter = new Thing("res/ingredients/butter.png", renderer, (800 / 4), (600 / 3) * 2, 100, 25);
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;

		case SDL_MOUSEMOTION:
			SDL_GetMouseState(&mousex, &mousey);

		default:
			break;
	}
}

void Game::update() {
	bg->Update();
	bowl->Update();
	egg->Update();
	butter->Update();
}

void Game::render() {
	SDL_RenderClear(renderer);

	bg->Render(renderer);
	bowl->Render(renderer);
	egg->Render(renderer);
	butter->Render(renderer);

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Cleaned" << "\n";
}
