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
		static bool primero;

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
		void cambiarPrimero() override;

		bool getReciclar() const override;
		bool getPrimero() const override;

		virtual void iniciarComportamiento(GameObject* miGameObject) override;
		AbiertoCerrado();

		void noReciclar() override;
	};

}

#endif
