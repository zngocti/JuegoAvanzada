#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "GameObject.h"
#include "Assets.h"
#include "Datos.h"

namespace Octavio
{

class Explosion : public GameObject
{

private:
	static sf::Texture* textura1;
	static sf::Texture* textura2;
	static sf::Texture* textura3;

	static sf::Time tiempoEntreSprites;

	sf::Time tiempoDeExplosion;
	bool estaExplotando;

	int faseExplosion;

public:
	Explosion();
	~Explosion();

	void resetExplosion();
	void iniciarExplosion();
	void activarComportamiento() override;

	bool getUso() const override;

	static sf::Texture* getTextura3();

};

}

#endif
