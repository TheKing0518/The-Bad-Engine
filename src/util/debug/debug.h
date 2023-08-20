#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <string>

class DebugMenu {
public:
	DebugMenu(SDL_Renderer* ren);
	void Render(SDL_Renderer* render);
	void Update(float fps);

private:

	std::string debugtext = "Kill Yourself";

	float xpos = 0.0;
	float ypos = 0.0;
	int width = 800;
	int height = 200;

	SDL_Rect transform;
	SDL_Texture* texture;
	SDL_Renderer* render;
};