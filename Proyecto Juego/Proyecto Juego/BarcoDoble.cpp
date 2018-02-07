#include "BarcoDoble.h"

namespace Octavio
{

BarcoDoble::BarcoDoble() : sprite2(new sf::Sprite())
{
	setDisparos(Datos::getDisparosBarcoDoble());
}

BarcoDoble::~BarcoDoble()
{
	delete(sprite2);
}

void BarcoDoble::setSprite2(const sf::Sprite &unSprite)
{
	*sprite2 = unSprite;
}

void BarcoDoble::setSprite2(const sf::Texture &miTextura)
{
	sprite2->setTexture(miTextura);
}

void BarcoDoble::setMedio2()
{
	sprite2->setOrigin(sf::Vector2f(sprite2->getLocalBounds().width, sprite2->getLocalBounds().height) / 2.f);
}

void BarcoDoble::setRotation2(float num)
{
	sprite2->setRotation(num);
}

void BarcoDoble::atacar()
{
	if (getUso() && !estaPoseido)
	{
		for (int i = 0; i < listaDeBalas.count() - 1; i++)
		{
			if (!(listaDeBalas[i]->getUso()) && !(listaDeBalas[i + 1]->getUso()))
			{
				resetAtaque();
				listaDeBalas[i]->restartUso();
				listaDeBalas[i + 1]->restartUso();
				listaDeBalas[i]->setPosition(getSprite().getPosition().x - 20, getSprite().getPosition().y + getSprite().getLocalBounds().height / 2 - 20);
				listaDeBalas[i + 1]->setPosition(getSprite().getPosition().x - 20, getSprite().getPosition().y - getSprite().getLocalBounds().height / 2 + 20);
				listaDeBalas[i]->getComportamiento()->setData(6, true);
				listaDeBalas[i + 1]->getComportamiento()->setData(8, true);
				i = listaDeBalas.count();
			}
		}
	}
}

void BarcoDoble::abordar()
{
	estaPoseido = true;
	setRotation(Datos::getRotacionPoseido());
	setRotation2(Datos::getRotacionPoseido());
}

}