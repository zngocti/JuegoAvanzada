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
	void setMedio2();
	void setRotation2(float num);

	virtual void atacar() override;
	virtual void abordar() override;
	virtual void abandonar() override;
	virtual void impacto() override;

	virtual void resetBarco() override;
};

}

#endif