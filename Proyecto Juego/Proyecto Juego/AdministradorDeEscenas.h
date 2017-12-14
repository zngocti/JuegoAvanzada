#ifndef ADMINISTRADORDEESCENAS_H
#define ADMINISTRADORDEESCENAS_H

#include "Escena.h"
#include "GameObject.h"
#include "Lista.cpp"
#include <SFML/Graphics.hpp>
#include "AdministradorDeInput.h"


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

	sf::RenderWindow ventana;

	void verificarBotones();

public:
	AdministradorDeEscenas();
	~AdministradorDeEscenas();

	Escena* crearEscena();
	Escena* getEscenaActual() const;
	Escena* getPrimerEscena() const;

	void iniciarUpdate();
	void dibujarEscena(sf::RenderWindow* window);

	void cambiarEscena(Escena* const &proximaEscena);

	void cerrarJuego();
};

}

#endif
