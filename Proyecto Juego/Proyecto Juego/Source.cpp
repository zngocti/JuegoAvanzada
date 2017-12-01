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

	std::cout << "Nombre: " << doc.first_node()->name() << std::endl;
	std::cout << "Valor: " << doc.first_node()->value() << std::endl;
	std::cout << "Primer Atributo Nombre: " << doc.first_node()->first_attribute()->name() << std::endl;
	std::cout << "Primer Atributo Valor: " << doc.first_node()->first_attribute()->value() << std::endl;
	std::cout << "Primer Atributo: " << doc.first_node()->first_attribute("imagePath") << std::endl;






	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::Texture texture;

	// cargo un rectangulo de 50x108 que inicia en el (0, 0) del archivo
	if (!texture.loadFromFile("../Assets/hullLarge (1).png", sf::IntRect(0, 0, 50, 108)))
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