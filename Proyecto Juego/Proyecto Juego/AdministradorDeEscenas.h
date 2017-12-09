#ifndef ADMINISTRADORDEESCENAS_H
#define ADMINISTRADORDEESCENAS_H

#include "Escena.h"
#include "Lista.cpp"
#include <SFML/Graphics.hpp>

namespace Octavio
{
	class AdministradorDeEscenas
	{
	private:
		Escena* primerEscena;
		Lista<Escena*> listaDeEscenas;

	public:
		AdministradorDeEscenas();
		~AdministradorDeEscenas();

		Escena* CrearEscena();

		void IniciarUpdate();
	};
}

#endif
