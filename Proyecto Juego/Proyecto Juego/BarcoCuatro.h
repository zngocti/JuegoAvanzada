#ifndef BARCOCUATRO_H
#define BARCOCUATRO_H

#include "Barco.h"

namespace Octavio
{

class BarcoCuatro : public Barco
{

private:
	sf::Sprite* sprite2;
	sf::Sprite* sprite3;

public:
	BarcoCuatro();
	~BarcoCuatro();

	void setSprite2(const sf::Sprite &unSprite);
	void setSprite2(const sf::Texture &miTextura);
	void setSprite3(const sf::Sprite &unSprite);
	void setSprite3(const sf::Texture &miTextura);
	void setMedio2();
	void setMedio3();
	void setRotation2(float num);
	void setRotation3(float num);
};

}

#endif
