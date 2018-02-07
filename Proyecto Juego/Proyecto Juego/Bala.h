#ifndef BALA_H
#define BALA_H

#include "GameObject.h"
#include "Assets.h"
#include "MovimientoBala.h"

namespace Octavio
{

class Barco;

class Bala : public GameObject
{

private:
	bool estaEnUso;
	Barco* miBarcoOrigen;

	static sf::Texture* texturaBala;
	static sf::Texture* texturaMarino;

public:
	Bala();
	virtual ~Bala();

	void setBarcoOrigen(Barco* miBarco);
	Barco* getBarcoOrigen() const;
	void setMarino();

};

}

#endif
