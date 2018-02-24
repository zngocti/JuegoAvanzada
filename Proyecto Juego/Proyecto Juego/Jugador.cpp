#include "Jugador.h"

namespace Octavio
{

Jugador* Jugador::elJugador = nullptr;

Jugador::Jugador() : jugando(false)
{

}

Jugador::~Jugador()
{
	elJugador = nullptr;
}

Jugador* Jugador::crearJugador()
{
	if (elJugador == nullptr)
	{
		elJugador = new Jugador();
	}

	return elJugador;
}

void Jugador::empezarJuego()
{
	jugando = true;
}

bool Jugador::getJugando() const
{
	return jugando;
}

void Jugador::setJugando(bool estaJugando)
{
	jugando = estaJugando;
}

}