#include "CentroVolver.h"
#include "GameObject.h"

namespace Octavio
{

bool CentroVolver::primero = true;
sf::Time CentroVolver::cdAtaque = sf::seconds(5.0f);

CentroVolver::CentroVolver() : avanzando(false), entrando(true), recorrido(0), ultimoTiempo(Datos::timerJuego.getElapsedTime()), atacar(false), reciclar(true)
{

}

void CentroVolver::iniciarComportamiento(GameObject* miGameObject)
{
	if (reciclar == false)
	{
		if (miGameObject->getX() > Datos::getAnchoPantalla() + Datos::getMaxAnchoSprite())
		{
			miGameObject->move(-(Datos::getVelocidad()), 0);
		}
		else if (entrando)
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
				entrando = false;
				avanzando = true;
			}
		}
		else if (avanzando)
		{
			if (miGameObject->getX() > (Datos::getAnchoPantalla() / 3))
			{
				miGameObject->move(-(Datos::getVelocidad()), 0);
			}
			else
			{
				avanzando = false;
			}
		}
		else
		{
			if (miGameObject->getY() > (Datos::getAltoPantalla() / 2))
			{
				miGameObject->move(-(Datos::getVelocidad()), Datos::getVelocidad());
			}
			else
			{
				miGameObject->move(-(Datos::getVelocidad()), -(Datos::getVelocidad()));
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
}

bool CentroVolver::getAtaque() const
{
	return atacar;
}

void CentroVolver::resetAtaque()
{
	atacar = false;
	ultimoTiempo = Datos::timerJuego.getElapsedTime();
}

bool CentroVolver::getReciclar() const
{
	return reciclar;
}

bool CentroVolver::getPrimero() const
{
	return primero;
}

void CentroVolver::cambiarPrimero()
{
	primero = !primero;
}

void CentroVolver::noReciclar()
{
	reciclar = false;
}

void CentroVolver::activarReciclar()
{
	reciclar = true;
}

void CentroVolver::setData(int num, bool enemigo)
{

}

bool CentroVolver::getEsEnemigo() const
{
	return false;
}

}