// 
// Created by LucaLuci1001 on 22.08.24.
//

#include "../../../headers/gui/utils/Font.hpp"

#include <iostream>


Font::Font(std::string path, int size)
	: path(path)
	, size(size)
{}

void Font::free()
{
	refCount--;

	if (refCount == 0)
	{
		TTF_CloseFont(font);
	}
}

TTF_Font *Font::getFont()
{
	return font;
}
