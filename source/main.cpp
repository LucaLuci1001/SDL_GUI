#include <iostream>
#include <SDL.h>

#include "../headers/gui/Window.hpp"

int main() {
	SDL_Init(SDL_INIT_VIDEO);

	WindowHandler windowHandler;
	Window window{windowHandler, "window1"};
	Window window1{windowHandler, "window2"};

	while(windowHandler.tick())
	{}

	SDL_Quit();

	return 0;
}
