#include <iostream>
#include "vld.h"
#include <SFML/Graphics.hpp>

void main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::Texture texture;

	// cargo un rectangulo de 64x64 que inicia en el (0, 0) del archivo
	if (!texture.loadFromFile("../Assets/tile_01.png", sf::IntRect(0, 0, 64, 64)))
	{
		std::cout << "No cargo la imagen" << std::endl;
	}
	else
	{
		sf::Sprite sprite;
		sprite.setTexture(texture);

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