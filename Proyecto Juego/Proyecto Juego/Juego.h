#ifndef JUEGO_H
#define JUEGO_H
#include "Jugador.h"
#include "AdministradorDeEscenas.h"

namespace Octavio
{

class Juego
{
private:
	Jugador* jugador;
	AdministradorDeEscenas* administradorEscenas;

public:
	void Iniciar();
	Juego();
	~Juego();
};

}

#endif