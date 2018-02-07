#ifndef DATOS_H
#define DATOS_H

#include <SFML\System.hpp>

namespace Octavio
{

class Escena;

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
	static int pixelesExtraEnElBarco;
	static int rotacionInicial;
	static int rotacionPoseido;

	static int posicionInicialX;

	static float velocidad;
	static float velocidadJugador;
	static float tiempoEntreBarcos;

	static float velocidadBala;

	static Escena* escenaDelJuego;

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
	static int getPixelesExtraDelBarco();
	static int getPosicionInicialX();
	static int getRotacionInicial();
	static int getRotacionPoseido();

	static float getVelocidad();
	static float getVelocidadJugador();
	static float getTiempoEntreBarcos();

	static float getVelocidadBala();

	static Escena* getEscenaJuego();
	static void setEscenaJuego(Escena* unaEscena);

	static sf::Clock timerJuego;
};

}

#endif
