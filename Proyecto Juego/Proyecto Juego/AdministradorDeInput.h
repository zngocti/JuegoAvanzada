#ifndef ADMINISTRADORDEINPUT_H
#define ADMINISTRADORDEINPUT_H

#include <SFML/Window.hpp>
#include "Escena.h"

namespace Octavio
{

class AdministradorDeInput
{
private:
	static AdministradorDeInput* administradorCreado;

	bool clickeando;

	AdministradorDeInput();

public:
	~AdministradorDeInput();
	static AdministradorDeInput* crearAdministradorDeInput();

	void verificarMouse(const Escena &escenaActual, const sf::Event &evento);
};

}

#endif