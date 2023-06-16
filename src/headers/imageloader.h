#include <SDL2/SDL.h>
#include <SDL2-Image/SDL_image.h>

class ImageLoader {
public:
	static SDL_Texture* LoadImage(const char* filename, SDL_Renderer* renderer);
};