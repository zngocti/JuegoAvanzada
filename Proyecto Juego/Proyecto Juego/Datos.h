#ifndef DATOS_H
#define DATOS_H

#include <SFML\System.hpp>

namespace Octavio
{

class Datos
{
private:
	Datos();
	static int anchoPantalla;
	static int altoPantalla;
	static int anchoDeTileAgua;
	static int zDelAgua;
	static int tilesExtra;
	static int maxAltoSprite;
	static int maxAnchoSprite;
	static int cantidadDeCadaBarco;
	static int zDeBarcos;
	static int zDelJugador;
	static int disparosBarco;
	static int disparosBarcoDoble;
	static int disparosBarcoCuatro;
	static int balasPorBarco;

	static float velocidad;
	static float tiempoEntreBarcos;

	static float velocidadBala;

public:
	static int getAnchoPantalla();
	static int getAltoPantalla();
	static int getAnchoDeTileAgua();
	static int getZDelAgua();
	static int getTilesExtra();
	static int getMaxAltoSprite();
	static int getMaxAnchoSprite();
	static int getCantidadBarcos();
	static int getZDeBarcos();
	static int getZDelJugador();
	static int getDisparosBarco();
	static int getDisparosBarcoDoble();
	static int getDisparosBarcoCuatro();
	static int getBalasPorBarco();

	static float getVelocidad();
	static float getTiempoEntreBarcos();

	static float getVelocidadBala();

	static sf::Clock timerJuego;
};

}

#endif
