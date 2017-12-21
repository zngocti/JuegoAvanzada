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
			listaDeBarcos[i]->setMedio();
			listaDeBarcos[i]->setRotation(90);

			listaDeBarcosDobles[i]->setSprite(*barcoDoble1);
			listaDeBarcosDobles[i]->setSprite2(*barcoDoble2);
			listaDeBarcosDobles[i]->setZ(Datos::getZDeBarcos());
			listaDeBarcosDobles[i]->setMedio();
			listaDeBarcosDobles[i]->setMedio2();
			listaDeBarcosDobles[i]->setRotation(90);
			listaDeBarcosDobles[i]->setRotation2(90);

			listaDeBarcosCuatro[i]->setSprite(*barcoCuatro1);
			listaDeBarcosCuatro[i]->setSprite2(*barcoCuatro2);
			listaDeBarcosCuatro[i]->setSprite3(*barcoCuatro3);
			listaDeBarcosCuatro[i]->setZ(Datos::getZDeBarcos());
			listaDeBarcosCuatro[i]->setMedio();
			listaDeBarcosCuatro[i]->setMedio2();
			listaDeBarcosCuatro[i]->setMedio3();
			listaDeBarcosCuatro[i]->setRotation(90);
			listaDeBarcosCuatro[i]->setRotation2(90);
			listaDeBarcosCuatro[i]->setRotation3(90);
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
		for (int i = 0; i < Datos::getCantidadBarcos(); i++)
		{
			num = rand() % 3;
			setBarco(listaDeBarcos[i], num);

		}

		for (int i = 0; i < Datos::getCantidadBarcos(); i++)
		{
			num = rand() % 3;
			setBarco(listaDeBarcosDobles[i], num);
		}
		
		for (int i = 0; i < Datos::getCantidadBarcos(); i++)
		{
			num = rand() % 3;
			setBarco(listaDeBarcosCuatro[i], num);
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
		int num = 0;
		num = rand() % 3;

		if (Datos::timerJuego.getElapsedTime().asSeconds() - tiempo1.asSeconds() >= Datos::getTiempoEntreBarcos())
		{
			if (contador1 >= Datos::getCantidadBarcos())
			{
				contador1 = 0;
			}
			if (contador2 >= Datos::getCantidadBarcos())
			{
				contador2 = 0;
			}
			if (contador3 >= Datos::getCantidadBarcos())
			{
				contador3 = 0;
			}

			switch (num)
			{
			case 1:
				if (listaDeBarcos[contador1]->getEstaPoseido())
				{
					contador1++;
				}
				else if (!listaDeBarcos[contador1]->getUso())
				{
					if (listaDeBarcos[contador1]->getPrimero())
					{
						listaDeBarcos[contador1]->setPosition(Datos::getAnchoPantalla() + Datos::getMaxAnchoSprite(), 0 - (Datos::getMaxAltoSprite()));
						listaDeBarcos[contador1]->cambiarPrimero();
					}
					else
					{
						listaDeBarcos[contador1]->setPosition(Datos::getAnchoPantalla() + Datos::getMaxAnchoSprite(), Datos::getAltoPantalla() + Datos::getMaxAltoSprite());
						listaDeBarcos[contador1]->cambiarPrimero();
					}
					listaDeBarcos[contador1]->restartUso();
					contador1++;
					tiempo1 = Datos::timerJuego.getElapsedTime();
				}
				else
				{
					contador1++;
				}
				break;
			case 2:
				if (listaDeBarcosDobles[contador2]->getEstaPoseido())
				{
					contador2++;
				}
				else if (!listaDeBarcosDobles[contador2]->getUso())
				{
					if (listaDeBarcos[contador2]->getPrimero())
					{
						listaDeBarcos[contador2]->setPosition(Datos::getAnchoPantalla() + Datos::getMaxAnchoSprite(), 0 - (Datos::getMaxAltoSprite()));
						listaDeBarcos[contador2]->cambiarPrimero();
					}
					else
					{
						listaDeBarcos[contador2]->setPosition(Datos::getAnchoPantalla() + Datos::getMaxAnchoSprite(), Datos::getAltoPantalla() + Datos::getMaxAltoSprite());
						listaDeBarcos[contador2]->cambiarPrimero();
					}
					listaDeBarcos[contador2]->restartUso();
					contador2++;
					tiempo1 = Datos::timerJuego.getElapsedTime();
				}
				else
				{
					contador2++;
				}
				break;
			default:
				if (listaDeBarcosCuatro[contador3]->getEstaPoseido())
				{
					contador3++;
				}
				else if(!listaDeBarcosCuatro[contador3]->getUso())
				{
					if (listaDeBarcos[contador3]->getPrimero())
					{
						listaDeBarcos[contador3]->setPosition(Datos::getAnchoPantalla() + Datos::getMaxAnchoSprite(), 0 - (Datos::getMaxAltoSprite()));
						listaDeBarcos[contador3]->cambiarPrimero();
					}
					else
					{
						listaDeBarcos[contador3]->setPosition(Datos::getAnchoPantalla() + Datos::getMaxAnchoSprite(), Datos::getAltoPantalla() + Datos::getMaxAltoSprite());
						listaDeBarcos[contador3]->cambiarPrimero();
					}
					listaDeBarcos[contador3]->restartUso();
					contador3++;
					tiempo1 = Datos::timerJuego.getElapsedTime();
				}
				else
				{
					contador3++;
				}
				break;
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