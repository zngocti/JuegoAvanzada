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
	virtual bool getPrimero() const = 0;
	virtual void cambiarPrimero() = 0;
	virtual void noReciclar() = 0;
	virtual void activarReciclar() = 0;
	virtual void setData(int num, bool enemigo) = 0;
	virtual bool getEsEnemigo() const = 0;

};

}

#endif
