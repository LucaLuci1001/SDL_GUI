// 
// Created by LucaLuci1001 on 20.08.24.
//

#ifndef WINDOWHANDLER_HPP
#define WINDOWHANDLER_HPP
#include <unordered_map>

#include "Window.hpp"

class Window;

class WindowHandler
{
private:
	std::unordered_map<uint32_t, Window *> windows;

	void addWindow(Window *window);

public:
	WindowHandler();

	bool tick();
	void handleEvents();

	friend class Window;
};


#endif //WINDOWHANDLER_HPP
