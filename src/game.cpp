#include "game.h"
#include <src/ent/base/base.h>
#include <src/util/imageloader/imageloader.h>
#include <string>
#include <src/util/debug/debug.h>
#include <src/ent/ui/button/button.h>

DebugMenu* debug;

Button* testbutton;

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
		
		debug = new DebugMenu(renderer);
		testbutton = new Button("res/ui/testbutton.png", renderer, 100, 100, 200, 50);

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

	case SDL_KEYDOWN:
		keyboard[event.key.keysym.sym] = true;
		break;

	case SDL_KEYUP:
		keyboard[event.key.keysym.sym] = false;
		break;

		default:
			break;
	}
}

void Game::update(float delta) {
	float fps = 100000 / delta;
	
	//render things
	testbutton -> Update(mousex, mousey, leftclick);

	debug -> Update(fps);

	if (keyboard[SDLK_ESCAPE]) {
		isRunning = false;
	}

}

void Game::render(float delta) {
	float fps = 100000 / delta;
	SDL_RenderClear(renderer);

	//render things
	testbutton -> Render(renderer);

	if (keyboard[SDLK_TAB]) {
		debug->Render(renderer);
	}

	SDL_RenderPresent(renderer);

}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Cleaned" << "\n";
}
