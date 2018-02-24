#ifndef JUGADOR_H
#define JUGADOR_H

namespace Octavio
{

class Jugador
{
private:
	Jugador();

	static Jugador* elJugador;

	bool jugando;

public:
	~Jugador();

	static Jugador* crearJugador();

	void empezarJuego();
	bool getJugando() const;
	void setJugando(bool estaJugando);
};

}

#endif