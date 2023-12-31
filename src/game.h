#pragma once
#include <SDL2/SDL.h>
#include <SDL2-Image/SDL_image.h>
#include <SDL2-TTF/SDL_ttf.h>
#include <iostream>
#include <map>

class Game {
public:

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update(float delta);
	void render(float delta);
	void clean();

	bool running() { return isRunning; }

private:

	int mousex = 0;
	int mousey = 0;

	bool leftclick = false;
	bool rightclick = false;
	
	std::map<int, bool> keyboard;

	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};