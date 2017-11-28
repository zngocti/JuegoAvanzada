#include <iostream>
#include "vld.h"
#include <SFML/Graphics.hpp>

void main()
{
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
		sprite.setRotation(90);
		sprite.setScale(3, 3);

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
			window.display();
		}
	}
}