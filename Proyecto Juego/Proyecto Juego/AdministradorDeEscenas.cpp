#include "AdministradorDeEscenas.h"

namespace Octavio
{
	AdministradorDeEscenas::AdministradorDeEscenas()
	{

	}

	AdministradorDeEscenas::~AdministradorDeEscenas()
	{

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