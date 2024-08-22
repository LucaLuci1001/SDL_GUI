// 
// Created by LucaLuci1001 on 22.08.24.
//

#ifndef FONTMANAGER_HPP
#define FONTMANAGER_HPP

#include <unordered_set>

#include "Font.hpp"

class FontManager
{
private:
	std::unordered_set<Font *> fonts;

public:
	FontManager();

	Font *loadFont(std::string path, int size);

	void tick();
};


#endif //FONTMANAGER_HPP
