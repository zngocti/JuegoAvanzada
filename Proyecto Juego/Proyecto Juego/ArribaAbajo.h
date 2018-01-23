#ifndef ARRIBAABAJO_H
#define ARRIBAABAJO_H

#include "IComportamientoDelObjeto.h"
#include "Datos.h"
#include <SFML\System.hpp>

namespace Octavio
{

	class GameObject;

	class ArribaAbajo : public IComportamientoDelObjeto
	{
	private:
		static bool primero;

		bool avanzando;
		bool arriba;
		bool abajo;
		bool primerMovimiento;

		float recorrido;
		sf::Time ultimoTiempo;
		bool atacar;

		bool reciclar;

		static sf::Time cdAtaque;
				
	public:
		static const float distanciaCorta;

		bool getAtaque() const override;
		void resetAtaque() override;
		void cambiarPrimero() override;

		bool getReciclar() const override;
		bool getPrimero() const override;

		virtual void iniciarComportamiento(GameObject* miGameObject) override;
		ArribaAbajo();

		void noReciclar() override;

	};

}

#endif