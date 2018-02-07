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
	int puntos;

public:
	~Jugador();

	static Jugador* crearJugador();

	void empezarJuego();
	void sumarPuntos(int num);
	bool getJugando() const;
	int getPuntos() const;
};

}

#endif