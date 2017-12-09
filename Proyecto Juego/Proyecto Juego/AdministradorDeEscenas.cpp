#include "AdministradorDeEscenas.h"

namespace Octavio
{
	AdministradorDeEscenas::AdministradorDeEscenas() : primerEscena(new Escena), listaDeEscenas(Lista<Escena*>(primerEscena))
	{

	}

	AdministradorDeEscenas::~AdministradorDeEscenas()
	{
		listaDeEscenas.removeAll();
	}

	Escena* AdministradorDeEscenas::CrearEscena()
	{
		Escena* nuevaEscena = new Escena();
		listaDeEscenas.addBack(nuevaEscena);
		return nuevaEscena;
	}

	void AdministradorDeEscenas::IniciarUpdate()
	{

	}
}