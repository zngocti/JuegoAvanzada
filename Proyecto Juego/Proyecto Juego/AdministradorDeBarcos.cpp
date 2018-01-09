#include "AdministradorDeBarcos.h"

namespace Octavio
{

	AdministradorDeBarcos* AdministradorDeBarcos::elAdministradorDeBarcos = nullptr;
	int AdministradorDeBarcos::numeroWave = 1;

	AdministradorDeBarcos::AdministradorDeBarcos() : listaDeBarcos(Lista<Barco*>(new Barco())),
												     listaDeBarcosDobles(Lista<BarcoDoble*>(new BarcoDoble())),
													 listaDeBarcosCuatro(Lista<BarcoCuatro*>(new BarcoCuatro())),
													 barco(new sf::Texture), barcoDoble1(new sf::Texture),
													 barcoDoble2(new sf::Texture), barcoCuatro1(new sf::Texture),
													 barcoCuatro2(new sf::Texture), barcoCuatro3(new sf::Texture),
													 wave1(false), wave2(false), wave3(false),
													 preparandoW1(true), preparandoW2(true), preparandoW3(true),
													 posicionandoW1(false), posicionandoW2(false), posicionandoW3(false),
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
		if (preparandoW1 && numeroWave == 1)
		{
			num = rand() % 3;
			for (int i = 0; i < Datos::getCantidadBarcos(); i++)
			{
				setBarco(listaDeBarcos[i], num);				
			}
			preparandoW1 = false;
			posicionandoW1 = true;
		}

		else if (preparandoW2 && numeroWave == 2)
		{
			num = rand() % 3;
			for (int i = 0; i < Datos::getCantidadBarcos(); i++)
			{
				setBarco(listaDeBarcosDobles[i], num);
			}
			preparandoW2 = false;
			posicionandoW2 = true;
		}
		
		if (preparandoW3 && numeroWave == 3)
		{
			num = rand() % 3;
			for (int i = 0; i < Datos::getCantidadBarcos(); i++)
			{
				setBarco(listaDeBarcosCuatro[i], num);
			}
			preparandoW3 = false;
			posicionandoW3 = true;
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
			if (contador1 >= Datos::getCantidadBarcos() && posicionandoW1)
			{
				contador1 = 0;
				posicionandoW1 = false;
			}
			if (contador2 >= Datos::getCantidadBarcos() && posicionandoW2)
			{
				contador2 = 0;
				posicionandoW2 = false;
			}
			if (contador3 >= Datos::getCantidadBarcos() && posicionandoW3)
			{
				contador3 = 0;
				posicionandoW3 = false;
			}

			if (numeroWave == 1 && posicionandoW1)
			{
				if (listaDeBarcos[contador1]->getEstaPoseido())
				{
					contador1++;
				}
				else if (!(listaDeBarcos[contador1]->getUso()) && posicionandoW1)
				{
					posicionInicial(listaDeBarcos[contador1]);
					listaDeBarcos[contador1]->cambiarPrimero();
					listaDeBarcos[contador1]->restartUso();
					contador1++;
					tiempo1 = Datos::timerJuego.getElapsedTime();
				}
			}
			
			else if (numeroWave == 2 && posicionandoW2)
			{
				if (listaDeBarcosDobles[contador2]->getEstaPoseido())
				{
					contador2++;
				}
				else if (!(listaDeBarcosDobles[contador2]->getUso()) && posicionandoW2)
				{
					posicionInicial(listaDeBarcosDobles[contador2]);
					listaDeBarcosDobles[contador2]->cambiarPrimero();
					listaDeBarcosDobles[contador2]->restartUso();
					contador2++;
					tiempo2 = Datos::timerJuego.getElapsedTime();
				}
			}

			else if (posicionandoW3)
			{
				if (listaDeBarcosCuatro[contador3]->getEstaPoseido())
				{
					contador3++;
				}
				else if (!(listaDeBarcosCuatro[contador3]->getUso()) && posicionandoW3)
				{
					posicionInicial(listaDeBarcosCuatro[contador3]);
					listaDeBarcosCuatro[contador3]->cambiarPrimero();
					listaDeBarcosCuatro[contador3]->restartUso();
					contador3++;
					tiempo3 = Datos::timerJuego.getElapsedTime();
				}
			}
		}
	}

	void AdministradorDeBarcos::posicionInicial(Barco* const &miBarco)
	{
		if (miBarco->getPrimero())
		{
			miBarco->getSprite().setPosition(Datos::getAnchoPantalla() + Datos::getMaxAnchoSprite(), 0 - (Datos::getMaxAltoSprite()));
		}
		else
		{
			miBarco->getSprite().setPosition(Datos::getAnchoPantalla() + Datos::getMaxAnchoSprite(), Datos::getAltoPantalla() + Datos::getMaxAltoSprite());
		}
	}

	void AdministradorDeBarcos::checkAtaques()
	{
		for (int i = 0; i < Datos::getCantidadBarcos(); i++)
		{
			if (!(listaDeBarcos[i]->getEstaPoseido()) && listaDeBarcos[i]->getAtaque())
			{
				listaDeBarcos[i]->atacar();
			}
			if (!(listaDeBarcosDobles[i]->getEstaPoseido()) && listaDeBarcosDobles[i]->getAtaque())
			{
				listaDeBarcosDobles[i]->atacar();
			}
			if (!(listaDeBarcosCuatro[i]->getEstaPoseido()) && listaDeBarcosCuatro[i]->getAtaque())
			{
				listaDeBarcosCuatro[i]->atacar();
			}
		}
	}

	void AdministradorDeBarcos::checkUso()
	{
		bool cambioDeWave = true;
		for (int i = 0; i < Datos::getCantidadBarcos(); i++)
		{
			if (numeroWave == 1)
			{
				if (!(listaDeBarcos[i]->getEstaPoseido()) && listaDeBarcos[i]->getUso())
				{
					cambioDeWave = false;
				}
			}
			else if (numeroWave == 2)
			{
				if (!(listaDeBarcosDobles[i]->getEstaPoseido()) && listaDeBarcosDobles[i]->getUso())
				{
					cambioDeWave = false;
				}
			}
			else
			{
				if (!(listaDeBarcosCuatro[i]->getEstaPoseido()) && listaDeBarcosCuatro[i]->getUso())
				{
					cambioDeWave = false;
				}
			}
		}

		if (cambioDeWave)
		{
			if (numeroWave == 1)
			{
				numeroWave = 2;
				preparandoW2 = true;
			}
			else if (numeroWave == 2)
			{
				numeroWave = 3;
				preparandoW3 = true;
			}
			else
			{
				numeroWave = 1;
				preparandoW1 = true;
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

	bool AdministradorDeBarcos::getPosicionandoW1() const
	{
		return posicionandoW1;
	}

	bool AdministradorDeBarcos::getPosicionandoW2() const
	{
		return posicionandoW2;
	}

	bool AdministradorDeBarcos::getPosicionandoW3() const
	{
		return posicionandoW3;
	}
}