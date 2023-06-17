#include <baseobject.h>
#include <imageloader.h>
#include <ingredient.h>
#include <cmath>

Ingredient::Ingredient(const char* texpath, SDL_Renderer* ren, float x, float y, float dimmod, float gr) {
	render = ren;
	texture = ImageLoader::LoadImage(texpath, render);
	xpos = x;
	ypos = y;

	SDL_QueryTexture(texture, NULL, NULL, &width, &height);

	width = width * dimmod;
	height = height * dimmod;

	grabradius = gr;
}

void Ingredient::Render(SDL_Renderer* render) {
	SDL_RenderCopy(render, texture, NULL, &transform);
}

void Ingredient::Update(float mx, float my, bool click) {

	if (xpos > 800 - width) {
		xpos = 800 - width;
	}
	if (xpos < 0) {
		xpos = 0;
	}

	if (ypos > 600 - height) {
		ypos = 600 - height;
	}
	if (ypos < 0) {
		ypos = 0;
	}

	float cx = xpos + (width / 2);
	float cy = ypos + (height / 2);

	float distance = sqrt((mx - cx) * (mx - cx) + (my - cy) * (my - cy));

	if (distance <= grabradius) {
		if (click) {
			xpos = mx - (width / 2);
			ypos = my - (height / 2);
		}
	}

	transform.x = xpos;
	transform.y = ypos;
	transform.w = width;
	transform.h = height;
}

void Ingredient::ChangePos(float xnew, float ynew) {
	xpos = xnew;
	ypos = ynew;
}

void Ingredient::ChangeDim(int wnew, int hnew) {
	width = wnew;
	height = hnew;
}