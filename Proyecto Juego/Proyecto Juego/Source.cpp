#include <iostream>
#include "vld.h"
#include <SFML/Graphics.hpp>
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"

void main()
{
	rapidxml::file<> xmlFile("../Assets/ships_sheet.xml");
	rapidxml::xml_document<> doc;
	doc.parse<0>(xmlFile.data());

	/*std::cout << "X: " << doc.first_node()->first_node()->name() << std::endl;
	std::cout << "X: " << doc.first_node()->first_node()->first_attribute()->name() << std::endl;
	std::cout << "X: " << doc.first_node()->first_node()->first_attribute("x")->value() << std::endl;

	std::cout << "X: " << doc.first_node()->first_node()->next_sibling() << std::endl;
	std::cout << "X: " << doc.first_node()->first_node()->next_sibling()->first_attribute()->name() << std::endl;
	std::cout << "X: " << doc.first_node()->first_node()->next_sibling()->first_attribute("x")->value() << std::endl;
	*/
	rapidxml::xml_node<char>* nodoActual = doc.first_node()->first_node();
	bool seguirBuscando = true;
	
	int spriteX = 0;
	int spriteY = 0;
	int spriteH = 0;
	int spriteW = 0;

	do
	{
		if (0 == std::strcmp("ship (6).png", nodoActual->first_attribute("name")->value()))
		{
			std::cout << "x: " << nodoActual->first_attribute("x")->value() << std::endl;
			std::cout << "y: " << nodoActual->first_attribute("y")->value() << std::endl;
			std::cout << "height: " << nodoActual->first_attribute("height")->value() << std::endl;
			std::cout << "width: " << nodoActual->first_attribute("width")->value() << std::endl;

			seguirBuscando = false;

			spriteX = strtol(nodoActual->first_attribute("x")->value(), NULL, 0);
			spriteY = strtol(nodoActual->first_attribute("y")->value(), NULL, 0);
			spriteH = strtol(nodoActual->first_attribute("height")->value(), NULL, 0);
			spriteW = strtol(nodoActual->first_attribute("width")->value(), NULL, 0);

			std::cout << "X: " << spriteX << std::endl;
			std::cout << "Y: " << spriteY << std::endl;
			std::cout << "H: " << spriteH << std::endl;
			std::cout << "W: " << spriteW << std::endl;

		}
		else if (nodoActual == doc.first_node()->last_node())
		{
			seguirBuscando = false;

			std::cout << "No se encontro" << std::endl;
		}
		else
		{
			nodoActual = nodoActual->next_sibling();
		}

	} while (seguirBuscando);



	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::Texture texture;

	// cargo un rectangulo de 50x108 que inicia en el (0, 0) del archivo
	if (!texture.loadFromFile("../Assets/ships_sheet.png", sf::IntRect(spriteX, spriteY, spriteW, spriteH)))
	{
		std::cout << "No cargo la imagen" << std::endl;
	}
	else
	{
		sf::Sprite sprite;
		sprite.setTexture(texture);

		sprite.setPosition(500, 300);
		sprite.setRotation(270);
		sprite.setScale(1, 1);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			window.clear();
			window.draw(sprite);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				sprite.move(0.1, 0.f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				sprite.move(-0.1, 0.f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				sprite.move(0.f, -0.1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				sprite.move(0.f, 0.1);
			}

			window.display();
		}
	}
}