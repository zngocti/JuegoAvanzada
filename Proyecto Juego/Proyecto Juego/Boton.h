#ifndef BOTON_H
#define BOTON_H

#include "GameObject.h"

namespace Octavio
{

class Escena;

class Boton : public GameObject
{

private:
	sf::Sprite* botonNormal;
	sf::Sprite* botonOver;
	sf::Sprite* botonApretado;

	bool estaOver;
	bool estaClickeado;
	bool estaActivado;

	Escena* escenaObjetivo;

public:
	Boton(const sf::Texture &miTextura, const sf::Texture &texturaOver, const sf::Texture &texturaApretado, float x, float y, int z);
	Boton(const sf::Sprite &unSprite, const sf::Sprite &spriteOver, const sf::Sprite &spriteApretado, float x, float y, int z);
	~Boton();

	void iniciaOver();
	void finOver();
	void iniciaClick();
	void finClick();

	void setPosBoton(float x, float y);
	void setEscalaBoton(float x, float y);

	bool getOver() const;
	bool getClickeado() const;

	void activarBoton();
	void apagarBoton();

	void setEscenaObjetivo(Escena* const &miEscena);
	Escena* getEscenaObjetivo() const;
	bool getEstaActivado() const;
};

}

#endif
