#include <iostream>
#include <SDL.h>

#include "../headers/gui/Window.hpp"

class CustomWindow: Window
{
private:
	SDL_Rect rect{100, 100, 200, 200};
	SDL_Color color;
	Font *font;

	SDL_Surface *textSurface = TTF_RenderText_Solid(font->getFont(), "Test", {255, 255, 255, 255});
	SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

public:
	CustomWindow(WindowHandler &windowHandler, bool keepRunningInBG, const char *title, int x, int y, int width
	             , int height, uint32_t flags)
		: Window(windowHandler, keepRunningInBG, title, x, y, width, height, flags)
	, font(&windowHandler.getFontmanager().loadFont("ressources/Open_Sans/static/OpenSans-Regular.ttf", 24))
	{}

	void deInit() override
	{
		SDL_FreeSurface(textSurface);
		SDL_DestroyTexture(textTexture);

		font->free();

		Window::deInit();
	}

	void render(int32_t mouseX, int32_t mouseY) override
	{
		if (rectContainsPos(rect, mouseX, mouseY))
		{
			color = SDL_Color{255, 0, 0, 255};
		} else
		{
			color = SDL_Color{0, 0, 255, 255};
		}

		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
		SDL_RenderFillRect(renderer, &rect);

		SDL_RenderCopy(renderer, textTexture, nullptr, nullptr);
	}

	static bool rectContainsPos(SDL_Rect &rect, int32_t x, int32_t y)
	{
		return
				rect.x <= x
				&& x <= (rect.x + rect.w)
				&& rect.y <= y
				&& y <= (rect.y + rect.h);
	}
};

int main()
{
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

	WindowHandler windowHandler;
	CustomWindow window{
		windowHandler, true, "window1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400
		, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
	};
	CustomWindow window1{
		windowHandler, false, "window2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 400
		, SDL_WINDOW_SHOWN
	};

	while (windowHandler.tick())
	{}

	TTF_Quit();
	SDL_Quit();

	return 0;
}
