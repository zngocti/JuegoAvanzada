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
		bool avanzando;
		bool entrando;

		float recorrido;
		sf::Time ultimoTiempo;
		bool atacar;

		bool reciclar;

		static sf::Time cdAtaque;

	public:
		bool getAtaque() const;
		void resetAtaque();

		bool getReciclar() const;

		virtual void iniciarComportamiento(GameObject* miGameObject) override;
		CentroVolver();

	};

}

#endif
