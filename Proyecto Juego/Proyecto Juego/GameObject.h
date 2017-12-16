#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include "IComportamientoDelObjeto.h"

namespace Octavio
{

class GameObject
{

private:
	static int maximoZ;

	sf::Sprite* miSprite;

	float posX;
	float posY;
	int posZ;

	bool esDibujable;

	IComportamientoDelObjeto* miComportamiento;

	static void setMaximoZ(int z);

public:
	GameObject();
	GameObject(float x, float y, int z);
	GameObject(const sf::Texture &miTextura, float x, float y, int z);
	GameObject(const sf::Sprite &unSprite, float x, float y, int z);
	virtual ~GameObject();

	static int getMaximoZ();

	void setSprite(const sf::Sprite &unSprite);
	void setSprite(const sf::Texture &miTextura);
	sf::Sprite getSprite() const;

	void setEscala(float x, float y);
	void setPosition(float x, float y);
	void move(float x, float y);

	float getX();
	float getY();

	int getZ() const;

	void setComportamiento(IComportamientoDelObjeto* comportamiento);
	void activarComportamiento();

};

}

#endif
