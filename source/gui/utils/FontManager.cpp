// 
// Created by LucaLuci1001 on 22.08.24.
//

#include "../../../headers/gui/utils/FontManager.hpp"

#include <iostream>

FontManager::FontManager()
{}

Font *FontManager::loadFont(std::string path, int size)
{
	for (const auto font : fonts)
	{
		if(font->path == path && font->size == size)
		{
			font->refCount++;
			return font;
		}
	}

	Font *newFont = new Font{path, size};
	newFont->font = TTF_OpenFont(path.c_str(), size);
	newFont->refCount++;
	fonts.insert(newFont);

	return newFont;
}

void FontManager::tick()
{
	erase_if(fonts, [](const Font *font)
	{
		if(font->refCount == 0)
		{
			delete font;
			return true;
		}

		return false;
	});
}
