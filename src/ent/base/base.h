#pragma once
#include <SDL2/SDL.h>

class Thing {
public:
	virtual void Setup(const char* texpath, SDL_Renderer* ren, float x, float y);
	virtual void Render(SDL_Renderer* render);
	virtual void Update();

	void ChangePos(float xnew, float ynew);
	void ChangeDim(int wnew, int hnew);

	float xpos = 0.0;
	float ypos = 0.0;
	int width = 0;
	int height = 0;

	SDL_Rect transform;
	SDL_Texture* texture;
	SDL_Renderer* render;
};