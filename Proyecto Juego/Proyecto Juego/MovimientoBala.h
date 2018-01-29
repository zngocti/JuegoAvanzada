#ifndef MOVIMIENTOBALA_H
#define MOVIMIENTOBALA_H

#include "IComportamientoDelObjeto.h"
#include "Datos.h"
#include <SFML\System.hpp>

namespace Octavio
{

class GameObject;

class MovimientoBala : public IComportamientoDelObjeto
{
private:
	int direccion;
	bool esEnemigo;
	bool reciclar;

public:
	bool getReciclar() const override;

	bool getAtaque() const override;
	void resetAtaque() override;
	void cambiarPrimero() override;
	bool getPrimero() const override;

	virtual void iniciarComportamiento(GameObject* miGameObject) override;
	MovimientoBala();

	void noReciclar() override;
	void activarReciclar() override;
	void setData(int num, bool enemigo) override;
	bool getEsEnemigo() const override;
};

}

#endif