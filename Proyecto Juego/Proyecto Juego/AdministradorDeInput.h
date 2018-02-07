#ifndef ADMINISTRADORDEINPUT_H
#define ADMINISTRADORDEINPUT_H

#include <SFML/Window.hpp>
#include "Escena.h"
#include "Jugador.h"
#include "Barco.h"

namespace Octavio
{

class AdministradorDeInput
{
private:
	static AdministradorDeInput* administradorCreado;

	bool clickeando;
	bool puedeAtacar;
	bool puedeAbordar;

	AdministradorDeInput();

public:
	~AdministradorDeInput();
	static AdministradorDeInput* crearAdministradorDeInput();

	void verificarMouse(const Escena &escenaActual, const sf::Event &evento);
	void verificarTeclas(Jugador* miJugador, const sf::Event &evento, Barco* unBarco);
};

}

#endif