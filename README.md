# The Bad Engine
Not really what I'm gonna call it but it will work for now.
The engine I will use when I want to make a game in C++ or maybe some cool visualizations like [Sebastion Lague](https://www.youtube.com/@SebastianLague).

## How to use
Now I know nobody will use this except myself however if I keep using this I will eventually need this myself.
Just do the following : 
```c++
  #include <src/game.hpp>
  
  Game* game = nullptr;

  float delta;
  int a = SDL_GetTicks();
  int b = SDL_GetTicks();
  
  int main(int argc, char* argv[]) {
  	game = new Game();
  
  	game->init({put the window name here}, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, {width}, {height}, {fullscreen});
  
  	while (game->running()) {
	      	a = SDL_GetTicks();
		delta += a - b;
	      	b = a;
	      
	  	game->handleEvents();
	  	game->update(delta);
	  	game->render(delta);
	
	      	delta = 0;
      
  	}
  	game->clean();
  	return 0;
  }
```
