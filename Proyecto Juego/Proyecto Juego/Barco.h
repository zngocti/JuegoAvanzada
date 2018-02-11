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

protected:
	int disparos;
	int resistencia;
	int valorPuntos;
	bool puedeSerGolpeado;
	bool estaPoseido;
	sf::Time cdRecuperacion;
	bool estaVivo;
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
	bool getEstaVivo() const;
	sf::Time getTiempoDeMuerte() const;
	bool getPuedeSerGolpeado() const;

	void setDisparos(int num);

	void mover(sf::Keyboard::Key tecla);
	virtual void atacar();
	void impacto();
	void morir();
	virtual void abordar();
	virtual void abandonar();
	void dispararMarinero();
	void checkTimers();

	virtual void activarComportamiento() override;

	Lista<Bala*> getListaDeBalas() const;

	static Marinero* getMarinero();
};

}

#endif