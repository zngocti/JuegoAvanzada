#ifndef ESCENA_H
#define ESCENA_H

#include "Lista.cpp"
#include "GameObject.h"
#include "Boton.h"

namespace Octavio
{

class Escena
{
private:
	Lista<GameObject*> listaDeGameObjects;
	Lista<Boton*> listaDeBotones;

public:
	Escena();
	~Escena();

	Lista<GameObject*> getGameObjects() const;
	Lista<Boton*> getBotones() const;

	void agregarGameObject(GameObject* unGameObject);

	GameObject* crearGameObject();
	GameObject* crearGameObject(float x, float y, int z);
	GameObject* crearGameObject(const sf::Texture &miTextura, float x, float y, int z);
	GameObject* crearGameObject(const sf::Sprite &unSprite, float x, float y, int z);

	Boton* crearBoton(const sf::Texture &miTextura, const sf::Texture &texturaOver, const sf::Texture &texturaApretado, float x, float y, int z);
	Boton* crearBoton(const sf::Sprite &unSprite, const sf::Sprite &spriteOver, const sf::Sprite &spriteApretado, float x, float y, int z);

};

}

#endif
