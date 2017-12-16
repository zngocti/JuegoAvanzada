#ifndef TILEIZQUIERDAENLOOP_H
#define TILEIZQUIERDAENLOOP_H

#include "IComportamientoDelObjeto.h"
#include "GameObject.h"
#include "Datos.h"

namespace Octavio
{
	
class TileIzquierdaEnLoop : public IComportamientoDelObjeto
{
public:

	// Heredado vía IComportamientoDelObjeto
	virtual void iniciarComportamiento(GameObject* miGameObject) override;
	// void iniciarComportamiento(GameObject* miGameObject);
};

}

#endif
