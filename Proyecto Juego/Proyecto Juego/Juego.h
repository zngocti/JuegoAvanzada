#ifndef JUEGO_H
#define JUEGO_H
#include "Jugador.h"
#include "AdministradorDeEscenas.h"
#include "Assets.h"

namespace Octavio
{

class Juego
{
private:
	Jugador* jugador;
	AdministradorDeEscenas* administradorEscenas;
	Lista<sf::Texture*> listaDeTexturas;

	void crearMenu();
	void destruirMenu();

public:
	void iniciar();
	Juego();
	~Juego();

};

}

#endif