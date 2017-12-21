#include "BarcoCuatro.h"

namespace Octavio
{

BarcoCuatro::BarcoCuatro() : sprite2(new sf::Sprite()), sprite3(new sf::Sprite())
{
	setDisparos(Datos::getDisparosBarcoCuatro());
}

BarcoCuatro::~BarcoCuatro()
{
	delete (sprite2);
	delete (sprite3);
}

void BarcoCuatro::setSprite2(const sf::Sprite &unSprite)
{
	*sprite2 = unSprite;
}

void BarcoCuatro::setSprite2(const sf::Texture &miTextura)
{
	sprite2->setTexture(miTextura);
}

void BarcoCuatro::setSprite3(const sf::Sprite &unSprite)
{
	*sprite3 = unSprite;
}

void BarcoCuatro::setSprite3(const sf::Texture &miTextura)
{
	sprite3->setTexture(miTextura);
}

}