#include "AdministradorDeBarcos.h"

namespace Octavio
{

	AdministradorDeBarcos* AdministradorDeBarcos::elAdministradorDeBarcos = nullptr;

	AdministradorDeBarcos::AdministradorDeBarcos() : listaDeBarcos(Lista<Barco*>(new Barco())),
												     listaDeBarcosDobles(Lista<BarcoDoble*>(new BarcoDoble())),
													 listaDeBarcosCuatro(Lista<BarcoCuatro*>(new BarcoCuatro())),
													 barco(new sf::Texture), barcoDoble1(new sf::Texture),
													 barcoDoble2(new sf::Texture), barcoCuatro1(new sf::Texture),
													 barcoCuatro2(new sf::Texture), barcoCuatro3(new sf::Texture),
													 wave1(false), wave2(false), wave3(false),
													 preparandoW1(false), preparandoW2(false), preparandoW3(false),
													 contador1(0), contador2(0), contador3(0),
													 tiempo1(sf::seconds(0)), tiempo2(sf::seconds(0)), tiempo3(sf::seconds(0))
	{
		srand(time(0));

		for (int i = 0; i < (Datos::getCantidadBarcos() - 1); i++)
		{
			listaDeBarcos.addBack(new Barco());
			listaDeBarcosDobles.addBack(new BarcoDoble());
			listaDeBarcosCuatro.addBack(new BarcoCuatro());
		}

		Assets::boteGrandeNuevo(*barco);
		Assets::barcoNegroNuevo(*barcoDoble1);
		Assets::barcoNegroRoto2(*barcoDoble2);
		Assets::barcoRojoNuevo(*barcoCuatro1);
		Assets::barcoRojoRoto1(*barcoCuatro2);
		Assets::barcoRojoRoto2(*barcoCuatro3);

		for (int i = 0; i < Datos::getCantidadBarcos(); i++)
		{
			listaDeBarcos[i]->setSprite(*barco);
			listaDeBarcos[i]->setZ(Datos::getZDeBarcos());

			listaDeBarcosDobles[i]->setSprite(*barcoDoble1);
			listaDeBarcosDobles[i]->setSprite2(*barcoDoble2);
			listaDeBarcosDobles[i]->setZ(Datos::getZDeBarcos());

			listaDeBarcosCuatro[i]->setSprite(*barcoCuatro1);
			listaDeBarcosCuatro[i]->setSprite2(*barcoCuatro2);
			listaDeBarcosCuatro[i]->setSprite3(*barcoCuatro3);
			listaDeBarcosCuatro[i]->setZ(Datos::getZDeBarcos());
		}
	}

	AdministradorDeBarcos::~AdministradorDeBarcos()
	{
		delete(barco);
		delete(barcoDoble1);
		delete(barcoDoble2);
		delete(barcoCuatro1);
		delete(barcoCuatro2);
		delete(barcoCuatro3);

		listaDeBarcos.removeAll();
		listaDeBarcosDobles.removeAll();
		listaDeBarcosCuatro.removeAll();
	}

	void AdministradorDeBarcos::agregarBarcos(Escena* &miEscena)
	{
		for (int i = 0; i < Datos::getCantidadBarcos(); i++)
		{
			miEscena->agregarGameObject(listaDeBarcos[i]);
			miEscena->agregarGameObject(listaDeBarcosDobles[i]);
			miEscena->agregarGameObject(listaDeBarcosCuatro[i]);
		}
	}

	AdministradorDeBarcos* AdministradorDeBarcos::crearAdministradorDeBarcos()
	{
		if (elAdministradorDeBarcos == nullptr)
		{
			elAdministradorDeBarcos = new AdministradorDeBarcos();
			return elAdministradorDeBarcos;
		}
		else
		{
			return elAdministradorDeBarcos;
		}
	}

	void AdministradorDeBarcos::setearComportamientos()
	{
		int num = 0;

		if (!wave1)
		{
			num = rand() % 3;

			for (int i = 0; i < Datos::getCantidadBarcos(); i++)
			{
				setBarco(listaDeBarcos[i], num);

			}

			preparandoW1 = true;
			wave1 = true;
		}

		if (!wave2)
		{
			num = rand() % 3;

			for (int i = 0; i < Datos::getCantidadBarcos(); i++)
			{
				setBarco(listaDeBarcosDobles[i], num);
			}

			preparandoW2 = true;
			wave2 = true;
		}

		if (!wave3)
		{
			num = rand() % 3;

			for (int i = 0; i < Datos::getCantidadBarcos(); i++)
			{
				setBarco(listaDeBarcosCuatro[i], num);
			}

			preparandoW3 = true;
			wave3 = true;
		}
	}

	void AdministradorDeBarcos::setBarco(Barco* const &miBarco, int num)
	{
		switch (num)
		{
		case 0:
			miBarco->setComportamiento(new ArribaAbajo());
			break;
		case 1:
			miBarco->setComportamiento(new AbiertoCerrado());
			break;
		default:
			miBarco->setComportamiento(new CentroVolver());
			break;
		}
	}

