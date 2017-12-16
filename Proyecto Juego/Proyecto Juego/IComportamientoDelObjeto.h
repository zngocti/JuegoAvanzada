#ifndef ICOMPORTAMIENTODELOBJETO_H
#define ICOMPORTAMIENTODELOBJETO_H

#include "GameObject.h"

namespace Octavio
{

class IComportamientoDelObjeto
{

public:
	virtual ~IComportamientoDelObjeto();
	virtual void iniciarComportamiento(GameObject* miGameObject) = 0;

};

}

#endif
