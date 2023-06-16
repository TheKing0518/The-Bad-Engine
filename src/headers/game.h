#include <SDL2/SDL.h>
#include <SDL2-Image/SDL_image.h>
#include <SDL2-TTF/SDL_ttf.h>
#include <iostream>

class Game {
public:

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update(double delta);
	void render(double delta);
	void clean();

	bool running() { return isRunning; }

	int mousex = 0;
	int mousey = 0;

	bool leftclick = false;
	bool rightclick = false;

private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};