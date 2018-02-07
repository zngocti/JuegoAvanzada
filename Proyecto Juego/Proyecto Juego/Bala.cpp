#include "Bala.h"

namespace Octavio
{

sf::Texture* Bala::texturaBala = nullptr;
sf::Texture* Bala::texturaMarino = nullptr;

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

	if (texturaMarino != nullptr)
	{
		delete(texturaMarino);
		texturaMarino = nullptr;
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

void Bala::setMarino()
{
	if (texturaMarino == nullptr)
	{
		texturaMarino = new sf::Texture();
		Assets::crew1(*texturaMarino);
		setSprite(*texturaMarino);
		setMedio();
	}
	getComportamiento()->setData(3, false);
	setSprite(*texturaMarino);
}

}