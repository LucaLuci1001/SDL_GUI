// 
// Created by LucaLuci1001 on 22.08.24.
//

#ifndef ELEMENT_HPP
#define ELEMENT_HPP
#include <cstdint>
#include <SDL_events.h>

class Window;

class Element {
private:
	Window *parent;

public:
	Element(Window *parent);

	virtual void render(int32_t mouseX, int32_t mouseY);
	virtual void handleEvent(SDL_Event &event);
};



#endif //ELEMENT_HPP
