#include "game.hpp"
#include <src/ent/base/base.hpp>
#include <src/util/imageloader/imageloader.hpp>
#include <string>

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;

	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		TTF_Init();
		std::cout << "Subsystems Initialised" << "\n";

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window created" << "\n";
		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			std::cout << "Renderer created" << "\n";
		}

		isRunning = true;

	}
	else {
		isRunning = false;
	}	

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
			break;
		
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
				leftclick = true;
			if (event.button.button == SDL_BUTTON_RIGHT)
				rightclick = true;
			break;
		
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
				leftclick = false;
			if (event.button.button == SDL_BUTTON_RIGHT)
				rightclick = false;
			break;

		default:
			break;
	}
}

void Game::update(float delta) {
	
	//do update stuff

}

void Game::render(float delta) {
	float fps = 100000 / delta;
	SDL_RenderClear(renderer);

	//render things

	SDL_RenderPresent(renderer);

}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Cleaned" << "\n";
}
