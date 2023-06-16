#include <imageloader.h>

SDL_Texture* ImageLoader::LoadImage(const char* filename, SDL_Renderer* renderer) {
	SDL_Surface* tempsurf = IMG_Load(filename);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempsurf);
	SDL_FreeSurface(tempsurf);
	return tex;
}