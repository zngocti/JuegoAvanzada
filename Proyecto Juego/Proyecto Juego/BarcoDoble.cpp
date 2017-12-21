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

}