#ifndef BALA_H
#define BALA_H

#include "GameObject.h"

namespace Octavio
{

class Bala : public GameObject
{

private:
	float velocidad;
	bool estaEnUso;

public:
	Bala();
	~Bala();

	float getVelocidad() const;
	bool getEstaEnUso() const;

	void mover(int num);

}

}

#endif
