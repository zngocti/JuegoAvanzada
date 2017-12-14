#include "Escena.h"

namespace Octavio
{

Escena::Escena() : listaDeGameObjects(Lista<GameObject*>(nullptr)), listaDeBotones(Lista<Boton*>(nullptr))
{
	listaDeGameObjects.removeFirst();
	listaDeBotones.removeFirst();
}

Escena::~Escena()
{
	for (int i = 0; i < listaDeGameObjects.count(); i++)
	{
		delete (listaDeGameObjects[i]);
	}

	listaDeGameObjects.removeAll();
	listaDeBotones.removeAll();
}

Lista<GameObject*> Escena::getGameObjects() const
{
	return listaDeGameObjects;
}

Lista<Boton*> Escena::getBotones() const
{
	return listaDeBotones;
}

void Escena::agregarGameObject(GameObject* unGameObject)
{
	listaDeGameObjects.addBack(unGameObject);
}

GameObject* Escena::crearGameObject()
{
	GameObject* nuevoGameObject = new GameObject();
	listaDeGameObjects.addBack(nuevoGameObject);

	return nuevoGameObject;
}

GameObject* Escena::crearGameObject(float x, float y, int z)
{
	GameObject* nuevoGameObject = new GameObject(x, y, z);
	listaDeGameObjects.addBack(nuevoGameObject);

	return nuevoGameObject;
}

GameObject* Escena::crearGameObject(const sf::Texture &miTextura, float x, float y, int z)
{
	GameObject* nuevoGameObject = new GameObject(miTextura, x, y, z);
	listaDeGameObjects.addBack(nuevoGameObject);

	return nuevoGameObject;
}

GameObject* Escena::crearGameObject(const sf::Sprite &unSprite, float x, float y, int z)
{
	GameObject* nuevoGameObject = new GameObject(unSprite, x, y, z);
	listaDeGameObjects.addBack(nuevoGameObject);

	return nuevoGameObject;
}

Boton* Escena::crearBoton(const sf::Texture &miTextura, const sf::Texture &texturaOver, const sf::Texture &texturaApretado, float x, float y, int z)
{
	Boton* nuevoBoton = new Boton(miTextura, texturaOver, texturaApretado, x, y, z);
	listaDeGameObjects.addBack(nuevoBoton);
	listaDeBotones.addBack(nuevoBoton);

	return nuevoBoton;
}

Boton* Escena::crearBoton(const sf::Sprite &unSprite, const sf::Sprite &spriteOver, const sf::Sprite &spriteApretado, float x, float y, int z)
{
	Boton* nuevoBoton = new Boton(unSprite, spriteOver, spriteApretado, x, y, z);
	listaDeGameObjects.addBack(nuevoBoton);
	listaDeBotones.addBack(nuevoBoton);

	return nuevoBoton;
}

}