	void AdministradorDeBarcos::posicionarBarcos()
	{
		if (preparandoW1)
		{
			if (contador1 == Datos::getCantidadBarcos())
			{
				contador1 = 0;
				preparandoW1 = false;
			}
			else if (Datos::timerJuego.getElapsedTime().asSeconds() - tiempo1.asSeconds() >= Datos::getTiempoEntreBarcos())
			{
				if (listaDeBarcos[contador1]->getEstaPoseido())
				{
					contador1++;
				}
				else
				{
					if (listaDeBarcos[contador1]->getPrimero())
					{
						listaDeBarcos[contador1]->setPosition(Datos::getAnchoPantalla() + Datos::getMaxAnchoSprite(), Datos::getAltoPantalla() + Datos::getMaxAltoSprite());
						listaDeBarcos[contador1]->cambiarPrimero();
					}
					else
					{
						listaDeBarcos[contador1]->setPosition(Datos::getAnchoPantalla() + Datos::getMaxAnchoSprite(), 0 - (Datos::getMaxAltoSprite()));
						listaDeBarcos[contador1]->cambiarPrimero();
					}
					contador1++;
					tiempo1 = Datos::timerJuego.getElapsedTime();
				}
			}
		}

		else if (preparandoW2)
		{
			if (contador2 == Datos::getCantidadBarcos())
			{
				contador2 = 0;
				preparandoW2 = false;
			}
			else if (Datos::timerJuego.getElapsedTime().asSeconds() - tiempo2.asSeconds() >= Datos::getTiempoEntreBarcos())
			{
				if (listaDeBarcos[contador2]->getEstaPoseido())
				{
					contador2++;
				}
				else
				{
					if (listaDeBarcosDobles[contador2]->getPrimero())
					{
						listaDeBarcosDobles[contador2]->setPosition(Datos::getAnchoPantalla() + Datos::getMaxAnchoSprite(), Datos::getAltoPantalla() + Datos::getMaxAltoSprite());
						listaDeBarcosDobles[contador2]->cambiarPrimero();
					}
					else
					{
						listaDeBarcosDobles[contador2]->setPosition(Datos::getAnchoPantalla() + Datos::getMaxAnchoSprite(), 0 - (Datos::getMaxAltoSprite()));
						listaDeBarcosDobles[contador2]->cambiarPrimero();
					}
					contador2++;
					tiempo2 = Datos::timerJuego.getElapsedTime();
				}
			}
		}

		else if (preparandoW3)
		{
			if (contador3 == Datos::getCantidadBarcos())
			{
				contador3 = 0;
				preparandoW3 = false;
			}
			else if (Datos::timerJuego.getElapsedTime().asSeconds() - tiempo3.asSeconds() >= Datos::getTiempoEntreBarcos())
			{
				if (listaDeBarcos[contador3]->getEstaPoseido())
				{
					contador3++;
				}
				else
				{
					if (listaDeBarcosDobles[contador3]->getPrimero())
					{
						listaDeBarcosDobles[contador3]->setPosition(Datos::getAnchoPantalla() + Datos::getMaxAnchoSprite(), Datos::getAltoPantalla() + Datos::getMaxAltoSprite());
						listaDeBarcosDobles[contador3]->cambiarPrimero();
					}
					else
					{
						listaDeBarcosDobles[contador3]->setPosition(Datos::getAnchoPantalla() + Datos::getMaxAnchoSprite(), 0 - (Datos::getMaxAltoSprite()));
						listaDeBarcosDobles[contador3]->cambiarPrimero();
					}
					contador3++;
					tiempo3 = Datos::timerJuego.getElapsedTime();
				}
			}
		}
	}

	void AdministradorDeBarcos::checkAtaques()
	{
		for (int i = 0; i < Datos::getCantidadBarcos(); i++)
		{
			if (!listaDeBarcos[i]->getEstaPoseido() && listaDeBarcos[i]->getAtaque())
			{
				listaDeBarcos[i]->atacar();
			}
			if (!listaDeBarcosDobles[i]->getEstaPoseido() && listaDeBarcosDobles[i]->getAtaque())
			{
				listaDeBarcosDobles[i]->atacar();
			}
			if (!listaDeBarcosCuatro[i]->getEstaPoseido() && listaDeBarcosCuatro[i]->getAtaque())
			{
				listaDeBarcosCuatro[i]->atacar();
			}
		}
	}

	bool AdministradorDeBarcos::getWave1() const
	{
		return wave1;
	}

	bool AdministradorDeBarcos::getWave2() const
	{
		return wave2;
	}

	bool AdministradorDeBarcos::getWave3() const
	{
		return wave3;
	}

	bool AdministradorDeBarcos::getPreparandoW1() const
	{
		return preparandoW1;
	}

	bool AdministradorDeBarcos::getPreparandoW2() const
	{
		return preparandoW2;
	}

	bool AdministradorDeBarcos::getPreparandoW3() const
	{
		return preparandoW3;
	}
}