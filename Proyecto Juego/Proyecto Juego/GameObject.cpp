#include "GameObject.h"

namespace Octavio
{

GameObject::GameObject() : esDibujable(false), posX(0), posY(0), posZ(0)
{
	
}

GameObject::GameObject(float x, float y, int z) : esDibujable(false), posX(x), posY(y), posZ(z)
{

}

GameObject::GameObject(sf::Sprite unSprite, float x, float y, int z) : miSprite(unSprite), esDibujable(true), posX(x), posY(0), posZ(0)
{

}

GameObject::GameObject(sf::Texture miTextura, float x, float y, int z) : esDibujable(true), posX(x), posY(0), posZ(0)
{
	miSprite.setTexture(miTextura);
}

GameObject::~GameObject()
{

}

int GameObject::getMaximoZ()
{
	//return maximoZ;
	return 0;
}

/*
void GameObject::setMaximoZ(int z)
{
	if (maximoZ < z)
	{
		maximoZ = z;
	}
}*/

sf::Sprite GameObject::getSprite() const
{
	return miSprite;
}

void GameObject::setSprite(sf::Sprite unSprite)
{
	miSprite = unSprite;
}

void GameObject::setSprite(sf::Texture miTextura)
{
	miSprite.setTexture(miTextura);
}

}