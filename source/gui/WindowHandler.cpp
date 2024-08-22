// 
// Created by LucaLuci1001 on 20.08.24.
//

#include "../../headers/gui/WindowHandler.hpp"

#include <iostream>

void WindowHandler::addWindow(Window *window)
{
	windows.insert({window->id, window});
}

WindowHandler::WindowHandler()
{}

WindowHandler::~WindowHandler()
{}

bool WindowHandler::tick()
{
	handleEvents();

	erase_if(windows, [](const auto &pair)
	{
		return !pair.second->tick();
	});

	fontManager.tick();

	return !windows.empty();
}

void WindowHandler::handleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if(windows.contains(event.window.windowID))
		{
			windows.at(event.window.windowID)->handleEvent(event);
		}
	}
}
