#ifndef CENTROVOLVER_H
#define CENTROVOLVER_H

#include "IComportamientoDelObjeto.h"
#include "Datos.h"
#include <SFML\System.hpp>

namespace Octavio
{

class GameObject;

class CentroVolver : public IComportamientoDelObjeto
{
private:
	static bool primero;

	bool avanzando;
	bool entrando;

	float recorrido;
	sf::Time ultimoTiempo;
	bool atacar;

	bool reciclar;

	static sf::Time cdAtaque;

public:
	bool getAtaque() const override;
	void resetAtaque() override;
	void cambiarPrimero() override;

	bool getReciclar() const override;
	bool getPrimero() const override;

	virtual void iniciarComportamiento(GameObject* miGameObject) override;
	CentroVolver();

	void noReciclar() override;
	void activarReciclar() override;
	void setData(int num, bool enemigo) override;
	bool getEsEnemigo() const override;
};

}

#endif
