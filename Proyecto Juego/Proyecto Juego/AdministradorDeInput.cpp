#include "AdministradorDeInput.h"

namespace Octavio
{

AdministradorDeInput* AdministradorDeInput::administradorCreado = nullptr;

AdministradorDeInput::AdministradorDeInput() : clickeando(false)
{

}

AdministradorDeInput::~AdministradorDeInput()
{
	administradorCreado = nullptr;
}

AdministradorDeInput* AdministradorDeInput::crearAdministradorDeInput()
{
	if (administradorCreado == nullptr)
	{
		administradorCreado = new AdministradorDeInput();
		return administradorCreado;
	}
	else
	{
		return administradorCreado;
	}
}

void AdministradorDeInput::verificarMouse(const Escena &escenaActual, const sf::Event &evento)
{
	if (evento.type == sf::Event::MouseMoved)
	{
		for (int i = 0; i < escenaActual.getBotones().count(); i++)
		{
			if (!(escenaActual.getBotones())[i]->getClickeado())
			{
				if ((escenaActual.getBotones())[i]->getSprite().getGlobalBounds().contains(evento.mouseMove.x, evento.mouseMove.y) && !(escenaActual.getBotones())[i]->getOver())
				{
					escenaActual.getBotones()[i]->iniciaOver();
				}
				else if (!(escenaActual.getBotones())[i]->getSprite().getGlobalBounds().contains(evento.mouseMove.x, evento.mouseMove.y) && (escenaActual.getBotones())[i]->getOver())
				{
					escenaActual.getBotones()[i]->finOver();
				}
			}
		}
	}
	else if (evento.type == sf::Event::MouseButtonPressed)
	{
		for (int i = 0; i < escenaActual.getBotones().count(); i++)
		{
			if ((escenaActual.getBotones())[i]->getSprite().getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y) && !(escenaActual.getBotones())[i]->getClickeado())
			{
				escenaActual.getBotones()[i]->iniciaClick();
			}
		}
	}
	else if (evento.type == sf::Event::MouseButtonReleased)
	{
		for (int i = 0; i < escenaActual.getBotones().count(); i++)
		{
			if ((escenaActual.getBotones())[i]->getSprite().getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y) && (escenaActual.getBotones())[i]->getClickeado())
			{
				escenaActual.getBotones()[i]->activarBoton();
			}
			else if (!(escenaActual.getBotones())[i]->getSprite().getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y) && (escenaActual.getBotones())[i]->getClickeado())
			{
				escenaActual.getBotones()[i]->finClick();
			}
		}
	}
}

}