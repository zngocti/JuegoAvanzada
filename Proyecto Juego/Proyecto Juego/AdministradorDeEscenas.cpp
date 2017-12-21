#include "AdministradorDeEscenas.h"

namespace Octavio
{

	AdministradorDeEscenas::AdministradorDeEscenas() : primerEscena(new Escena), listaDeEscenas(Lista<Escena*>(primerEscena)),
													   escenaActual(primerEscena), gameObjectsActuales(primerEscena->getGameObjects()),
													   miInput(AdministradorDeInput::crearAdministradorDeInput()),
													   ventana(sf::VideoMode(Datos::getAnchoPantalla(), Datos::getAltoPantalla()), "SFML works!"),
													   misBarcos(AdministradorDeBarcos::crearAdministradorDeBarcos())
	{

	}

	AdministradorDeEscenas::~AdministradorDeEscenas()
	{
		for (int i = 0; i < listaDeEscenas.count(); i++)
		{
			delete (listaDeEscenas[i]);
		}

		listaDeEscenas.removeAll();
		delete(miInput);
		delete(misBarcos);

	}

	Escena* AdministradorDeEscenas::crearEscena()
	{
		Escena* nuevaEscena = new Escena();
		listaDeEscenas.addBack(nuevaEscena);
		return nuevaEscena;
	}

	Escena* AdministradorDeEscenas::getEscenaActual() const
	{
		return escenaActual;
	}

	Escena* AdministradorDeEscenas::getPrimerEscena() const
	{
		return primerEscena;
	}

	void AdministradorDeEscenas::iniciarUpdate()
	{
		gameObjectsActuales = escenaActual->getGameObjects();

		while (ventana.isOpen())
		{
			sf::Event event;
			while (ventana.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					ventana.close();
			}
			ventana.clear();

			if (escenaActual->getBotones().count() > 0)
			{
				miInput->verificarMouse(*escenaActual, event);
				verificarBotones();
			}

			verificarComportamientos();

			dibujarEscena(&ventana);

			ventana.display();
		}
	}

	void AdministradorDeEscenas::verificarComportamientos()
	{
		misBarcos->setearComportamientos();
		misBarcos->posicionarBarcos();


		for (int i = 0; i < gameObjectsActuales.count(); i++)
		{
			gameObjectsActuales[i]->activarComportamiento();
		}

		misBarcos->checkAtaques();
	}

	void AdministradorDeEscenas::dibujarEscena(sf::RenderWindow* window)
	{
		for (int i = GameObject::getMaximoZ(); i >= 0; i--)
		{
			for (int c = 0; c < gameObjectsActuales.count(); c++)
			{
				if (gameObjectsActuales[c]->getZ() == i)
				{
					window->draw(gameObjectsActuales[c]->getSprite());
				}
			}
		}
	}

	void AdministradorDeEscenas::cerrarJuego()
	{
		ventana.close();
	}

	void AdministradorDeEscenas::verificarBotones()
	{
		for (int i = 0; i < escenaActual->getBotones().count(); i++)
		{
			if ((escenaActual->getBotones())[i]->getEstaActivado())
			{
				(escenaActual->getBotones())[i]->apagarBoton();
				if ((escenaActual->getBotones())[i]->getEscenaObjetivo() == nullptr)
				{
					ventana.close();
				}
				else
				{
					cambiarEscena((escenaActual->getBotones())[i]->getEscenaObjetivo());
					return;
				}
			}
		}
	}

	void AdministradorDeEscenas::cambiarEscena(Escena* const &proximaEscena)
	{
		escenaActual = proximaEscena;
		gameObjectsActuales = escenaActual->getGameObjects();
	}

	void AdministradorDeEscenas::administrarBarcos(Escena* &escena)
	{
		misBarcos->agregarBarcos(escena);
	}
}