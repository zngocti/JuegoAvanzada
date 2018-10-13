#include "TileIzquierdaEnLoop.h"
#include "GameObject.h"

namespace Octavio
{

	void TileIzquierdaEnLoop::iniciarComportamiento(GameObject* miGameObject)
	{
		if (miGameObject->getX() < -(Datos::getAnchoDeTileAgua()))
		{
			//ese -1 junto al ancho del tile es para que no se separen tanto los sprites porque causaba una linea vertical negra
			miGameObject->setPosition(((Datos::getAnchoPantalla() / Datos::getAnchoDeTileAgua()) + Datos::getTilesExtra() - 1.0f)* (Datos::getAnchoDeTileAgua() -1.0f ) - 0.1f, miGameObject->getY());
		}
		else
		{
			miGameObject->move(-0.05f, 0);
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

	void TileIzquierdaEnLoop::noReciclar()
	{

	}

	void TileIzquierdaEnLoop::activarReciclar()
	{

	}

	void TileIzquierdaEnLoop::setData(int num, bool enemigo)
	{

	}

	bool TileIzquierdaEnLoop::getEsEnemigo() const
	{
		return false;
	}
}