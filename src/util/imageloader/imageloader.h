#pragma once
#include <SDL2/SDL.h>
#include <SDL2-Image/SDL_image.h>
#include <SDL2-TTF/SDL_ttf.h>

class ImageLoader {
public:
	static SDL_Texture* LoadImage(const char* filename, SDL_Renderer* renderer);
	static SDL_Texture* LoadText(const char* text, SDL_Renderer* renderer, SDL_Rect& rect, int size);
};