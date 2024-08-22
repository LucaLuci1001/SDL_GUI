// 
// Created by LucaLuci1001 on 22.08.24.
//

#ifndef FONTS_HPP
#define FONTS_HPP

#include <string>
#include <SDL2/SDL_ttf.h>

class Font {
private:
	const std::string path;
	const int size;

	TTF_Font *font = nullptr;
	int refCount = 0;

public:
	Font(std::string path, int size);

	void free();

	TTF_Font *getFont();

	friend class FontManager;
};



#endif //FONTS_HPP
