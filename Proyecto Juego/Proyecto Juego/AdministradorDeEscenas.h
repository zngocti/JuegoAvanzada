#ifndef ADMINISTRADORDEESCENAS_H
#define ADMINISTRADORDEESCENAS_H

#include "Escena.h"
#include "GameObject.h"
#include "Lista.cpp"
#include "Assets.h"
#include <SFML/Graphics.hpp>
#include "AdministradorDeInput.h"
#include "Datos.h"


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

	void revisarFondo();

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
