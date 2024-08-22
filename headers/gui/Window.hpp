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
	bool closeWindow = false;
	bool keepRunningInBG;

protected:
	SDL_Window *window;
	SDL_Renderer *renderer;

	int32_t mouseX = 0;
	int32_t mouseY = 0;

public:
	const uint32_t id;

	Window(WindowHandler &windowHandler, bool keepRunningInBG, const char *title, int x, int y, int width
	               , int height, uint32_t flags);
	virtual ~Window();

	bool tick();
	void handleEvent(SDL_Event &event);
	virtual void handleEventCustom(SDL_Event &event);
	virtual void handleLogic();
	virtual void render(int32_t mouseX, int32_t mouseY);
	virtual void deInit();
};


#endif //WINDOW_HPP
