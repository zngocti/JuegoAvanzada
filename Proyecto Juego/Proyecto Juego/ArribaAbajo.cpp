#include "ArribaAbajo.h"
#include "GameObject.h"

namespace Octavio
{
	const float ArribaAbajo::distanciaCorta = 410;
	sf::Time ArribaAbajo::cdAtaque = sf::seconds(1.5f);
	bool ArribaAbajo::primero = true;

	ArribaAbajo::ArribaAbajo() : avanzando(true), arriba(false), abajo(false), recorrido(0),
								 ultimoTiempo(Datos::timerJuego.getElapsedTime()), atacar(false), reciclar(true), primerMovimiento(true)
	{

	}

	void ArribaAbajo::iniciarComportamiento(GameObject* miGameObject)
	{
		if (reciclar == false)
		{
			if ((miGameObject->getY() >= Datos::getAltoPantalla() + Datos::getMaxAltoSprite()) && avanzando)
			{
				if (recorrido < distanciaCorta)
				{
					miGameObject->move(-(Datos::getVelocidad()), 0);
					recorrido = recorrido + Datos::getVelocidad();
				}
				else
				{
					recorrido = 0;
					avanzando = false;
					arriba = true;
				}

				primerMovimiento = false;
			}
			else if ((miGameObject->getY() <= 0 - (Datos::getMaxAltoSprite())) && avanzando)
			{
				if (!primerMovimiento)
				{
					if (recorrido < distanciaCorta)
					{
						miGameObject->move(-(Datos::getVelocidad()), 0);
						recorrido = recorrido + Datos::getVelocidad();
					}
					else
					{
						recorrido = 0;
						avanzando = false;
						abajo = true;
					}
				}
				else
				{
					if (recorrido < distanciaCorta/2)
					{
						miGameObject->move(-(Datos::getVelocidad()), 0);
						recorrido = recorrido + Datos::getVelocidad();
					}
					else
					{
						recorrido = 0;
						avanzando = false;
						abajo = true;
						primerMovimiento = false;
					}
				}
			}

			if (arriba && miGameObject->getY() > 0 - (Datos::getMaxAltoSprite()))
			{
				miGameObject->move(0, -(Datos::getVelocidad()));
			}
			else if (arriba)
			{
				arriba = false;
				avanzando = true;
			}

			if (abajo && miGameObject->getY() < Datos::getAltoPantalla() + Datos::getMaxAltoSprite())
			{
				miGameObject->move(0, Datos::getVelocidad());
			}
			else if (abajo)
			{
				abajo = false;
				avanzando = true;
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

	void ArribaAbajo::noReciclar()
	{
		reciclar = false;
	}
}