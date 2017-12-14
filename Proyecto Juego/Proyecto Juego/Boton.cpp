#include "Boton.h"

namespace Octavio
{

Boton::Boton(const sf::Texture &texturaNormal, const sf::Texture &texturaOver, const sf::Texture &texturaApretado, float x, float y, int z)
	: 
	GameObject(texturaNormal, x, y, z),
  	botonNormal(new sf::Sprite(texturaNormal)),
	botonOver(new sf::Sprite (texturaOver)),
	botonApretado (new sf::Sprite (texturaApretado)),
	estaOver(false),
	estaClickeado(false)
{
	setPosBoton(x, y);
}

Boton::Boton(const sf::Sprite &spriteNormal, const sf::Sprite &spriteOver, const sf::Sprite &spriteApretado, float x, float y, int z)
	:
	GameObject(spriteNormal, x, y, z),
	botonNormal(new sf::Sprite(spriteNormal)),
	botonOver(new sf::Sprite(spriteOver)),
	botonApretado(new sf::Sprite(spriteApretado)),
	estaOver(false),
	estaClickeado(false),
	estaActivado(false)
{
	setPosBoton(x, y);
}

Boton::~Boton()
{
	delete(botonNormal);
	delete(botonOver);
	delete(botonApretado);
}

void Boton::iniciaOver()
{
	estaOver = true;
	setSprite(*botonOver);
}

void Boton::finOver()
{
	setSprite(*botonNormal);
	estaOver = false;
}

void Boton::iniciaClick()
{
	estaClickeado = true;
	setSprite(*botonApretado);
}

void Boton::finClick()
{
	setSprite(*botonNormal);
	estaClickeado = false;
}

void Boton::setPosBoton(float x, float y)
{
	setPosition(x, y);
	botonNormal->setPosition(x, y);
	botonOver->setPosition(x, y);
	botonApretado->setPosition(x, y);
}

void Boton::setEscalaBoton(float x, float y)
{
	setEscala(x, y);
	botonNormal->setScale(x, y);
	botonOver->setScale(x, y);
	botonApretado->setScale(x, y);
}

bool Boton::getOver() const
{
	return estaOver;
}

bool Boton::getClickeado() const
{
	return estaClickeado;
}

void Boton::activarBoton()
{
	finClick();
	estaActivado = true;
}

void Boton::apagarBoton()
{
	estaActivado = false;
}

void Boton::setEscenaObjetivo(Escena* const &miEscena)
{
	escenaObjetivo = miEscena;
}

Escena* Boton::getEscenaObjetivo() const
{
	return escenaObjetivo;
}

bool Boton::getEstaActivado() const
{
	return estaActivado;
}

}