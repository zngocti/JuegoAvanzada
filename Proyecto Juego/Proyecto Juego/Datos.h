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
	static int vidaBarco;
	static int vidaBarcoDoble;
	static int vidaBarcoCuatro;
	static int balasPorBarco;
	static int pixelesExtraEnElBarco;
	static int rotacionInicial;
	static int rotacionPoseido;
	static int zDeBalas;
	static int zDeMarinero;
	static int puntosBarco;
	static int puntosBarcoDoble;
	static int puntosBarcoCuatro;
	static int disparosActuales;
	static int vidaActual;
	static int puntosDelJugador;
	static int zDeExplosion;
	static int zDeFondo;

	static int posicionInicialX;

	static int miTextSize;
	static int posXTexto1;
	static int posXTexto2;
	static int posYTexto1;
	static int posYTexto2;

	static float velocidad;
	static float velocidadJugador;
	static float tiempoEntreBarcos;

	static float velocidadBala;

	static bool musicaMenuOn;

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
	static int getVidaBarco();
	static int getVidaBarcoDoble();
	static int getVidaBarcoCuatro();
	static int getBalasPorBarco();
	static int getPixelesExtraDelBarco();
	static int getPosicionInicialX();
	static int getRotacionInicial();
	static int getRotacionPoseido();
	static int getZDeBalas();
	static int getZDeMarinero();
	static int getZDeExplosion();
	static int getMiTextSize();
	static int getVidaActual();
	static int getDisparosActuales();
	static int getPuntosActuales();
	static int getPosXTexto1();
	static int getPosXTexto2();
	static int getPosYTexto1();
	static int getPosYTexto2();
	static int getZDeFondo();

	static float getVelocidad();
	static float getVelocidadJugador();
	static float getTiempoEntreBarcos();

	static float getVelocidadBala();

	static void addPuntos(int num);
	static void setBalas(int num);
	static void usarBalas();
	static void setVida(int num);
	static void restarVida();
	static void resetDatos();

	static bool getMusicaMenuOn();
	static void setMusicaMenuOn(bool estaPrendida);

	static Escena* getEscenaJuego();
	static void setEscenaJuego(Escena* unaEscena);

	static sf::Clock timerJuego;
};

}

#endif
