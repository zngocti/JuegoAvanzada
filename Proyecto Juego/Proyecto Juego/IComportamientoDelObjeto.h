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
	virtual bool getAtaque() const = 0;
	virtual void resetAtaque() = 0;
	virtual bool getReciclar() const = 0;

};

}

#endif
