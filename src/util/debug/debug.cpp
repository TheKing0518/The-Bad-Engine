#include <src/util/debug/debug.h>
#include <src/util/imageloader/imageloader.h>
#include <src/game.h>

DebugMenu::DebugMenu(SDL_Renderer* ren) {
	render = ren;
	texture = ImageLoader::LoadText(debugtext.c_str(), render, transform, 17);
	xpos = 0;
	ypos = 0;

	SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}

void DebugMenu::Render(SDL_Renderer* render) {
	SDL_RenderCopy(render, texture, NULL, &transform);
}

void DebugMenu::Update(float fps) {

	debugtext = "Fps: " + std::to_string(fps);
	texture = ImageLoader::LoadText(debugtext.c_str(), render, transform, 17);

	transform.x = xpos;
	transform.y = ypos;
	transform.w = width;
	transform.h = height;

}