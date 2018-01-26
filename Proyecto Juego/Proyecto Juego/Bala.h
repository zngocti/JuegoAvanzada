#ifndef BALA_H
#define BALA_H

#include "GameObject.h"
#include "Assets.h"

namespace Octavio
{

class Bala : public GameObject
{

private:
	bool estaEnUso;

	static sf::Texture* texturaBala;

public:
	Bala();
	~Bala();

};

}

#endif
