#include "ArribaAbajo.h"
#include "GameObject.h"

namespace Octavio
{
	const float ArribaAbajo::distanciaCorta = 150;
	sf::Time ArribaAbajo::cdAtaque = sf::seconds(1.5f);
	bool ArribaAbajo::primero = true;

	ArribaAbajo::ArribaAbajo() : avanzando(false), arriba(false), abajo(false), recorrido(0),
								 ultimoTiempo(Datos::timerJuego.getElapsedTime()), atacar(false), reciclar(false)
	{

	}

	void ArribaAbajo::iniciarComportamiento(GameObject* miGameObject)
	{
		if (arriba && miGameObject->getY() < Datos::getAltoPantalla() + Datos::getMaxAltoSprite())
		{
			miGameObject->move(0, Datos::getVelocidad());
		}
		else if (abajo && miGameObject->getY() > 0 - Datos::getMaxAltoSprite())
		{
			miGameObject->move(0, -(Datos::getVelocidad()));
		}
		else
		{
			if (recorrido < distanciaCorta)
			{
				miGameObject->move(-(Datos::getVelocidad()), 0);
				recorrido = recorrido + Datos::getVelocidad();
			}
		}

		if (arriba && miGameObject->getY() >= Datos::getAltoPantalla() + Datos::getMaxAltoSprite())
		{
			arriba = false;
		}
		if (abajo && miGameObject->getY() <= 0 - Datos::getMaxAltoSprite())
		{
			abajo = false;
		}
		if (avanzando && recorrido >= distanciaCorta)
		{
			avanzando = false;
			recorrido = 0;
			if (miGameObject->getY() < 0)
			{
				arriba = true;
			}
			else
			{
				abajo = true;
			}
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

	bool ArribaAbajo::getAtaque() const
	{
		return atacar;
	}

	void ArribaAbajo::resetAtaque()
	{
		atacar = false;
		ultimoTiempo = Datos::timerJuego.getElapsedTime();
	}

	bool ArribaAbajo::getReciclar() const
	{
		return reciclar;
	}

	bool ArribaAbajo::getPrimero() const
	{
		return primero;
	}

	void ArribaAbajo::cambiarPrimero()
	{
		primero = !primero;
	}
}