#ifndef ADMINISTRADORDEESCENAS_H
#define ADMINISTRADORDEESCENAS_H

#include "Escena.h"
#include <list>

namespace Octavio
{
	class AdministradorDeEscenas
	{
	private:
		Escena* primerEscena;
		std::list<Escena*> listaDeEscenas;

	public:
		AdministradorDeEscenas();
		~AdministradorDeEscenas();
		
		Escena* CrearEscena();
		void DestruirEscena(Escena* unaEscena);
	};
}

#endif
