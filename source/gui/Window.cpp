// 
// Created by LucaLuci1001 on 20.08.24.
//

#include "../../headers/gui/Window.hpp"

#include <iostream>

Window::Window(WindowHandler &windowHandler, const char *title)
	: window(SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, SDL_WINDOW_SHOWN))
	, renderer(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED))
	, id(SDL_GetWindowID(window))
{
	windowHandler.addWindow(this);
}

void Window::handleEvent(SDL_Event &event)
{
	switch (event.type)
	{
		case SDL_WINDOWEVENT:
		{
			if(event.window.event == SDL_WINDOWEVENT_CLOSE)
			{
				closeWindow = true;
			}
			break;
		}
		default:
		{
			break;
		}
	}
}

bool Window::tick()
{
	if(closeWindow)
	{
		deInit();
		return false;
	}

	render();
	SDL_RenderPresent(renderer);

	return true;
}

void Window::render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	SDL_Rect rect{100, 100, 200, 200};
	SDL_RenderFillRect(renderer, &rect);
}

void Window::deInit()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
