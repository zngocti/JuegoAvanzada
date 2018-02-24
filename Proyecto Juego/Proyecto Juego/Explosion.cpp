#include "Explosion.h"

namespace Octavio
{

sf::Texture* Explosion::textura1 = nullptr;
sf::Texture* Explosion::textura2 = nullptr;
sf::Texture* Explosion::textura3 = nullptr;

sf::Time Explosion::tiempoEntreSprites = sf::seconds(0.5f);

Explosion::Explosion() : estaExplotando(false), tiempoDeExplosion(sf::Time::Zero), faseExplosion(0)
{
	if (textura1 == nullptr)
	{
		textura1 = new sf::Texture();
		Assets::explosion1(*textura1);
	}

	if (textura2 == nullptr)
	{
		textura2 = new sf::Texture();
		Assets::explosion2(*textura2);
	}

	if (textura3 == nullptr)
	{
		textura3 = new sf::Texture();
		Assets::explosion3(*textura3);
	}
}

Explosion::~Explosion()
{
	if (textura1 != nullptr)
	{
		delete(textura1);
		textura1 = nullptr;
	}

	if (textura2 != nullptr)
	{
		delete(textura2);
		textura2 = nullptr;
	}

	if (textura3 != nullptr)
	{
		delete(textura3);
		textura3 = nullptr;
	}
}

sf::Texture* Explosion::getTextura3()
{
	return textura3;
}

void Explosion::activarComportamiento()
{
	if (estaExplotando)
	{
		if (Datos::timerJuego.getElapsedTime() - tiempoDeExplosion >= tiempoEntreSprites)
		{
			float miX = getSprite().getPosition().x;
			float miY = getSprite().getPosition().y;

			switch (faseExplosion)
			{
			case 1:
				faseExplosion++;
				tiempoDeExplosion = Datos::timerJuego.getElapsedTime();
				setSprite(*textura3);
				setMedio();
				getSprite().setPosition(miX, miY);
				break;
			case 2:
				resetExplosion();
				break;
			default:
				faseExplosion++;
				tiempoDeExplosion = Datos::timerJuego.getElapsedTime();
				setSprite(*textura2);
				setMedio();
				getSprite().setPosition(miX, miY);
				break;
			}
		}
	}
}

void Explosion::iniciarExplosion()
{
	estaExplotando = true;
	tiempoDeExplosion = Datos::timerJuego.getElapsedTime();
}

void Explosion::resetExplosion()
{
	estaExplotando = false;
	setSprite(*textura1);
	setMedio();
	tiempoDeExplosion = sf::Time::Zero;
	faseExplosion = 0;
}

bool Explosion::getUso() const
{
	return estaExplotando;
}

}