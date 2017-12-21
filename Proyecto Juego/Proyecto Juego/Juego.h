#ifndef JUEGO_H
#define JUEGO_H

#include "Jugador.h"
#include "AdministradorDeEscenas.h"
#include "Assets.h"
#include "Datos.h"
#include "TileIzquierdaEnLoop.h"

namespace Octavio
{

class Juego
{
private:
	Jugador* jugador;
	AdministradorDeEscenas* administradorEscenas;
	Lista<sf::Texture*> listaDeTexturas;

	void crearEscenas();
	void destruirTexturas();

	Escena* pantallaControles(Boton* const &miBoton, sf::Texture* const &miTextura);
	Escena* pantallaPuntajes(Boton* const &miBoton, sf::Texture* const &miTextura);
	Escena* pantallaCreditos(Boton* const &miBoton, sf::Texture* const &miTextura);

	void generarNiveles(Escena* const &miEscena);

public:
	void iniciar();
	Juego();
	~Juego();

};

}

#endif