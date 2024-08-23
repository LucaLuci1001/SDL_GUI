// 
// Created by LucaLuci1001 on 20.08.24.
//

#include "../../headers/gui/Window.hpp"

#include <iostream>

void Window::addElement(Element *element)
{
	elements.push_back(element);
}

Window::Window(WindowHandler &windowHandler, bool keepRunningInBG, const char *title, int x, int y, int width
               , int height, uint32_t flags)
	: window(SDL_CreateWindow(title, x, y, width, height, flags))
	, renderer(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED))
	, windowHandler(&windowHandler)
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
		case SDL_MOUSEMOTION:
		{
			mouseX = event.motion.x;
			mouseY = event.motion.y;
		}
		default:
		{
			break;
		}
	}

	handleEventCustom(event);

	for (auto element: elements)
	{
		element->handleEvent(event);
	}
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
		render(mouseX, mouseY);
		SDL_RenderPresent(renderer);
	} else if (keepRunningInBG)
	{
		handleLogic();
	}

	return true;
}

void Window::render(int32_t mouseX, int32_t mouseY)
{}

void Window::deInit()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

SDL_Renderer *Window::getRenderer()
{
	return renderer;
}
