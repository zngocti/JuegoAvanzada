#ifndef BARCO_H
#define BARCO_H

#include "GameObject.h"
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include "Marinero.h"
#include "Lista.cpp"
#include "Datos.h"

namespace Octavio
{

class Barco : public GameObject
{
private:
	static sf::Texture* texturaBala;
	static sf::Texture* texturaMarinero;
	static sf::Time tiempoInmune;

protected:
	sf::Sprite* sprite1;

	int disparos;
	int resistencia;
	int valorPuntos;
	bool puedeSerGolpeado;
	bool estaPoseido;
	sf::Time cdRecuperacion;
	sf::Time tiempoDeMuerte;
	Lista<Bala*> listaDeBalas;

	static Marinero* marinero;

public:
	Barco();
	virtual ~Barco();

	int getDisparos() const;
	int getResistencia() const;
	int getValorPuntos() const;
	bool getEstaPoseido() const;
	sf::Time getCDRecuperacion() const;
	sf::Time getTiempoDeMuerte() const;
	bool getPuedeSerGolpeado() const;

	void setDisparos(int num);
	void setResistencia(int num);

	void mover(sf::Keyboard::Key tecla);
	virtual void atacar();
	virtual void impacto();
	void impactoDeBarco();
	void morir();
	virtual void abordar();
	virtual void abandonar();
	void dispararMarinero();
	void checkTimers();

	void setSprite1(const sf::Sprite &unSprite);
	void setSprite1(const sf::Texture &miTextura);
	void setMedio1();
	void setRotation1(float num);

	virtual void activarComportamiento() override;

	Lista<Bala*> getListaDeBalas() const;

	static Marinero* getMarinero();
};

}

#endif