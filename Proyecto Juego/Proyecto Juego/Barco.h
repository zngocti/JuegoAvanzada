#ifndef BARCO_H
#define BARCO_H

#include "GameObject.h"
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include "Bala.h"
#include "Lista.cpp"
#include "Datos.h"

namespace Octavio
{

class Barco : public GameObject
{
private:
	int disparos;
	int resistencia;
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
	float velocidad;

protected:
	Lista<Bala*> listaDeBalas;

public:
	Barco();
	virtual ~Barco();

	int getDisparos() const;
	int getResistencia() const;
	int getValorPuntos() const;
	bool getEsBarcoDeAtaque() const;
	bool getPuedeAtacar() const;
	sf::Time getCDAtaque() const;
	bool getEstaPoseido() const;
	sf::Time getCDRecuperacion() const;
	sf::Time getCDAbordaje() const;
	bool getEstaEnUso() const;
	bool getEstaVivo() const;
	sf::Time getTiempoDeMuerte() const;
	bool getPuedeAbordar() const;
	bool getPuedeSerGolpeado() const;
	float getVelocidad() const;

	void setDisparos(int num);

	void mover(sf::Keyboard::Key tecla);
	virtual void atacar();
	void impacto();
	void morir();
	void abordar();
	void checkTimers();

	Lista<Bala*> getListaDeBalas() const;
};

}

#endif