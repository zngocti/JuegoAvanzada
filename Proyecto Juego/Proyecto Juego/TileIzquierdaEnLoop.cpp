#include "TileIzquierdaEnLoop.h"
#include "GameObject.h"

namespace Octavio
{

	void TileIzquierdaEnLoop::iniciarComportamiento(GameObject* miGameObject)
	{
		if (miGameObject->getX() < -(Datos::getAnchoDeTileAgua()))
		{
			miGameObject->setPosition(Datos::getAnchoPantalla() + (Datos::getTilesExtra() - 1)* (Datos::getAnchoDeTileAgua()), miGameObject->getY());
		}
		else
		{
			miGameObject->move(-0.01, 0);
		}
	}

	bool TileIzquierdaEnLoop::getAtaque() const
	{
		return false;
	}

	void TileIzquierdaEnLoop::resetAtaque()
	{

	}

	bool TileIzquierdaEnLoop::getReciclar() const
	{
		return false;
	}

	bool TileIzquierdaEnLoop::getPrimero() const
	{
		return false;
	}

	void TileIzquierdaEnLoop::cambiarPrimero()
	{

	}
}