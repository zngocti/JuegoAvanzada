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

	static Bala* marino;

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
	void dispararMarino();
	void checkTimers();

	virtual void activarComportamiento() override;

	Lista<Bala*> getListaDeBalas() const;

	static void crearMarino();
	static Bala* getMarino();
};

}

#endif