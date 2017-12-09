#ifndef ASSETS_H
#define ASSETS

#include <SFML/Graphics.hpp>
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include <iostream>

namespace Octavio
{

class Assets
{
public:
	static bool Assets::menuBackground(sf::Texture &textura);

private:
	Assets();

};

}

#endif
