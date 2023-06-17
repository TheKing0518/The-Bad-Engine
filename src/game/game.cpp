#include "game.h"
#include <baseobject.h>
#include <ingredient.h>
#include <imageloader.h>
#include <string>

Thing* bg;
Thing* bowl;
Ingredient* egg;
Ingredient* butter;

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
	bg = new Thing("res/background/kitchen.png", renderer, 0, 0);
	bowl = new Thing("res/items/bowl.png", renderer, 0, 0);
	egg = new Ingredient("res/ingredients/egg.png", renderer, (800 / 4) * 3, (600 / 3) * 2, 0.333, 50.0);
	butter = new Ingredient("res/ingredients/butter.png", renderer, (800 / 4), (600 / 3) * 2, 2, 50.0);

	
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

void Game::update() {
	bg->Update();
	bowl->Update();
	egg->Update(mousex, mousey, leftclick);
	butter->Update(mousex, mousey, leftclick);
}

void Game::render(double delta) {
	int fps = 100000 / delta;
	SDL_RenderClear(renderer);

	bg->Render(renderer);
	bowl->Render(renderer);
	egg->Render(renderer);
	butter->Render(renderer);

	if (debug) {
		SDL_Rect Message_rect;
		std::string debugstuff = ("FPS: " + std::to_string(fps) + " || " + std::to_string(mousex) + " : " + std::to_string(mousey) + " || LMouse : " + std::to_string(leftclick) + " || RMouse : " + std::to_string(rightclick));
		SDL_Texture* Message = ImageLoader::LoadText(debugstuff.c_str(), renderer, Message_rect, 30);
		SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
		SDL_DestroyTexture(Message);
	}

	SDL_RenderPresent(renderer);

}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Cleaned" << "\n";
}
