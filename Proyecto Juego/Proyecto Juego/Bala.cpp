#include "Bala.h"

namespace Octavio
{

Bala::Bala() : velocidad(0.2), estaEnUso(false)
{

}

Bala::~Bala()
{

}

bool Bala::getEstaEnUso() const
{
	return estaEnUso;
}

float Bala::getVelocidad() const
{
	return velocidad;
}

void Bala::mover(int num)
{

}

}