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
													preparandoW1(true), preparandoW2(true), preparandoW3(true),
													posicionandoW1(false), posicionandoW2(false), posicionandoW3(false),
													contador1(0), contador2(0), contador3(0),
													tiempo1(sf::seconds(0)), tiempo2(sf::seconds(0)), tiempo3(sf::seconds(0)),
													barcoDelJugador(nullptr)
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
		listaDeBarcos[i]->setSprite1(*barco);
		listaDeBarcos[i]->setZ(Datos::getZDeBarcos());
		listaDeBarcos[i]->setMedio();
		listaDeBarcos[i]->setMedio1();
		listaDeBarcos[i]->setRotation(Datos::getRotacionInicial());
		listaDeBarcos[i]->setRotation1(Datos::getRotacionInicial());

		listaDeBarcosDobles[i]->setSprite(*barcoDoble1);
		listaDeBarcosDobles[i]->setSprite1(*barcoDoble1);
		listaDeBarcosDobles[i]->setSprite2(*barcoDoble2);
		listaDeBarcosDobles[i]->setZ(Datos::getZDeBarcos());
		listaDeBarcosDobles[i]->setMedio();
		listaDeBarcosDobles[i]->setMedio1();
		listaDeBarcosDobles[i]->setMedio2();
		listaDeBarcosDobles[i]->setRotation(Datos::getRotacionInicial());
		listaDeBarcosDobles[i]->setRotation1(Datos::getRotacionInicial());
		listaDeBarcosDobles[i]->setRotation2(Datos::getRotacionInicial());

		listaDeBarcosCuatro[i]->setSprite(*barcoCuatro1);
		listaDeBarcosCuatro[i]->setSprite1(*barcoCuatro1);
		listaDeBarcosCuatro[i]->setSprite2(*barcoCuatro2);
		listaDeBarcosCuatro[i]->setSprite3(*barcoCuatro3);
		listaDeBarcosCuatro[i]->setZ(Datos::getZDeBarcos());
		listaDeBarcosCuatro[i]->setMedio();
		listaDeBarcosCuatro[i]->setMedio1();
		listaDeBarcosCuatro[i]->setMedio2();
		listaDeBarcosCuatro[i]->setMedio3();
		listaDeBarcosCuatro[i]->setRotation(Datos::getRotacionInicial());
		listaDeBarcosCuatro[i]->setRotation1(Datos::getRotacionInicial());
		listaDeBarcosCuatro[i]->setRotation2(Datos::getRotacionInicial());
		listaDeBarcosCuatro[i]->setRotation3(Datos::getRotacionInicial());
	}

	Barco::getMarinero();
	setBarcoInicial();
	Datos::resetDatos();
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
		miEscena->agregarGameObject(listaDeBarcos[i]->getExplosion());
		for (int c = 0; c < listaDeBarcos[i]->getListaDeBalas().count(); c++)
		{
			miEscena->agregarGameObject(listaDeBarcos[i]->getListaDeBalas()[c]);
		}
		
		miEscena->agregarGameObject(listaDeBarcosDobles[i]);
		miEscena->agregarGameObject(listaDeBarcosDobles[i]->getExplosion());
		for (int c = 0; c < listaDeBarcosDobles[i]->getListaDeBalas().count(); c++)
		{
			miEscena->agregarGameObject(listaDeBarcosDobles[i]->getListaDeBalas()[c]);
		}
		
		miEscena->agregarGameObject(listaDeBarcosCuatro[i]);
		miEscena->agregarGameObject(listaDeBarcosCuatro[i]->getExplosion());
		for (int c = 0; c < listaDeBarcosCuatro[i]->getListaDeBalas().count(); c++)
		{
			miEscena->agregarGameObject(listaDeBarcosCuatro[i]->getListaDeBalas()[c]);
		}
	}

	miEscena->agregarGameObject(Barco::getMarinero());
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
		
	else if (preparandoW3 && numeroWave == 3)
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

	if (miBarco->getEstaPoseido())
	{
		miBarco->restartUso();
	}
	else
	{
		miBarco->resetBarco();
	}
}

