#include <SDL2/SDL.h>

class Thing {
public:
	Thing(const char* texpath, SDL_Renderer* ren, double x, double y, int w, int h);
	void Render(SDL_Renderer* render);
	void ChangePos(double xnew, double ynew);
	void ChangeDim(int wnew, int hnew);
	void Update();
	
	double xpos = 0.0;
	double ypos = 0.0;
	int width = 0;
	int height = 0;

private:
	SDL_Rect transform;
	SDL_Texture* texture;
	SDL_Renderer* render;
};