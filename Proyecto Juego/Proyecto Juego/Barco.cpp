#include "Barco.h"

namespace Octavio
{


Bala* Barco::marino = nullptr;

Barco::Barco() : disparos(Datos::getDisparosBarco()), estaPoseido(false), listaDeBalas(Lista<Bala*>(new Bala()))
{
	setPosition(-500, -500);
	for (int i = 0; i < Datos::getBalasPorBarco() - 1; i++)
	{
		listaDeBalas.addBack(new Bala());
		listaDeBalas[i]->setBarcoOrigen(this);
	}
}

Barco::~Barco()
{
	listaDeBalas.removeAll();
}

int Barco::getDisparos() const
{
	return disparos;
}

int Barco::getResistencia() const
{
	return resistencia;
}

int Barco::getValorPuntos() const
{
	return valorPuntos;
}

bool Barco::getEstaPoseido() const
{
	return estaPoseido;
}

sf::Time Barco::getCDRecuperacion() const
{
	return cdRecuperacion;
}

bool Barco::getEstaVivo() const
{
	return estaVivo;
}

sf::Time Barco::getTiempoDeMuerte() const
{
	return tiempoDeMuerte;
}

bool Barco::getPuedeSerGolpeado() const
{
	return puedeSerGolpeado;
}

void Barco::mover(sf::Keyboard::Key tecla)
{
	if (tecla == sf::Keyboard::D && getX() + getSprite().getLocalBounds().width / 2 <= Datos::getAnchoPantalla())
	{
		move(Datos::getVelocidadJugador(), 0.0f);
	}
	else if (tecla == sf::Keyboard::A && getX() - getSprite().getLocalBounds().width / 2 >= 0)
	{
		move(- (Datos::getVelocidadJugador()), 0.0f);
	}
	else if (tecla == sf::Keyboard::S && getY() + getSprite().getLocalBounds().height / 2 <= Datos::getAltoPantalla())
	{
		move(0.0f, Datos::getVelocidadJugador());
	}
	else if (tecla == sf::Keyboard::W && getY() - getSprite().getLocalBounds().height / 2 >= 0)
	{
		move(0.0f, -(Datos::getVelocidadJugador()));
	}
}

void Barco::setDisparos(int num)
{
	disparos = num;
}

void Barco::atacar()
{
	if (getUso() && !estaPoseido)
	{
		for (int i = 0; i < listaDeBalas.count(); i++)
		{
			if (!(listaDeBalas[i]->getUso()))
			{
				resetAtaque();
				listaDeBalas[i]->restartUso();
				listaDeBalas[i]->setPosition(getSprite().getPosition().x - getSprite().getLocalBounds().width / 2, getSprite().getPosition().y);
				listaDeBalas[i]->getComportamiento()->setData(7, true);
				i = listaDeBalas.count();
			}
		}
	}
	else if (getUso() && estaPoseido && disparos > 0)
	{
		for (int i = 0; i < listaDeBalas.count(); i++)
		{
			if (!(listaDeBalas[i]->getUso()))
			{
				resetAtaque();
				listaDeBalas[i]->restartUso();
				listaDeBalas[i]->setPosition(getSprite().getPosition().x + getSprite().getLocalBounds().width / 2, getSprite().getPosition().y);
				listaDeBalas[i]->getComportamiento()->setData(3, false);
				i = listaDeBalas.count();
			}
		}
	}
}

void Barco::impacto()
{
	//efecto impacto y efecto explosion
}

void morir();

void Barco::abordar()
{
	estaPoseido = true;
	setRotation(Datos::getRotacionPoseido());
}

void Barco::dispararMarino()
{
	if (getUso() && estaPoseido && !(marino->getUso()))
	{
		marino->restartUso();
		marino->setPosition(getSprite().getPosition().x + getSprite().getLocalBounds().width / 2, getSprite().getPosition().y);
	}
}

void Barco::checkTimers()
{
	/*
	if (timerAbordaje.getElapsedTime() >= cdAbordaje && !puedeAbordar)
	{
		puedeAbordar = true;
	}
	if (timerAtaque.getElapsedTime() >= cdAtaque && !puedeAtacar)
	{
		puedeAtacar = true;
	}
	if (timerMorir.getElapsedTime() >= tiempoDeMuerte && !estaVivo)
	{
		estaVivo = true;
		getSprite().setPosition(-500, -500);
	}
	if (timerRecuperacion.getElapsedTime() >= cdRecuperacion && !puedeSerGolpeado)
	{
		puedeSerGolpeado = true;
	}
	*/
}

Lista<Bala*> Barco::getListaDeBalas() const
{
	return listaDeBalas;
}

void Barco::activarComportamiento()
{
	if (miComportamiento != nullptr && !estaPoseido)
	{
		miComportamiento->iniciarComportamiento(this);
	}
}

void Barco::crearMarino()
{
	if (marino == nullptr)
	{
		marino = new Bala();
		marino->setMarino();
	}
}

Bala* Barco::getMarino()
{
	return marino;
}

}