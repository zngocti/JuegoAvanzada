#include "Barco.h"

namespace Octavio
{

Barco::Barco() : GameObject()
{

}

Barco::~Barco()
{

}

int Barco::getDisparos() const
{
	return disparos;
}

int Barco::getResistencia() const
{
	return resistencia;
}

float Barco::getVelocidad() const
{
	return velocidad;
}

int Barco::getValorPuntos() const
{
	return valorPuntos;
}

bool Barco::getEsBarcoDeAtaque() const
{
	return esBarcoDeAtaque;
}

bool Barco::getPuedeAtacar() const
{
	return puedeAtacar;
}

sf::Time Barco::getCDAtaque() const
{
	return cdAtaque;
}

bool Barco::getEstaPoseido() const
{
	return estaPoseido;
}

sf::Time Barco::getCDRecuperacion() const
{
	return cdRecuperacion;
}

sf::Time Barco::getCDAbordaje() const
{
	return cdAbordaje;
}

bool Barco::getEstaEnUso() const
{
	return estaEnUso;
}

bool Barco::getEstaVivo() const
{
	return estaVivo;
}

sf::Time Barco::getTiempoDeMuerte() const
{
	return tiempoDeMuerte;
}

bool Barco::getPuedeAbordar() const
{
	return puedeAbordar;
}

bool Barco::getPuedeSerGolpeado() const
{
	return puedeSerGolpeado;
}

void Barco::mover(sf::Keyboard::Key tecla)
{
	if (tecla == sf::Keyboard::D)
	{
		getSprite().move(velocidad, 0.0f);
	}
	if (tecla == sf::Keyboard::A)
	{
		getSprite().move(-velocidad, 0.0f);
	}
	if (tecla == sf::Keyboard::W)
	{
		getSprite().move(0.0f, velocidad);
	}
	if (tecla == sf::Keyboard::S)
	{
		getSprite().move(0.0f, -velocidad);
	}
}

void Barco::atacar()
{

}

void impacto(); //efecto impacto y efecto explosion
void morir();
void abordar();

void Barco::checkTimers()
{
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
}

}