#include "AdministradorDeEscenas.h"
#include "Assets.h"

namespace Octavio
{
	AdministradorDeEscenas::AdministradorDeEscenas() : primerEscena(new Escena), listaDeEscenas(Lista<Escena*>(primerEscena))
	{

	}

	AdministradorDeEscenas::~AdministradorDeEscenas()
	{
		listaDeEscenas.removeAll();
	}

	Escena* AdministradorDeEscenas::CrearEscena()
	{
		Escena* nuevaEscena = new Escena();
		listaDeEscenas.addBack(nuevaEscena);
		return nuevaEscena;
	}

	void AdministradorDeEscenas::IniciarUpdate()
	{
		sf::Texture* miTextura = new sf::Texture();
		sf::Sprite miSprite;

		sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

		if (Assets::menuBackground(*miTextura))
		{
			miSprite.setTexture(*miTextura);
			miSprite.setPosition(-350, 0);

			while (window.isOpen())
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();
				}
				window.clear();

				window.draw(miSprite);

				window.display();
			}
		}
	}
}