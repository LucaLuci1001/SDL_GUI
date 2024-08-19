// 
// Created by LucaLuci1001 on 19.08.24.
//

#include "../../gui/Window.hpp"

Window::Window(char *title, int x, int y, int width, int height, uint32_t flags)
{
	window = SDL_CreateWindow(title, x, y, width, height, flags);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	thread = std::thread(run);
}

Window::~Window()
{}

bool Window::update()
{
	handleEvents();

	if(closeWindow)
	{
		deInit();
		return false;
	}

	render();

	return true;
}

void Window::handleEvents()
{}

void Window::run()
{
	while(true)
	{
		if(!update())
		{
			break;
		}
	}
}

void Window::render()
{}

void Window::deInit()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}
