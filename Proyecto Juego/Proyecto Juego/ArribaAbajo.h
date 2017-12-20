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
		bool avanzando;
		bool arriba;
		bool abajo;

		float recorrido;
		sf::Time ultimoTiempo;
		bool atacar;

		bool reciclar;

		static sf::Time cdAtaque;
				
	public:
		static const float distanciaCorta;

		bool getAtaque() const override;
		void resetAtaque() override;

		bool getReciclar() const override;

		virtual void iniciarComportamiento(GameObject* miGameObject) override;
		ArribaAbajo();

	};

}

#endif