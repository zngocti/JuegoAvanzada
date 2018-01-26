#include "Bala.h"

namespace Octavio
{

sf::Texture* Bala::texturaBala = nullptr;

Bala::Bala() : estaEnUso(false)
{
	if (texturaBala == nullptr)
	{
		texturaBala = new sf::Texture();
		Assets::cannonBall(*texturaBala);
	}

	setSprite(*texturaBala);
	setMedio();
	setPosition(-500, -500);
}

Bala::~Bala()
{
	if (texturaBala != nullptr)
	{
		delete(texturaBala);
		texturaBala = nullptr;
	}
}

}