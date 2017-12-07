#include "AdministradorDeEscenas.h"

namespace Octavio
{
	AdministradorDeEscenas::AdministradorDeEscenas() : primerEscena(new Escena)
	{
		listaDeEscenas.push_front(primerEscena);
	}

	AdministradorDeEscenas::~AdministradorDeEscenas()
	{
		for (int i = 0; i < listaDeEscenas.size; i++)
		{
			
		}
	}

	Escena* AdministradorDeEscenas::CrearEscena()
	{
		return new Escena();
	}

	void AdministradorDeEscenas::DestruirEscena(Escena* unaEscena)
	{
		delete (unaEscena);
	}
}