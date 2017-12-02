#include "Juego.h"

namespace Octavio
{

	Juego::Juego() : jugador(new Jugador()), administradorEscenas(new AdministradorDeEscenas())
	{
			
	}

	Juego::~Juego()
	{
		delete(jugador);
		delete(administradorEscenas);
	}

	void Juego::Iniciar()
	{

	}
}