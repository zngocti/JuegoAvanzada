#ifndef ADMINISTRADORDEESCENAS_H
#define ADMINISTRADORDEESCENAS_H

#include "Escena.h"

namespace Octavio
{
	class AdministradorDeEscenas
	{
	public:
		AdministradorDeEscenas();
		~AdministradorDeEscenas();
		
		Escena* CrearEscena();
		void DestruirEscena(Escena* unaEscena);
	};
}

#endif
