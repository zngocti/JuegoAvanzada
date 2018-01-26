#ifndef TILEIZQUIERDAENLOOP_H
#define TILEIZQUIERDAENLOOP_H

#include "IComportamientoDelObjeto.h"
#include "Datos.h"

namespace Octavio
{

class GameObject;

class TileIzquierdaEnLoop : public IComportamientoDelObjeto
{
public:
	virtual void iniciarComportamiento(GameObject* miGameObject) override;

	bool getAtaque() const override;
	void resetAtaque() override;
	bool getReciclar() const override;

	void cambiarPrimero() override;
	bool getPrimero() const override;
	void noReciclar() override;
	void setData(int num, bool enemigo) override;
	bool getEsEnemigo() const override;
};

}

#endif
