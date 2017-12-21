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

};

}

#endif
