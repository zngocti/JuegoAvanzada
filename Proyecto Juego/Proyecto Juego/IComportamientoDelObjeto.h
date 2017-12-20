#ifndef ICOMPORTAMIENTODELOBJETO_H
#define ICOMPORTAMIENTODELOBJETO_H

namespace Octavio
{

class GameObject;

class IComportamientoDelObjeto
{

public:
	virtual ~IComportamientoDelObjeto();
	virtual void iniciarComportamiento(GameObject* miGameObject) = 0;

};

}

#endif