void AdministradorDeBarcos::posicionarBarcos()
{
	int num = 0;
	num = rand() % 3;

	if (numeroWave == 1)
	{
		if (Datos::timerJuego.getElapsedTime().asSeconds() - tiempo1.asSeconds() >= Datos::getTiempoEntreBarcos())
		{
			if (contador1 >= Datos::getCantidadBarcos())
			{
				contador1 = 0;
				posicionandoW1 = false;
			}

			if (posicionandoW1)
			{
				if (listaDeBarcos[contador1]->getEstaPoseido())
				{
					contador1++;
				}
				if (contador1 < Datos::getCantidadBarcos())
				{
					if (!(listaDeBarcos[contador1]->getUso()))
					{
						posicionInicial(listaDeBarcos[contador1]);
						listaDeBarcos[contador1]->cambiarPrimero();
						listaDeBarcos[contador1]->restartUso();
						contador1++;
						tiempo1 = Datos::timerJuego.getElapsedTime();
					}
				}
			}
		}
	}

	else if (numeroWave == 2)
	{
		if (Datos::timerJuego.getElapsedTime().asSeconds() - tiempo2.asSeconds() >= Datos::getTiempoEntreBarcos())
		{
			if (contador2 >= Datos::getCantidadBarcos())
			{
				contador2 = 0;
				posicionandoW2 = false;
			}

			if (posicionandoW2)
			{
				if (listaDeBarcosDobles[contador2]->getEstaPoseido())
				{
					contador2++;
				}
				if (contador2 < Datos::getCantidadBarcos())
				{
					if (!(listaDeBarcosDobles[contador2]->getUso()))
					{
						posicionInicial(listaDeBarcosDobles[contador2]);
						listaDeBarcosDobles[contador2]->cambiarPrimero();
						listaDeBarcosDobles[contador2]->restartUso();
						contador2++;
						tiempo2 = Datos::timerJuego.getElapsedTime();
					}
				}
			}
		}
	}

	else if (numeroWave == 3)
	{
		if (Datos::timerJuego.getElapsedTime().asSeconds() - tiempo3.asSeconds() >= Datos::getTiempoEntreBarcos())
		{
			if (contador3 >= Datos::getCantidadBarcos())
			{
				contador3 = 0;
				posicionandoW3 = false;
			}

			if (posicionandoW3)
			{
				if (listaDeBarcosCuatro[contador3]->getEstaPoseido())
				{
					contador3++;
				}
				if (contador2 < Datos::getCantidadBarcos())
				{
					if (!(listaDeBarcosCuatro[contador3]->getUso()))
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
	}
}

void AdministradorDeBarcos::posicionInicial(Barco* const &miBarco)
{
	if (miBarco->getPrimero())
	{
		miBarco->setPosition(Datos::getAnchoPantalla() + Datos::getMaxAnchoSprite(), 0 - (Datos::getMaxAltoSprite()));
	}
	else
	{
		miBarco->setPosition(Datos::getAnchoPantalla() + Datos::getMaxAnchoSprite(), Datos::getAltoPantalla() + Datos::getMaxAltoSprite());
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

void AdministradorDeBarcos::checkImpactosBarcos()
{
	for (int i = 0; i < Datos::getCantidadBarcos(); i++)
	{
		if (listaDeBarcos[i]->getUso() && listaDeBarcos[i] != barcoDelJugador)
		{
			if (barcoDelJugador->getSprite().getGlobalBounds().intersects(listaDeBarcos[i]->getSprite().getGlobalBounds()))
			{
				barcoDelJugador->impactoDeBarco();
				listaDeBarcos[i]->impactoDeBarco();
			}
		}

		if (listaDeBarcosDobles[i]->getUso() && listaDeBarcosDobles[i] != barcoDelJugador)
		{
			if (barcoDelJugador->getSprite().getGlobalBounds().intersects(listaDeBarcosDobles[i]->getSprite().getGlobalBounds()))
			{
				barcoDelJugador->impactoDeBarco();
				listaDeBarcosDobles[i]->impactoDeBarco();
			}
		}

		if (listaDeBarcosCuatro[i]->getUso() && listaDeBarcosCuatro[i] != barcoDelJugador)
		{
			if (barcoDelJugador->getSprite().getGlobalBounds().intersects(listaDeBarcosCuatro[i]->getSprite().getGlobalBounds()))
			{
				barcoDelJugador->impactoDeBarco();
				listaDeBarcosCuatro[i]->impactoDeBarco();
			}
		}
	}
}

void AdministradorDeBarcos::checkImpactosBala()
{
	for (int i = 0; i < Datos::getCantidadBarcos(); i++)
	{
		for (int c = 0; c < listaDeBarcos[i]->getListaDeBalas().count(); c++)
		{
			colisionBarcoBala((listaDeBarcos[i]->getListaDeBalas())[c]);
		}
		for (int c = 0; c < listaDeBarcosDobles[i]->getListaDeBalas().count(); c++)
		{
			colisionBarcoBala((listaDeBarcosDobles[i]->getListaDeBalas())[c]);
		}
		for (int c = 0; c < listaDeBarcosCuatro[i]->getListaDeBalas().count(); c++)
		{
			colisionBarcoBala((listaDeBarcosCuatro[i]->getListaDeBalas())[c]);
		}

		colisionBarcoMarinero(i, Barco::getMarinero());
	}
}

void AdministradorDeBarcos::colisionBarcoBala(Bala* miBala)
{
	if (miBala->getUso())
	{
		for (int i = 0; i < Datos::getCantidadBarcos(); i++)
		{
			if (listaDeBarcos[i]->getUso() && listaDeBarcos[i] != miBala->getBarcoOrigen())
			{
				if (miBala->getSprite().getGlobalBounds().intersects(listaDeBarcos[i]->getSprite().getGlobalBounds()))
				{
					if ((!(miBala->getComportamiento()->getEsEnemigo()) && !(listaDeBarcos[i]->getEstaPoseido())) ||
						(miBala->getComportamiento()->getEsEnemigo() && listaDeBarcos[i]->getEstaPoseido()))
					{
						listaDeBarcos[i]->impacto();
					}
					miBala->getComportamiento()->activarReciclar();
					return;
				}
			}
			if(listaDeBarcosDobles[i]->getUso() && listaDeBarcosDobles[i] != miBala->getBarcoOrigen())
			{
				if (miBala->getSprite().getGlobalBounds().intersects(listaDeBarcosDobles[i]->getSprite().getGlobalBounds()))
				{
					if ((!(miBala->getComportamiento()->getEsEnemigo()) && !(listaDeBarcosDobles[i]->getEstaPoseido())) ||
						(miBala->getComportamiento()->getEsEnemigo() && listaDeBarcosDobles[i]->getEstaPoseido()))
					{
						listaDeBarcosDobles[i]->impacto();
					}
					miBala->getComportamiento()->activarReciclar();
					return;
				}
			}
			if(listaDeBarcosCuatro[i]->getUso() && listaDeBarcosCuatro[i] != miBala->getBarcoOrigen())
			{
				if (miBala->getSprite().getGlobalBounds().intersects(listaDeBarcosCuatro[i]->getSprite().getGlobalBounds()))
				{
					if ((!(miBala->getComportamiento()->getEsEnemigo()) && !(listaDeBarcosCuatro[i]->getEstaPoseido())) ||
						(miBala->getComportamiento()->getEsEnemigo() && listaDeBarcosCuatro[i]->getEstaPoseido()))
					{
						listaDeBarcosCuatro[i]->impacto();
					}
					miBala->getComportamiento()->activarReciclar();
					return;
				}
			}
		}
	}
}

void AdministradorDeBarcos::colisionBarcoMarinero(int numeroDeBarco, Marinero* miMarinero)
{
	if (miMarinero->getUso())
	{
		if (listaDeBarcos[numeroDeBarco]->getUso() && listaDeBarcos[numeroDeBarco] != miMarinero->getBarcoOrigen())
		{
			if (miMarinero->getSprite().getGlobalBounds().intersects(listaDeBarcos[numeroDeBarco]->getSprite().getGlobalBounds()))
			{
				listaDeBarcos[numeroDeBarco]->abordar();
				barcoDelJugador = listaDeBarcos[numeroDeBarco];
				miMarinero->getBarcoOrigen()->abandonar();
				miMarinero->getComportamiento()->activarReciclar();
				return;
			}
		}

		if (listaDeBarcosDobles[numeroDeBarco]->getUso() && listaDeBarcosDobles[numeroDeBarco] != miMarinero->getBarcoOrigen())
		{
			if (miMarinero->getSprite().getGlobalBounds().intersects(listaDeBarcosDobles[numeroDeBarco]->getSprite().getGlobalBounds()))
			{
				listaDeBarcosDobles[numeroDeBarco]->abordar();
				barcoDelJugador = listaDeBarcosDobles[numeroDeBarco];
				miMarinero->getBarcoOrigen()->abandonar();
				miMarinero->getComportamiento()->activarReciclar();
				return;
			}
		}

		if (listaDeBarcosCuatro[numeroDeBarco]->getUso() && listaDeBarcosCuatro[numeroDeBarco] != miMarinero->getBarcoOrigen())
		{
			if (miMarinero->getSprite().getGlobalBounds().intersects(listaDeBarcosCuatro[numeroDeBarco]->getSprite().getGlobalBounds()))
			{
				listaDeBarcosCuatro[numeroDeBarco]->abordar();
				barcoDelJugador = listaDeBarcosCuatro[numeroDeBarco];
				miMarinero->getBarcoOrigen()->abandonar();
				miMarinero->getComportamiento()->activarReciclar();
				return;
			}
		}
	}
}

void AdministradorDeBarcos::setBarcoInicial()
{
	listaDeBarcos[0]->abordar();
	listaDeBarcos[0]->setPosition(Datos::getPosicionInicialX(), Datos::getAltoPantalla() / 2);
	barcoDelJugador = listaDeBarcos[0];
}

void AdministradorDeBarcos::checkTimers()
{
	for (int i = 0; i < Datos::getCantidadBarcos(); i++)
	{
		listaDeBarcos[i]->checkTimers();
		listaDeBarcosDobles[i]->checkTimers();
		listaDeBarcosCuatro[i]->checkTimers();
	}
}

void AdministradorDeBarcos::resetAdministrador()
{
	for (int i = 0; i < Datos::getCantidadBarcos(); i++)
	{
		listaDeBarcos[i]->resetBarco();
		listaDeBarcos[i]->resetExtra();
		listaDeBarcosDobles[i]->resetBarco();
		listaDeBarcosDobles[i]->resetExtra();
		listaDeBarcosCuatro[i]->resetBarco();
		listaDeBarcosCuatro[i]->resetExtra();
	}

	Barco::getMarinero()->resetBala();

	Datos::timerJuego.restart();

	preparandoW1 = true;
	preparandoW2 = true;
	preparandoW3 = true;
	posicionandoW1 = false;
	posicionandoW2 = false;
	posicionandoW3 = false;
	contador1 = 0;
	contador2 = 0;
	contador3 = 0;
	tiempo1 = sf::seconds(0);
	tiempo2 = sf::seconds(0);
	tiempo3 = sf::seconds(0);

	setBarcoInicial();

	Datos::resetDatos();
}

Barco* AdministradorDeBarcos::getBarcoDelJugador() const
{
	return barcoDelJugador;
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