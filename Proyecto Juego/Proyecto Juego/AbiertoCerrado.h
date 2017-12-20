#ifndef ABIERTOCERRADO_H
#define ABIERTOCERRADO_H

#include "IComportamientoDelObjeto.h"
#include "Datos.h"
#include <SFML\System.hpp>

namespace Octavio
{

	class GameObject;

	class AbiertoCerrado : public IComportamientoDelObjeto
	{
	private:
		bool avanzando;
		bool cerrando1;
		bool cerrando2;

		float recorrido;
		sf::Time ultimoTiempo;
		bool atacar;

		bool reciclar;

		static sf::Time cdAtaque;

	public:
		bool getAtaque() const override;
		void resetAtaque() override;

		bool getReciclar() const override;

		virtual void iniciarComportamiento(GameObject* miGameObject) override;
		AbiertoCerrado();

	};

}

#endif
