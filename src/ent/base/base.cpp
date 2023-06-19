#include <src/ent/base/base.hpp>
#include <src/util/imageloader/imageloader.hpp>
#include <src/game.hpp>

Thing::Thing(const char* texpath, SDL_Renderer* ren, float x, float y) {
	render = ren;
	texture = ImageLoader::LoadImage(texpath, render);
	xpos = x;
	ypos = y;

	SDL_QueryTexture(texture, NULL, NULL, &width, &height);
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

void Thing::ChangePos(float xnew, float ynew) {
	xpos = xnew;
	ypos = ynew;
}

void Thing::ChangeDim(int wnew, int hnew) {
	width = wnew;
	height = hnew;
}