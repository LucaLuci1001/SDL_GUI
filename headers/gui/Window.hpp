// 
// Created by LucaLuci1001 on 20.08.24.
//

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>

#include "WindowHandler.hpp"

class WindowHandler;

class Window {
private:
	SDL_Window *window;
	SDL_Renderer *renderer;

	bool closeWindow;

public:
	const uint32_t id;

	Window(WindowHandler &windowHandler, const char *title);

	bool tick();
	virtual void handleEvent(SDL_Event &event);
	virtual void render();
	virtual void deInit();
};



#endif //WINDOW_HPP
