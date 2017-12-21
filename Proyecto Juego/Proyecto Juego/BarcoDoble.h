#ifndef BARCODOBLE_H
#define BARCODOBLE_H

#include "Barco.h"

namespace Octavio
{

class BarcoDoble : public Barco
{

private:
	sf::Sprite* sprite2;

public:
	BarcoDoble();
	~BarcoDoble();
	void setSprite2(const sf::Sprite &unSprite);
	void setSprite2(const sf::Texture &miTextura);

};

}

#endif