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
	static bool Assets::menuBackground(sf::Texture &textura);

	static bool Assets::cannon(sf::Texture &textura);
	static bool Assets::cannonBall(sf::Texture &textura);
	static bool Assets::cannonLoose(sf::Texture &textura);
	static bool Assets::cannonMobile(sf::Texture &textura);

	static bool Assets::crew1(sf::Texture &textura);
	static bool Assets::crew2(sf::Texture &textura);
	static bool Assets::crew3(sf::Texture &textura);
	static bool Assets::crew4(sf::Texture &textura);
	static bool Assets::crew5(sf::Texture &textura);
	static bool Assets::crew6(sf::Texture &textura);

	static bool Assets::boteGrandeNuevo(sf::Texture &textura);
	static bool Assets::boteGrandeRoto1(sf::Texture &textura);
	static bool Assets::boteGrandeRoto2(sf::Texture &textura);

	static bool Assets::boteChicoNuevo(sf::Texture &textura);
	static bool Assets::boteChicoRoto1(sf::Texture &textura);
	static bool Assets::boteChicoRoto2(sf::Texture &textura);

	static bool Assets::explosion1(sf::Texture &textura);
	static bool Assets::explosion2(sf::Texture &textura);
	static bool Assets::explosion3(sf::Texture &textura);

	static bool Assets::fuego1(sf::Texture &textura);
	static bool Assets::fuego2(sf::Texture &textura);

	static bool Assets::banderaBlanca(sf::Texture &textura);
	static bool Assets::banderaNegra(sf::Texture &textura);
	static bool Assets::banderaRoja(sf::Texture &textura);
	static bool Assets::banderaVerde(sf::Texture &textura);
	static bool Assets::banderaAzul(sf::Texture &textura);
	static bool Assets::banderaAmarillo(sf::Texture &textura);

	static bool Assets::barcoGrandeNuevo(sf::Texture &textura);
	static bool Assets::barcoGrandeRoto1(sf::Texture &textura);
	static bool Assets::barcoGrandeRoto2(sf::Texture &textura);
	static bool Assets::barcoGrandeRoto3(sf::Texture &textura);

	static bool Assets::barcoChicoNuevo(sf::Texture &textura);
	static bool Assets::barcoChicoRoto1(sf::Texture &textura);
	static bool Assets::barcoChicoRoto2(sf::Texture &textura);
	static bool Assets::barcoChicoRoto3(sf::Texture &textura);

	static bool Assets::nest(sf::Texture &textura);
	static bool Assets::mastil(sf::Texture &textura);

	static bool Assets::velaGrandeBlancaNueva(sf::Texture &textura);
	static bool Assets::velaGrandeBlancaRota1(sf::Texture &textura);
	static bool Assets::velaGrandeBlancaRota2(sf::Texture &textura);
	static bool Assets::velaGrandeBlancaRota3(sf::Texture &textura);

	static bool Assets::velaGrandeNegraNueva(sf::Texture &textura);
	static bool Assets::velaGrandeNegraRota1(sf::Texture &textura);
	static bool Assets::velaGrandeNegraRota2(sf::Texture &textura);
	static bool Assets::velaGrandeNegraRota3(sf::Texture &textura);

	static bool Assets::velaGrandeRojaNueva(sf::Texture &textura);
	static bool Assets::velaGrandeRojaRota1(sf::Texture &textura);
	static bool Assets::velaGrandeRojaRota2(sf::Texture &textura);
	static bool Assets::velaGrandeRojaRota3(sf::Texture &textura);

	static bool Assets::velaGrandeVerdeNueva(sf::Texture &textura);
	static bool Assets::velaGrandeVerdeRota1(sf::Texture &textura);
	static bool Assets::velaGrandeVerdeRota2(sf::Texture &textura);
	static bool Assets::velaGrandeVerdeRota3(sf::Texture &textura);

	static bool Assets::velaGrandeAzulNueva(sf::Texture &textura);
	static bool Assets::velaGrandeAzulRota1(sf::Texture &textura);
	static bool Assets::velaGrandeAzulRota2(sf::Texture &textura);
	static bool Assets::velaGrandeAzulRota3(sf::Texture &textura);

	static bool Assets::velaGrandeAmarillaNueva(sf::Texture &textura);
	static bool Assets::velaGrandeAmarillaRota1(sf::Texture &textura);
	static bool Assets::velaGrandeAmarillaRota2(sf::Texture &textura);
	static bool Assets::velaGrandeAmarillaRota3(sf::Texture &textura);

private:
	Assets();
	static bool cargarAsset(const char* nombreAsset, sf::Texture &textura);

};

}

#endif
