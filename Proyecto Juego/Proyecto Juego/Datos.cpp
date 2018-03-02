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
int Datos::zDeExplosion = 7;
int Datos::miTextSize = 20;
int Datos::miTextSize2 = 30;
int Datos::posXTexto1 = 10;
int Datos::posXTexto2 = 700;
int Datos::posYTexto1 = 10;
int Datos::posYTexto2 = 40;
int Datos::posXPuntajeMax = 450;
int Datos::posYPuntajeMax = 300;
int Datos::posXPuntajeGO = 450;
int Datos::posYPuntajeGO = 300;
int Datos::zDeFondo = 8;
int Datos::puntajeRecord = 0;

float Datos::velocidad = 0.1;
float Datos::velocidadJugador = 0.15;
float Datos::tiempoEntreBarcos = 2;

float Datos::velocidadBala = 0.3;

bool Datos::musicaMenuOn = false;

bool Datos::gameOver = false;

sf::Clock Datos::timerJuego = sf::Clock();

Escena* Datos::escenaDelJuego = nullptr;
Escena* Datos::escenaPuntos = nullptr;

GameObject* Datos::elGameOver = nullptr;

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

int Datos::getZDeExplosion()
{
	return zDeExplosion;
}

int Datos::getZDeFondo()
{
	return zDeFondo;
}

Escena* Datos::getEscenaJuego()
{
	return escenaDelJuego;
}

void Datos::setEscenaJuego(Escena* unaEscena)
{
	escenaDelJuego = unaEscena;
}

Escena* Datos::getEscenaPuntos()
{
	return escenaPuntos;
}

void Datos::setEscenaPuntos(Escena* unaEscena)
{
	escenaPuntos = unaEscena;
}

GameObject* Datos::getImagenGameOver()
{
	return elGameOver;
}

void Datos::setImagenGameOver(GameObject* unGameObject)
{
	elGameOver = unGameObject;
}

bool Datos::getGameOver()
{
	return gameOver;
}

void Datos::setGameOver(bool terminoElJuego)
{
	gameOver = terminoElJuego;
}

bool Datos::getMusicaMenuOn()
{
	return musicaMenuOn;
}

void Datos::setMusicaMenuOn(bool estaPrendida)
{
	musicaMenuOn = estaPrendida;
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

int Datos::getMiTextSize()
{
	return miTextSize;
}

int Datos::getMiTextSize2()
{
	return miTextSize2;
}

int Datos::getPosXTexto1()
{
	return posXTexto1;
}

int Datos::getPosXTexto2()
{
	return posXTexto2;
}

int Datos::getPosYTexto1()
{
	return posYTexto1;
}

int Datos::getPosYTexto2()
{
	return posYTexto2;
}

int Datos::getPosXPuntajeMax()
{
	return posXPuntajeMax;
}

int Datos::getPosYPuntajeMax()
{
	return posYPuntajeMax;
}

int Datos::getPosXPuntajeGO()
{
	return posXPuntajeGO;
}

int Datos::getPosYPuntajeGO()
{
	return posYPuntajeGO;
}

int Datos::getVidaActual()
{
	return vidaActual;
}

int Datos::getDisparosActuales()
{
	return disparosActuales;
}

int Datos::getPuntosActuales()
{
	return puntosDelJugador;
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

int Datos::getPuntajeRecord()
{
	return puntajeRecord;
}

void Datos::cargarPuntaje()
{
	FILE* pFile = fopen("Assets/puntaje.txt", "r");

	if (pFile != nullptr)
	{
		int num = 0;
		int puntaje = 0;

		while (!feof(pFile))
		{
			fgetc(pFile);
			num++;
		}

		char* miChar = (char*)calloc(num, sizeof(char));

		rewind(pFile);

		for (int i = 0; i < num - 1; i++)
		{
			puntaje = puntaje * 10;
			miChar[i] = fgetc(pFile);
			puntaje = puntaje + (miChar[i] - '0');
		}

		puntajeRecord = puntaje;

		fclose(pFile);
		free(miChar);
	}
}

void Datos::guardarPuntaje(int num)
{
	puntajeRecord = num;

	FILE* pFile = fopen("Assets/puntaje.txt", "w");

	if (pFile != nullptr)
	{
		char *miChar = new char[std::to_string(num).length() + 1];
		strcpy(miChar, (std::to_string(num)).c_str());

		fputs(miChar, pFile);

		delete[] miChar;

		fclose(pFile);
	}
}

}