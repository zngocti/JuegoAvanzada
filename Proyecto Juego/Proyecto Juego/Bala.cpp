#include "Bala.h"

namespace Octavio
{

Bala::Bala() : estaEnUso(false), miBarcoOrigen(nullptr)
{
	setPosition(-500, -500);
	setComportamiento(new MovimientoBala());
}

Bala::~Bala()
{

}

void Bala::setBarcoOrigen(Barco* miBarco)
{
	miBarcoOrigen = miBarco;
}

Barco* Bala::getBarcoOrigen() const
{
	return miBarcoOrigen;
}

}