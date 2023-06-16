#include <baseobject.h>
#include <imageloader.h>
#include <game.h>

Thing::Thing(const char* texpath, SDL_Renderer* ren, double x, double y, int w, int h) {
	render = ren;
	texture = ImageLoader::LoadImage(texpath, render);
	xpos = x;
	ypos = y;
	width = w;
	height = h;
}

void Thing::Render(SDL_Renderer* render) {
	SDL_RenderCopy(render, texture, NULL, &transform);
}

void Thing::Update() {
	transform.x = xpos;
	transform.y = ypos;
	transform.w = width;
	transform.h = height;
}

void Thing::ChangePos(double xnew, double ynew) {
	xpos = xnew;
	ypos = ynew;
}

void Thing::ChangeDim(int wnew, int hnew) {
	width = wnew;
	height = hnew;
}