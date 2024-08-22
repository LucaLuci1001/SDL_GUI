// 
// Created by LucaLuci1001 on 20.08.24.
//

#include "../../headers/gui/Window.hpp"

#include <iostream>

Window::Window(WindowHandler &windowHandler, bool keepRunningInBG, const char *title, int x, int y, int width
               , int height, uint32_t flags)
	: window(SDL_CreateWindow(title, x, y, width, height, flags))
	, renderer(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED))
	, keepRunningInBG(keepRunningInBG)
	, id(SDL_GetWindowID(window))
{
	windowHandler.addWindow(this);
}

Window::~Window()
{}

void Window::handleEvent(SDL_Event &event)
{
	switch (event.type)
	{
		case SDL_WINDOWEVENT:
		{
			if (event.window.event == SDL_WINDOWEVENT_CLOSE)
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

	handleEventCustom(event);
}

void Window::handleEventCustom(SDL_Event &event)
{}

void Window::handleLogic()
{}

bool Window::tick()
{
	if (closeWindow)
	{
		deInit();
		return false;
	}

	if (SDL_GetWindowFlags(window) & SDL_WINDOW_SHOWN)
	{
		handleLogic();
		render();
		SDL_RenderPresent(renderer);
	} else if (keepRunningInBG)
	{
		handleLogic();
	}

	return true;
}

void Window::render()
{}

void Window::deInit()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
