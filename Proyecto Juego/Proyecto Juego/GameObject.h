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

	static void setMaximoZ(int z);

protected:
	IComportamientoDelObjeto* miComportamiento;

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
	void setRotation(float num);

	float getX();
	float getY();

	int getZ() const;

	void setZ(int num);

	void setComportamiento(IComportamientoDelObjeto* comportamiento);
	IComportamientoDelObjeto* getComportamiento() const;
	virtual void activarComportamiento();

	bool getPrimero() const;
	void cambiarPrimero();

	bool getAtaque() const;
	void resetAtaque();

	void setMedio();

	virtual bool getUso() const;
	void restartUso();
};

}

#endif
