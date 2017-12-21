#include "GameObject.h"

namespace Octavio
{

int GameObject::maximoZ = 0;

GameObject::GameObject() : miSprite(new sf::Sprite()), esDibujable(false), posX(0), posY(0), posZ(0)
{
	setMaximoZ(posZ);
}

GameObject::GameObject(float x, float y, int z) : esDibujable(false), posX(x), posY(y), posZ(z)
{
	setPosition(x, y);
	setMaximoZ(posZ);
}

GameObject::GameObject(const sf::Sprite &unSprite, float x, float y, int z) : miSprite(new sf::Sprite(unSprite)), esDibujable(true), posX(x), posY(y), posZ(z)
{
	setPosition(x, y);
	setMaximoZ(posZ);
}

GameObject::GameObject(const sf::Texture &miTextura, float x, float y, int z) : miSprite(new sf::Sprite(miTextura)), esDibujable(true), posX(x), posY(y), posZ(z)
{
	setPosition(x, y);
	setMaximoZ(posZ);
}

GameObject::~GameObject()
{
	delete(miSprite);
	delete(miComportamiento);
}

int GameObject::getMaximoZ()
{
	return maximoZ;
}


void GameObject::setMaximoZ(int z)
{
	if (maximoZ < z)
	{
		maximoZ = z;
	}
}

sf::Sprite GameObject::getSprite() const
{
	return *miSprite;
}

void GameObject::setSprite(const sf::Sprite &unSprite)
{
	*miSprite = unSprite;
}

void GameObject::setSprite(const sf::Texture &miTextura)
{
	miSprite->setTexture(miTextura);
}

void GameObject::move(float x, float y)
{
	miSprite->move(x, y);
}

int GameObject::getZ() const
{
	return posZ;
}

void GameObject::setEscala(float x, float y)
{
	miSprite->setScale(x, y);
}

void GameObject::setPosition(float x, float y)
{
	miSprite->setPosition(x, y);
}

float GameObject::getX()
{
	return miSprite->getPosition().x;
}

float GameObject::getY()
{
	return miSprite->getPosition().y;
}

void GameObject::setComportamiento(IComportamientoDelObjeto* comportamiento)
{
	if (miComportamiento != nullptr)
	{
		delete(miComportamiento);
	}

	miComportamiento = comportamiento;
}

void GameObject::activarComportamiento()
{
	if (miComportamiento != nullptr)
	{
		miComportamiento->iniciarComportamiento(this);
	}
}

void GameObject::setZ(int num)
{
	posZ = num;
}

bool GameObject::getPrimero() const
{
	return miComportamiento->getPrimero();
}

void GameObject::cambiarPrimero()
{
	miComportamiento->cambiarPrimero();
}

bool GameObject::getAtaque() const
{
	return miComportamiento->getAtaque();
}

void GameObject::resetAtaque()
{
	miComportamiento->resetAtaque();
}

}