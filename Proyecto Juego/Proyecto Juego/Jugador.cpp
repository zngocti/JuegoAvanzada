#include "Jugador.h"

namespace Octavio
{

Jugador* Jugador::elJugador = nullptr;

Jugador::Jugador() : jugando(false), puntos(0)
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
	puntos = 0;
	jugando = true;
}

void Jugador::sumarPuntos(int num)
{
	puntos = puntos + num;
}

bool Jugador::getJugando() const
{
	return jugando;
}

int Jugador::getPuntos() const
{
	return puntos;
}

}