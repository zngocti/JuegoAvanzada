#include "Juego.h"

namespace Octavio
{

Juego::Juego() : jugador(new Jugador()), administradorEscenas(new AdministradorDeEscenas()), listaDeTexturas(Lista<sf::Texture*>(nullptr))
{
	listaDeTexturas.removeFirst();
}

Juego::~Juego()
{
	delete(jugador);
	delete(administradorEscenas);
	destruirMenu();
}

void Juego::iniciar()
{
	crearMenu();
	administradorEscenas->iniciarUpdate();
}

void Juego::crearMenu()
{
	sf::Texture* fondo = new sf::Texture();

	listaDeTexturas.addBack(fondo);

	Assets::menuBackground(*fondo);

	administradorEscenas->getPrimerEscena()->crearGameObject(*fondo, -200, 0, 2);

	sf::Texture* botonJugar1 = new sf::Texture();
	sf::Texture* botonJugar2 = new sf::Texture();
	sf::Texture* botonJugar3 = new sf::Texture();

	listaDeTexturas.addBack(botonJugar1);
	listaDeTexturas.addBack(botonJugar2);
	listaDeTexturas.addBack(botonJugar3);

	Assets::botonJugarNormal(*botonJugar1);
	Assets::botonJugarOver(*botonJugar2);
	Assets::botonJugarApretado(*botonJugar3);

	Boton* bJugar = administradorEscenas->getPrimerEscena()->crearBoton(*botonJugar1, *botonJugar2, *botonJugar3, 50, 350, 0);
	bJugar->setEscalaBoton(0.5f, 0.5f);
	bJugar->setEscenaObjetivo(administradorEscenas->crearEscena());

	sf::Texture* botonControles1 = new sf::Texture();
	sf::Texture* botonControles2 = new sf::Texture();
	sf::Texture* botonControles3 = new sf::Texture();

	listaDeTexturas.addBack(botonControles1);
	listaDeTexturas.addBack(botonControles2);
	listaDeTexturas.addBack(botonControles3);

	Assets::botonControlesNormal(*botonControles1);
	Assets::botonControlesOver(*botonControles2);
	Assets::botonControlesApretado(*botonControles3);

	Boton* bControles = administradorEscenas->getPrimerEscena()->crearBoton(*botonControles1, *botonControles2, *botonControles3, 50, 500, 0);
	bControles->setEscalaBoton(0.5f, 0.5f);
	bControles->setEscenaObjetivo(administradorEscenas->crearEscena());

	sf::Texture* botonPuntajes1 = new sf::Texture();
	sf::Texture* botonPuntajes2 = new sf::Texture();
	sf::Texture* botonPuntajes3 = new sf::Texture();

	listaDeTexturas.addBack(botonPuntajes1);
	listaDeTexturas.addBack(botonPuntajes2);
	listaDeTexturas.addBack(botonPuntajes3);

	Assets::botonPuntajesNormal(*botonPuntajes1);
	Assets::botonPuntajesOver(*botonPuntajes2);
	Assets::botonPuntajesApretado(*botonPuntajes3);

	Boton* bPuntajes = administradorEscenas->getPrimerEscena()->crearBoton(*botonPuntajes1, *botonPuntajes2, *botonPuntajes3, 50, 650, 0);
	bPuntajes->setEscalaBoton(0.5f, 0.5f);
	bPuntajes->setEscenaObjetivo(administradorEscenas->crearEscena());

	sf::Texture* botonCreditos1 = new sf::Texture();
	sf::Texture* botonCreditos2 = new sf::Texture();
	sf::Texture* botonCreditos3 = new sf::Texture();

	listaDeTexturas.addBack(botonCreditos1);
	listaDeTexturas.addBack(botonCreditos2);
	listaDeTexturas.addBack(botonCreditos3);

	Assets::botonCreditosNormal(*botonCreditos1);
	Assets::botonCreditosOver(*botonCreditos2);
	Assets::botonCreditosApretado(*botonCreditos3);

	Boton* bCreditos = administradorEscenas->getPrimerEscena()->crearBoton(*botonCreditos1, *botonCreditos2, *botonCreditos3, 350, 650, 0);
	bCreditos->setEscalaBoton(0.5f, 0.5f);
	bCreditos->setEscenaObjetivo(administradorEscenas->crearEscena());

	sf::Texture* botonSalir1 = new sf::Texture();
	sf::Texture* botonSalir2 = new sf::Texture();
	sf::Texture* botonSalir3 = new sf::Texture();

	listaDeTexturas.addBack(botonSalir1);
	listaDeTexturas.addBack(botonSalir2);
	listaDeTexturas.addBack(botonSalir3);

	Assets::botonSalirNormal(*botonSalir1);
	Assets::botonSalirOver(*botonSalir2);
	Assets::botonSalirApretado(*botonSalir3);

	Boton* bSalir = administradorEscenas->getPrimerEscena()->crearBoton(*botonSalir1, *botonSalir2, *botonSalir3, 650, 650, 0);
	bSalir->setEscalaBoton(0.5f, 0.5f);
	bSalir->setEscenaObjetivo(nullptr);

}

void Juego::destruirMenu()
{
	for (int i = 0; i < listaDeTexturas.count(); i++)
	{
		delete(listaDeTexturas[i]);
	}

	listaDeTexturas.removeAll();
}

}