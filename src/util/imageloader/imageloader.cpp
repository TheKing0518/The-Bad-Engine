#include <src/util/imageloader/imageloader.h>

SDL_Texture* ImageLoader::LoadImage(const char* filename, SDL_Renderer* renderer) {
	SDL_Surface* tempsurf = IMG_Load(filename);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tempsurf);
	SDL_FreeSurface(tempsurf);
	return tex;
}

SDL_Texture* ImageLoader::LoadText(const char* text, SDL_Renderer* renderer, SDL_Rect& rect, int size) {
	TTF_Font* Roboto = TTF_OpenFont("res/fonts/Roboto-Black.ttf", size);
	SDL_Color Black = { 0, 0, 0 };

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Roboto, text, Black);
	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	TTF_SizeText(Roboto, text, &rect.w, &rect.h);


	rect.x = 0;
	rect.y = 0;
	//rect.w = 250;
	//rect.h = 75;

	return Message;
}