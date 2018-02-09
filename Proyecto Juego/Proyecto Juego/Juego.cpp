#include "Juego.h"

namespace Octavio
{

Juego::Juego() : jugador(Jugador::crearJugador()), administradorEscenas(new AdministradorDeEscenas()), listaDeTexturas(Lista<sf::Texture*>(nullptr))
{
	listaDeTexturas.removeFirst();
}

Juego::~Juego()
{
	delete(jugador);
	delete(administradorEscenas);
	destruirTexturas();
}

void Juego::iniciar()
{
	crearEscenas();
	administradorEscenas->setJugador(jugador);
	administradorEscenas->iniciarUpdate();
}


void Juego::crearEscenas()
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
	Escena* primerNivel = administradorEscenas->crearEscena();
	bJugar->setEscenaObjetivo(primerNivel);
	generarNiveles(primerNivel);

	Datos::setEscenaJuego(primerNivel);

	administradorEscenas->administrarBarcos(primerNivel);

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

	sf::Texture* botonVolver1 = new sf::Texture();
	sf::Texture* botonVolver2 = new sf::Texture();
	sf::Texture* botonVolver3 = new sf::Texture();

	listaDeTexturas.addBack(botonVolver1);
	listaDeTexturas.addBack(botonVolver2);
	listaDeTexturas.addBack(botonVolver3);

	Assets::botonVolverNormal(*botonVolver1);
	Assets::botonVolverOver(*botonVolver2);
	Assets::botonVolverApretado(*botonVolver3);

	Boton* bVolverControles = pantallaControles(bControles, fondo)->crearBoton(*botonVolver1, *botonVolver2, *botonVolver3, 800, 650, 0);
	bVolverControles->setEscalaBoton(0.5f, 0.5f);
	bVolverControles->setEscenaObjetivo(administradorEscenas->getPrimerEscena());

	Boton* bVolverPuntajes = pantallaPuntajes(bPuntajes, fondo)->crearBoton(*botonVolver1, *botonVolver2, *botonVolver3, 800, 650, 0);
	bVolverPuntajes->setEscalaBoton(0.5f, 0.5f);
	bVolverPuntajes->setEscenaObjetivo(administradorEscenas->getPrimerEscena());

	Boton* bVolverCreditos = pantallaCreditos(bCreditos, fondo)->crearBoton(*botonVolver1, *botonVolver2, *botonVolver3, 800, 650, 0);
	bVolverCreditos->setEscalaBoton(0.5f, 0.5f);
	bVolverCreditos->setEscenaObjetivo(administradorEscenas->getPrimerEscena());

	bSalir->setEscenaObjetivo(nullptr);
}

void Juego::generarNiveles(Escena* const &miEscena)
{
	sf::Texture* tileAgua = new sf::Texture();
	listaDeTexturas.addBack(tileAgua);
	Assets::agua(*tileAgua);
	
	int num1 = Datos::getAltoPantalla() / Datos::getAnchoDeTileAgua();
	int num2 = (Datos::getAnchoPantalla() / Datos::getAnchoDeTileAgua()) + Datos::getTilesExtra();

	for (int i = 0; i < num1; i++)
	{
		for (int c = 0; c < num2; c++)
		{
			GameObject* nuevoObjeto = miEscena->crearGameObject(*tileAgua, c * Datos::getAnchoDeTileAgua(), i * Datos::getAnchoDeTileAgua(), Datos::getZDelAgua());
			nuevoObjeto->setEscala(2, 2);
			TileIzquierdaEnLoop* unComportamiento = new TileIzquierdaEnLoop();
			nuevoObjeto->setComportamiento(unComportamiento);
		}
	}
}

void Juego::destruirTexturas()
{
	for (int i = 0; i < listaDeTexturas.count(); i++)
	{
		delete(listaDeTexturas[i]);
	}

	listaDeTexturas.removeAll();
}

Escena* Juego::pantallaControles(Boton* const &miBoton, sf::Texture* const &miTextura)
{
	Escena* controles = administradorEscenas->crearEscena();
	controles->crearGameObject(*miTextura, -200, 0, 2);
	miBoton->setEscenaObjetivo(controles);
	return controles;
}

Escena* Juego::pantallaPuntajes(Boton* const &miBoton, sf::Texture* const &miTextura)
{
	Escena* puntajes = administradorEscenas->crearEscena();
	puntajes->crearGameObject(*miTextura, -200, 0, 2);
	miBoton->setEscenaObjetivo(puntajes);
	return puntajes;
}

Escena* Juego::pantallaCreditos(Boton* const &miBoton, sf::Texture* const &miTextura)
{
	Escena* creditos = administradorEscenas->crearEscena();
	creditos->crearGameObject(*miTextura, -200, 0, 2);
	miBoton->setEscenaObjetivo(creditos);
	return creditos;
}

}