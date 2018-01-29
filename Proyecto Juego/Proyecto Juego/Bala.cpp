#include "Bala.h"

namespace Octavio
{

sf::Texture* Bala::texturaBala = nullptr;

Bala::Bala() : estaEnUso(false), miBarcoOrigen(nullptr)
{
	if (texturaBala == nullptr)
	{
		texturaBala = new sf::Texture();
		Assets::cannonBall(*texturaBala);
	}

	setSprite(*texturaBala);
	setMedio();
	setPosition(-500, -500);
	setComportamiento(new MovimientoBala());
}

Bala::~Bala()
{
	if (texturaBala != nullptr)
	{
		delete(texturaBala);
		texturaBala = nullptr;
	}
}

void Bala::setBarcoOrigen(Barco* miBarco)
{
	miBarcoOrigen = miBarco;
}

Barco* Bala::getBarcoOrigen() const
{
	return miBarcoOrigen;
}

}