#ifndef ASSETS_H
#define ASSETS

#include <SFML/Graphics.hpp>
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include <iostream>

namespace Octavio
{

class Assets
{
public:
	static bool menuBackground(sf::Texture &textura);

	static bool cannon(sf::Texture &textura);
	static bool cannonBall(sf::Texture &textura);
	static bool cannonLoose(sf::Texture &textura);
	static bool cannonMobile(sf::Texture &textura);

	static bool crew1(sf::Texture &textura);
	static bool crew2(sf::Texture &textura);
	static bool crew3(sf::Texture &textura);
	static bool crew4(sf::Texture &textura);
	static bool crew5(sf::Texture &textura);
	static bool crew6(sf::Texture &textura);

	static bool boteGrandeNuevo(sf::Texture &textura);
	static bool boteGrandeRoto1(sf::Texture &textura);
	static bool boteGrandeRoto2(sf::Texture &textura);

	static bool boteChicoNuevo(sf::Texture &textura);
	static bool boteChicoRoto1(sf::Texture &textura);
	static bool boteChicoRoto2(sf::Texture &textura);

	static bool explosion1(sf::Texture &textura);
	static bool explosion2(sf::Texture &textura);
	static bool explosion3(sf::Texture &textura);

	static bool fuego1(sf::Texture &textura);
	static bool fuego2(sf::Texture &textura);

	static bool banderaBlanca(sf::Texture &textura);
	static bool banderaNegra(sf::Texture &textura);
	static bool banderaRoja(sf::Texture &textura);
	static bool banderaVerde(sf::Texture &textura);
	static bool banderaAzul(sf::Texture &textura);
	static bool banderaAmarillo(sf::Texture &textura);

	static bool barcoGrandeNuevo(sf::Texture &textura);
	static bool barcoGrandeRoto1(sf::Texture &textura);
	static bool barcoGrandeRoto2(sf::Texture &textura);
	static bool barcoGrandeRoto3(sf::Texture &textura);

	static bool barcoChicoNuevo(sf::Texture &textura);
	static bool barcoChicoRoto1(sf::Texture &textura);
	static bool barcoChicoRoto2(sf::Texture &textura);
	static bool barcoChicoRoto3(sf::Texture &textura);

	static bool nest(sf::Texture &textura);
	static bool mastil(sf::Texture &textura);

	static bool velaGrandeBlancaNueva(sf::Texture &textura);
	static bool velaGrandeBlancaRota1(sf::Texture &textura);
	static bool velaGrandeBlancaRota2(sf::Texture &textura);
	static bool velaGrandeBlancaRota3(sf::Texture &textura);

	static bool velaGrandeNegraNueva(sf::Texture &textura);
	static bool velaGrandeNegraRota1(sf::Texture &textura);
	static bool velaGrandeNegraRota2(sf::Texture &textura);
	static bool velaGrandeNegraRota3(sf::Texture &textura);

	static bool velaGrandeRojaNueva(sf::Texture &textura);
	static bool velaGrandeRojaRota1(sf::Texture &textura);
	static bool velaGrandeRojaRota2(sf::Texture &textura);
	static bool velaGrandeRojaRota3(sf::Texture &textura);

	static bool velaGrandeVerdeNueva(sf::Texture &textura);
	static bool velaGrandeVerdeRota1(sf::Texture &textura);
	static bool velaGrandeVerdeRota2(sf::Texture &textura);
	static bool velaGrandeVerdeRota3(sf::Texture &textura);

	static bool velaGrandeAzulNueva(sf::Texture &textura);
	static bool velaGrandeAzulRota1(sf::Texture &textura);
	static bool velaGrandeAzulRota2(sf::Texture &textura);
	static bool velaGrandeAzulRota3(sf::Texture &textura);

	static bool velaGrandeAmarillaNueva(sf::Texture &textura);
	static bool velaGrandeAmarillaRota1(sf::Texture &textura);
	static bool velaGrandeAmarillaRota2(sf::Texture &textura);
	static bool velaGrandeAmarillaRota3(sf::Texture &textura);

	static bool velaChicaRojaNueva(sf::Texture &textura);
	static bool velaChicaRojaRota1(sf::Texture &textura);
	static bool velaChicaRojaRota2(sf::Texture &textura);

	static bool velaChicaVerdeNueva(sf::Texture &textura);
	static bool velaChicaVerdeRota1(sf::Texture &textura);
	static bool velaChicaVerdeRota2(sf::Texture &textura);

	static bool velaChicaAzulNueva(sf::Texture &textura);
	static bool velaChicaAzulRota1(sf::Texture &textura);
	static bool velaChicaAzulRota2(sf::Texture &textura);

	static bool velaChicaAmarillaNueva(sf::Texture &textura);
	static bool velaChicaAmarillaRota1(sf::Texture &textura);
	static bool velaChicaAmarillaRota2(sf::Texture &textura);

	static bool velaChicaNegra(sf::Texture &textura);

	static bool barcoBlancoNuevo(sf::Texture &textura);
	static bool barcoBlancoRoto1(sf::Texture &textura);
	static bool barcoBlancoRoto2(sf::Texture &textura);
	static bool barcoBlancoRoto3(sf::Texture &textura);

	static bool barcoNegroNuevo(sf::Texture &textura);
	static bool barcoNegroRoto1(sf::Texture &textura);
	static bool barcoNegroRoto2(sf::Texture &textura);
	static bool barcoNegroRoto3(sf::Texture &textura);

	static bool barcoRojoNuevo(sf::Texture &textura);
	static bool barcoRojoRoto1(sf::Texture &textura);
	static bool barcoRojoRoto2(sf::Texture &textura);
	static bool barcoRojoRoto3(sf::Texture &textura);

	static bool barcoVerdeNuevo(sf::Texture &textura);
	static bool barcoVerdeRoto1(sf::Texture &textura);
	static bool barcoVerdeRoto2(sf::Texture &textura);
	static bool barcoVerdeRoto3(sf::Texture &textura);

	static bool barcoAzulNuevo(sf::Texture &textura);
	static bool barcoAzulRoto1(sf::Texture &textura);
	static bool barcoAzulRoto2(sf::Texture &textura);
	static bool barcoAzulRoto3(sf::Texture &textura);

	static bool barcoAmarilloNuevo(sf::Texture &textura);
	static bool barcoAmarilloRoto1(sf::Texture &textura);
	static bool barcoAmarilloRoto2(sf::Texture &textura);
	static bool barcoAmarilloRoto3(sf::Texture &textura);

	static bool madera1(sf::Texture &textura);
	static bool madera2(sf::Texture &textura);
	static bool madera3(sf::Texture &textura);
	static bool madera4(sf::Texture &textura);

private:
	Assets();
	static bool cargarAsset(const char* nombreAsset, sf::Texture &textura);

};

}

#endif
