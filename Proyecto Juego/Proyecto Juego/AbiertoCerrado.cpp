#include "AbiertoCerrado.h"
#include "GameObject.h"

namespace Octavio
{

bool AbiertoCerrado::primero = true;
sf::Time AbiertoCerrado::cdAtaque = sf::seconds(4.0f);

AbiertoCerrado::AbiertoCerrado() : avanzando(false), cerrando1(true), cerrando2(false), recorrido(0), ultimoTiempo(Datos::timerJuego.getElapsedTime()), atacar(false), reciclar(true)
{

}

void AbiertoCerrado::iniciarComportamiento(GameObject* miGameObject)
{
	if (reciclar == false)
	{
		if (cerrando1)
		{
			if (miGameObject->getY() > (Datos::getAltoPantalla() / 4) * 3 + Datos::getMaxAltoSprite())
			{
				miGameObject->move(-(Datos::getVelocidad()), -(Datos::getVelocidad()));
			}
			else if (miGameObject->getY() < (Datos::getAltoPantalla() / 4) - Datos::getMaxAltoSprite())
			{
				miGameObject->move(-(Datos::getVelocidad()), Datos::getVelocidad());
			}
			else
			{
				cerrando1 = false;
				avanzando = true;
			}
		}
		else if (avanzando)
		{
			if (miGameObject->getX() > (Datos::getAnchoPantalla() / 2))
			{
				miGameObject->move(-(Datos::getVelocidad()), 0);
			}
			else
			{
				avanzando = false;
				cerrando2 = true;
			}
		}
		else if (cerrando2)
		{
			if (miGameObject->getY() > (Datos::getAltoPantalla() / 2) + Datos::getMaxAltoSprite())
			{
				miGameObject->move(-(Datos::getVelocidad()), -(Datos::getVelocidad()));
			}
			else if (miGameObject->getY() < (Datos::getAltoPantalla() / 2) - Datos::getMaxAltoSprite())
			{
				miGameObject->move(-(Datos::getVelocidad()), Datos::getVelocidad());
			}
			else
			{
				cerrando2 = false;
			}
		}
		else
		{
			miGameObject->move(-(Datos::getVelocidad()), 0);
		}

		if (Datos::timerJuego.getElapsedTime() - ultimoTiempo >= cdAtaque)
		{
			atacar = true;
		}

		if (miGameObject->getX() < 0 - Datos::getMaxAnchoSprite())
		{
			reciclar = true;
		}
	}
}

bool AbiertoCerrado::getAtaque() const
{
	return atacar;
}

void AbiertoCerrado::resetAtaque()
{
	atacar = false;
	ultimoTiempo = Datos::timerJuego.getElapsedTime();
}

bool AbiertoCerrado::getReciclar() const
{
	return reciclar;
}

bool AbiertoCerrado::getPrimero() const
{
	return primero;
}

void AbiertoCerrado::cambiarPrimero()
{
	primero = !primero;
}

void AbiertoCerrado::noReciclar()
{
	reciclar = false;
}

void AbiertoCerrado::activarReciclar()
{
	reciclar = true;
}

void AbiertoCerrado::setData(int num, bool enemigo)
{

}

bool AbiertoCerrado::getEsEnemigo() const
{
	return false;
}

}