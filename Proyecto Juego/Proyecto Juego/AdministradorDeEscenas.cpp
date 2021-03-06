#include "AdministradorDeEscenas.h"

namespace Octavio
{

AdministradorDeEscenas::AdministradorDeEscenas() : primerEscena(new Escena()), listaDeEscenas(Lista<Escena*>(primerEscena)),
													escenaActual(primerEscena), gameObjectsActuales(primerEscena->getGameObjects()),
													miInput(AdministradorDeInput::crearAdministradorDeInput()),
													ventana(sf::VideoMode(Datos::getAnchoPantalla(), Datos::getAltoPantalla()), "Septimo Mar"),
													misBarcos(AdministradorDeBarcos::crearAdministradorDeBarcos()), miJugador(nullptr)
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

void AdministradorDeEscenas::setJugador(Jugador* unJugador)
{
	miJugador = unJugador;
}

void AdministradorDeEscenas::iniciarUpdate()
{
	gameObjectsActuales = escenaActual->getGameObjects();
	Assets::playMusica(0);

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

		miInput->verificarTeclas(miJugador, event, misBarcos->getBarcoDelJugador());

		verificarComportamientos();

		verificarEscapeRestart();

		dibujarEscena(&ventana);

		ventana.display();
	}
}

void AdministradorDeEscenas::verificarComportamientos()
{
	if (escenaActual == Datos::getEscenaJuego())
	{
		misBarcos->setearComportamientos();
		misBarcos->posicionarBarcos();

		for (int i = 0; i < gameObjectsActuales.count(); i++)
		{
			gameObjectsActuales[i]->activarComportamiento();
		}

		misBarcos->checkUso();
		misBarcos->checkAtaques();
		misBarcos->checkImpactosBarcos();
		misBarcos->checkImpactosBala();
		misBarcos->checkTimers();
		misBarcos->actualizarTexto();
		checkJugador();
	}
	else
	{
		for (int i = 0; i < gameObjectsActuales.count(); i++)
		{
			gameObjectsActuales[i]->activarComportamiento();
		}
	}
}

void AdministradorDeEscenas::dibujarEscena(sf::RenderWindow* window)
{
	for (int i = GameObject::getMaximoZ(); i >= 0; i--)
	{
		for (int c = 0; c < gameObjectsActuales.count(); c++)
		{
			if (gameObjectsActuales[c]->getUso() && gameObjectsActuales[c]->getZ() == i)
			{
				window->draw(gameObjectsActuales[c]->getSprite());
			}
		}
	}

	if (escenaActual == Datos::getEscenaJuego())
	{
		window->draw(*(misBarcos->getTextoResistencia()));
		window->draw(*(misBarcos->getTextoDisparos()));
		window->draw(*(misBarcos->getTextoPuntaje()));

		if (Datos::getGameOver())
		{
			window->draw(*(misBarcos->getTextoPuntajeGO()));
		}

	}
	else if (escenaActual == Datos::getEscenaPuntos())
	{
		window->draw(*(misBarcos->getTextoPuntajeMax()));
	}
}

void AdministradorDeEscenas::checkJugador()
{
	if (miJugador->getJugando())
	{
		if (!(misBarcos->checkJugando()))
		{
			miJugador->setJugando(false);
			misBarcos->activarGameOver();
		}
	}
}

void AdministradorDeEscenas::verificarEscapeRestart()
{
	if (miInput->getSaliendo())
	{
		miInput->resetSaliendo();
		miJugador->setJugando(false);
		misBarcos->resetAdministrador();
		cambiarEscena(primerEscena);
	}
	else if (miInput->getRestart())
	{
		Assets::stopMusica();
		Assets::playMusica(1);
		miInput->resetRestart();
		misBarcos->resetAdministrador();
		miJugador->setJugando(true);
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

	if (escenaActual == Datos::getEscenaJuego())
	{
		Assets::stopMusica();
		Assets::playMusica(1);
		miJugador->empezarJuego();
	}
	else if (escenaActual == primerEscena && !Datos::getMusicaMenuOn())
	{
		Assets::stopMusica();
		Assets::playMusica(0);
	}
}

void AdministradorDeEscenas::administrarBarcos(Escena* &escena)
{
	misBarcos->agregarBarcos(escena);
}

}