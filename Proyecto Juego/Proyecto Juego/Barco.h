#ifndef BARCO_H
#define BARCO_H

#include "GameObject.h"
#include <SFML\Window.hpp>
#include <SFML\System.hpp>

namespace Octavio
{

class Barco : public GameObject
{
private:
	static sf::Sprite elSprite;

	int disparos;
	int resistencia;
	float velocidad;
	int valorPuntos;
	bool esBarcoDeAtaque;
	bool puedeAtacar;
	bool puedeAbordar;
	bool puedeSerGolpeado;
	sf::Time cdAtaque;
	bool estaPoseido;
	sf::Time cdRecuperacion;
	sf::Time cdAbordaje;
	bool estaEnUso;
	bool estaVivo;
	sf::Time tiempoDeMuerte;

	sf::Clock timerAtaque;
	sf::Clock timerRecuperacion;
	sf::Clock timerAbordaje;
	sf::Clock timerMorir;

public:
	Barco();
	virtual ~Barco();

	int getDisparos() const;
	int getResistencia() const;
	float getVelocidad() const;
	int getValorPuntos() const;
	bool getEsBarcoDeAtaque() const;
	bool getPuedeAtacar() const;
	sf::Time getCDAtaque() const;
	bool getEstaPoseido() const;
	sf::Time getCDRecuperacion() const;
	sf::Time getCDAbordaje() const;
	bool estaEnUso() const;
	bool getEstaVivo() const;
	sf::Time getTiempoDeMuerte() const;
	bool getPuedeAbordar() const;
	bool getPuedeSerGolpeado() const;

	void mover(sf::Keyboard::Key tecla);
	void atacar();
	void impacto();
	void morir();
	void abordar();
	void checkTimers();
};

}

#endif