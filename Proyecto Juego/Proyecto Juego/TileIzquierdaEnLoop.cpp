#include "TileIzquierdaEnLoop.h"
#include "GameObject.h"

namespace Octavio
{

	void TileIzquierdaEnLoop::iniciarComportamiento(GameObject* miGameObject)
	{
		if (miGameObject->getX() < -(Datos::getAnchoDeTitleAgua()))
		{
			miGameObject->setPosition(Datos::getAnchoPantalla() + (Datos::getTilesExtra() - 1)* (Datos::getAnchoDeTitleAgua()), miGameObject->getY());
		}
		else
		{
			miGameObject->move(-0.01, 0);
		}
	}
}