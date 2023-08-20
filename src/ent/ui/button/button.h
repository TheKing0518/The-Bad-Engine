#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <src/ent/base/base.h>
#include <src/util/imageloader/imageloader.h>

class Button : public Thing {
public:
	Button(const char* texpath, SDL_Renderer* ren, float x, float y, int w, int h);
	void Update(float mx, float my, bool lm);

	virtual void Click();

	bool hovering = false;
	bool canclick = true;

};