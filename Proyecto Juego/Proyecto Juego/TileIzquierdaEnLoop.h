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

};

}

#endif
