#include "Datos.h"

namespace Octavio
{

int Datos::anchoPantalla = 1024;
int Datos::altoPantalla = 768;
int Datos::anchoDeTileAgua = 128;
int Datos::zDelAgua = 8;
int Datos::tilesExtra = 2;
int Datos::maxAltoSprite = 64;
int Datos::maxAnchoSprite = 128;
int Datos::cantidadDeCadaBarco = 5;
int Datos::zDeBarcos = 6;
int Datos::zDelJugador = 5;
int Datos::disparosBarco = 8;
int Datos::disparosBarcoDoble = 5;
int Datos::disparosBarcoCuatro = 3;
int Datos::vidaBarco = 1;
int Datos::vidaBarcoDoble = 2;
int Datos::vidaBarcoCuatro = 3;
int Datos::balasPorBarco = 12;
int Datos::pixelesExtraEnElBarco = 20;
int Datos::posicionInicialX = 100;
int Datos::rotacionInicial = 90;
int Datos::rotacionPoseido = 270;
int Datos::zDeBalas = 4;
int Datos::zDeMarinero = 3;
int Datos::puntosBarco = 10;
int Datos::puntosBarcoDoble = 20;
int Datos::puntosBarcoCuatro = 40;
int Datos::disparosActuales = 0;
int Datos::vidaActual = 0;
int Datos::puntosDelJugador = 0;

float Datos::velocidad = 0.1;
float Datos::velocidadJugador = 0.3;
float Datos::tiempoEntreBarcos = 2;

float Datos::velocidadBala = 0.2;

sf::Clock Datos::timerJuego = sf::Clock();

Escena* Datos::escenaDelJuego = nullptr;

int Datos::getAnchoPantalla()
{
	return anchoPantalla;
}

int Datos::getAltoPantalla()
{
	return altoPantalla;
}
int Datos::getAnchoDeTileAgua()
{
	return anchoDeTileAgua;
}

int Datos::getZDelAgua()
{
	return zDelAgua;
}

int Datos::getTilesExtra()
{
	return tilesExtra;
}

int Datos::getMaxAltoSprite()
{
	return maxAltoSprite;
}

int Datos::getMaxAnchoSprite()
{
	return maxAnchoSprite;
}

int Datos::getCantidadBarcos()
{
	return cantidadDeCadaBarco;
}

float Datos::getVelocidad()
{
	return velocidad;
}

float Datos::getVelocidadJugador()
{
	return velocidadJugador;
}

float Datos::getTiempoEntreBarcos()
{
	return tiempoEntreBarcos;
}

int Datos::getZDeBarcos()
{
	return zDeBarcos;
}

int Datos::getZDelJugador()
{
	return zDelJugador;
}

int Datos::getDisparosBarco()
{
	return disparosBarco;
}

int Datos::getDisparosBarcoDoble()
{
	return disparosBarcoDoble;
}

int Datos::getDisparosBarcoCuatro()
{
	return disparosBarcoCuatro;
}

int Datos::getVidaBarco()
{
	return vidaBarco;
}

int Datos::getVidaBarcoDoble()
{
	return vidaBarcoDoble;
}

int Datos::getVidaBarcoCuatro()
{
	return vidaBarcoCuatro;
}

int Datos::getBalasPorBarco()
{
	return balasPorBarco;
}

float Datos::getVelocidadBala()
{
	return velocidadBala;
}

int Datos::getPixelesExtraDelBarco()
{
	return pixelesExtraEnElBarco;
}

int Datos::getPosicionInicialX()
{
	return posicionInicialX;
}

int Datos::getRotacionInicial()
{
	return rotacionInicial;
}

int Datos::getRotacionPoseido()
{
	return rotacionPoseido;
}

int Datos::getZDeBalas()
{
	return zDeBalas;
}

int Datos::getZDeMarinero()
{
	return zDeMarinero;
}

Escena* Datos::getEscenaJuego()
{
	return escenaDelJuego;
}

void Datos::setEscenaJuego(Escena* unaEscena)
{
	escenaDelJuego = unaEscena;
}

void Datos::addPuntos(int num)
{
	switch (num)
	{
	case 1:
		puntosDelJugador = puntosDelJugador + puntosBarco;
		break;
	case 2:
		puntosDelJugador = puntosDelJugador + puntosBarcoDoble;
		break;
	case 3:
		puntosDelJugador = puntosDelJugador + puntosBarcoCuatro;
		break;
	default:
		break;
	}
}

void Datos::setBalas(int num)
{
	switch (num)
	{
	case 1:
		disparosActuales = disparosBarco;
		break;
	case 2:
		disparosActuales = disparosBarcoDoble;
		break;
	case 3:
		disparosActuales = disparosBarcoCuatro;
		break;
	default:
		break;
	}
}

void Datos::usarBalas()
{
	disparosActuales--;
}

void Datos::setVida(int num)
{
	vidaActual = num;
}

void Datos::restarVida()
{
	vidaActual--;
}

void Datos::resetDatos()
{
	vidaActual = vidaBarco;
	disparosActuales = disparosBarco;
	puntosDelJugador = 0;
}

}