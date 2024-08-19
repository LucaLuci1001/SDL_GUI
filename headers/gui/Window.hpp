// 
// Created by LucaLuci1001 on 19.08.24.
//

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <thread>
#include <SDL2/SDL.h>


class Window {
private:
	std::thread thread;

	bool closeWindow = false;

protected:
	SDL_Window *window;
	SDL_Renderer *renderer;

public:
	Window(char *title, int x, int y, int width, int height, uint32_t flags);
	virtual ~Window();

	bool update();
	void handleEvents();
	void run();

	virtual void render();
	virtual void deInit();
};



#endif //WINDOW_HPP
