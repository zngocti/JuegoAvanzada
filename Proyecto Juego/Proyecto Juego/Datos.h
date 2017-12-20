#ifndef DATOS_H
#define DATOS_H

#include <SFML\System.hpp>

namespace Octavio
{

class Datos
{
private:
	Datos();
	static int anchoPantalla;
	static int altoPantalla;
	static int anchoDeTileAgua;
	static int zDelAgua;
	static int tilesExtra;
	static int maxAltoSprite;
	static int maxAnchoSprite;
	
	static float velocidad;
public:
	static int getAnchoPantalla();
	static int getAltoPantalla();
	static int getAnchoDeTitleAgua();
	static int getZDelAgua();
	static int getTilesExtra();
	static int getMaxAltoSprite();
	static int getMaxAnchoSprite();

	static float getVelocidad();

	static sf::Clock timerJuego;
};

}

#endif
