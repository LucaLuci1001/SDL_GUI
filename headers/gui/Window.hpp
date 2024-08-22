// 
// Created by LucaLuci1001 on 20.08.24.
//

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>

#include "WindowHandler.hpp"

class WindowHandler;

class Window
{
private:
	SDL_Window *window;
	SDL_Renderer *renderer;

	bool closeWindow = false;
	bool keepRunningInBG;

public:
	const uint32_t id;

	Window(WindowHandler &windowHandler, bool keepRunningInBG, const char *title, int x, int y, int width
	               , int height, uint32_t flags);
	virtual ~Window();

	bool tick();
	void handleEvent(SDL_Event &event);
	virtual void handleEventCustom(SDL_Event &event);
	virtual void handleLogic();
	virtual void render();
	virtual void deInit();
};


#endif //WINDOW_HPP
