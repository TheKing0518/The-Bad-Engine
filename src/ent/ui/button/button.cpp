#include <src/ent/ui/button/button.h>

void Button::Update(float mx, float my, bool lm) {
	transform.x = xpos;
	transform.y = ypos;
	transform.w = width;
	transform.h = height;

	if (mx <= (xpos + width) && mx >= xpos && my <= (ypos + height) && my >= ypos) {
		hovering = true;
	}
	else {
		hovering = false;
	}
	
	if (!lm)
		canclick = true;

	if (lm && hovering && canclick) {
		Click();
	}

}

void Button::Click() {
	canclick = false;
}

Button::Button(const char* texpath, SDL_Renderer* ren, float x, float y, int w, int h) {
	render = ren;
	texture = ImageLoader::LoadImage(texpath, render);
	xpos = x;
	ypos = y;

	SDL_QueryTexture(texture, NULL, NULL, &width, &height);
	
	width = w;
	height = h;
}