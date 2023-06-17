#include <SDL2/SDL.h>

class Ingredient {
public:
	Ingredient(const char* texpath, SDL_Renderer* ren, float x, float y, float dimmod, float gr);
	void Render(SDL_Renderer* render);
	void ChangePos(float xnew, float ynew);
	void ChangeDim(int wnew, int hnew);
	void Update(float mx, float my, bool click);

	float xpos = 0.0;
	float ypos = 0.0;
	int width = 0;
	int height = 0;

	float grabradius = 0.1;

private:
	SDL_Rect transform;
	SDL_Texture* texture;
	SDL_Renderer* render;
};