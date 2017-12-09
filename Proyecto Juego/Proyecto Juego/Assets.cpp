#include "Assets.h"

namespace Octavio
{

bool Assets::menuBackground(sf::Texture &textura)
{
	sf::Texture miTextura;

	// cargo un rectangulo de spriteW x spriteH que inicia en el (spriteX, spriteY) del archivo
	if (!miTextura.loadFromFile("../Assets/background.jpg", sf::IntRect()))
	{
		std::cout << "No cargo la imagen." << std::endl;
		return false;
	}
	else
	{
		textura = miTextura;
		return true;
	}
}

}