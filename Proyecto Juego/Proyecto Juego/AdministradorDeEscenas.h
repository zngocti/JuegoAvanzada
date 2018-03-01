#ifndef ADMINISTRADORDEESCENAS_H
#define ADMINISTRADORDEESCENAS_H

#include "Escena.h"
#include "GameObject.h"
#include "Lista.cpp"
#include "Assets.h"
#include <SFML/Graphics.hpp>
#include "AdministradorDeInput.h"
#include "AdministradorDeBarcos.h"
#include "Datos.h"
#include "Jugador.h"

namespace Octavio
{

class AdministradorDeEscenas
{
private:
	Escena* primerEscena;
	Lista<Escena*> listaDeEscenas;
	Escena* escenaActual;
	Lista<GameObject*> gameObjectsActuales;
	AdministradorDeInput* miInput;
	AdministradorDeBarcos* misBarcos;
	Jugador* miJugador;

	sf::RenderWindow ventana;

	void verificarBotones();
	void verificarComportamientos();

public:
	AdministradorDeEscenas();
	~AdministradorDeEscenas();

	Escena* crearEscena();
	Escena* getEscenaActual() const;
	Escena* getPrimerEscena() const;

	void iniciarUpdate();
	void dibujarEscena(sf::RenderWindow* window);

	void cambiarEscena(Escena* const &proximaEscena);

	void administrarBarcos(Escena* &escena);

	void checkJugador();
	void verificarEscapeRestart();

	void cerrarJuego();

	void setJugador(Jugador* unJugador);
};

}

#endif
