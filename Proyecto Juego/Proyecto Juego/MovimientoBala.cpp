#include "MovimientoBala.h"
#include "GameObject.h"

namespace Octavio
{

MovimientoBala::MovimientoBala() : direccion(0), esEnemigo(true), reciclar(true)
{

}

void MovimientoBala::iniciarComportamiento(GameObject* miGameObject)
{
	if (reciclar == false)
	{
		switch (direccion)
		{
		case 1:
			miGameObject->move(0, -(Datos::getVelocidadBala()));
			break;
		case 2:
			miGameObject->move(Datos::getVelocidadBala(), -(Datos::getVelocidadBala()));
			break;
		case 3:
			miGameObject->move(Datos::getVelocidadBala(), 0);
			break;
		case 4:
			miGameObject->move(Datos::getVelocidadBala(), Datos::getVelocidadBala());
			break;
		case 5:
			miGameObject->move(0, Datos::getVelocidadBala());
			break;
		case 6:
			miGameObject->move(-(Datos::getVelocidadBala()), Datos::getVelocidadBala());
			break;
		case 7:
			miGameObject->move(-(Datos::getVelocidadBala()), 0);
			break;
		case 8:
			miGameObject->move(0, Datos::getVelocidadBala());
			break;
		default:
			break;
		}
	}
}

void MovimientoBala::setData(int num, bool enemigo)
{
	direccion = num;
	esEnemigo = enemigo;
}

bool MovimientoBala::getEsEnemigo() const
{
	return esEnemigo;
}

bool MovimientoBala::getReciclar() const
{
	return reciclar;
}

void MovimientoBala::noReciclar()
{
	reciclar = false;
}

}