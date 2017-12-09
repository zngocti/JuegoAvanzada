#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

namespace Octavio
{

class GameObject
{

private:
	//static int maximoZ;

	sf::Sprite miSprite;

	float posX;
	float posY;
	int posZ;

	bool esDibujable;

	//static void setMaximoZ(int z);

public:
	GameObject();
	GameObject(float x, float y, int z);
	GameObject(sf::Texture miTextura, float x, float y, int z);
	GameObject(sf::Sprite unSprite, float x, float y, int z);
	~GameObject();

	static int getMaximoZ();

	void setSprite(sf::Sprite unSprite);
	void setSprite(sf::Texture miTextura);
	sf::Sprite getSprite() const;


};

}

#endif
