#include "Assets.h"

namespace Octavio
{

bool Assets::menuBackground(sf::Texture &textura)
{
	sf::Texture miTextura;

	if (!miTextura.loadFromFile("../Assets/background.jpg", sf::IntRect()))
	{
		std::cout << "No cargo el fondo del menu." << std::endl;
		return false;
	}
	else
	{
		textura = miTextura;
		return true;
	}
}

bool Assets::fondoInstrucciones(sf::Texture &textura)
{
	sf::Texture miTextura;

	if (!miTextura.loadFromFile("../Assets/instrucciones.png", sf::IntRect()))
	{
		std::cout << "No cargaron las instrucciones." << std::endl;
		return false;
	}
	else
	{
		textura = miTextura;
		return true;
	}
}

bool Assets::fondoCreditos(sf::Texture &textura)
{
	sf::Texture miTextura;

	if (!miTextura.loadFromFile("../Assets/creditos.png", sf::IntRect()))
	{
		std::cout << "No cargaron los creditos." << std::endl;
		return false;
	}
	else
	{
		textura = miTextura;
		return true;
	}
}

bool Assets::cargarAsset(const char* nombreAsset, sf::Texture &textura)
{
	rapidxml::file<> miXML("../Assets/ships_sheet.xml");
	rapidxml::xml_document<> doc;

	doc.parse<0>(miXML.data());

	rapidxml::xml_node<char>* nodoActual = doc.first_node()->first_node();
	
	bool seguirBuscando = true;

	int texturaX = 0;
	int texturaY = 0;
	int texturaH = 0;
	int texturaW = 0;

	do
	{
		if (0 == std::strcmp(nombreAsset, nodoActual->first_attribute("name")->value()))
		{
			seguirBuscando = false;

			texturaX = strtol(nodoActual->first_attribute("x")->value(), NULL, 0);
			texturaY = strtol(nodoActual->first_attribute("y")->value(), NULL, 0);
			texturaH = strtol(nodoActual->first_attribute("height")->value(), NULL, 0);
			texturaW = strtol(nodoActual->first_attribute("width")->value(), NULL, 0);

			sf::Texture miTextura;

			// Cargo un rectangulo de texturaW x texturaH que inicia en el (texturaX, texturaY) del archivo
			if (!miTextura.loadFromFile("../Assets/ships_sheet.png", sf::IntRect(texturaX, texturaY, texturaW, texturaH)))
			{
				std::cout << "No cargo la imagen " << nombreAsset << "." << std::endl;
				return false;
			}
			else
			{
				textura = miTextura;
				return true;
			}
		}
		else if (nodoActual == doc.first_node()->last_node())
		{
			seguirBuscando = false;

			std::cout << "No se encontro la textura " << nombreAsset << " en el XML." << std::endl;

			return false;
		}
		else
		{
			nodoActual = nodoActual->next_sibling();
		}

	} while (seguirBuscando);
}

bool Assets::cargarBoton(int num, sf::Texture &textura)
{
	sf::Texture miTextura;

	int texturaX = 0;
	int texturaY = 0;
	int texturaW = 400;
	int texturaH = 174;

	if (num == 2 || num == 5 || num == 8 || num == 11 || num == 14 || num == 17)
	{
		texturaX = texturaW;
	}

	else if (num == 3 || num == 6 || num == 9 || num == 12 || num == 15 || num == 18)
	{
		texturaX = texturaW*2;
	}

	if (num == 4 || num == 5 || num == 6)
	{
		texturaY = texturaH;
	}

	else if (num == 7 || num == 8 || num == 9)
	{
		texturaY = texturaH * 2;
	}

	else if (num == 10 || num == 11 || num == 12)
	{
		texturaY = texturaH * 3;
	}

	else if (num == 13 || num == 14 || num == 15)
	{
		texturaY = texturaH * 4;
	}

	else if (num == 16 || num == 17 || num == 18)
	{
		texturaY = texturaH * 5;
	}

	if (!miTextura.loadFromFile("../Assets/botones.png", sf::IntRect(texturaX, texturaY, texturaW, texturaH)))
	{
		std::cout << "No cargo la imagen del boton." << std::endl;
		return false;
	}
	else
	{
		textura = miTextura;
		return true;
	}
}

bool Assets::cargarIsla(sf::Texture &textura)
{
	sf::Texture miTextura;

	if (!miTextura.loadFromFile("../Assets/tiles_sheet.png", sf::IntRect(0, 0, 64*3, 64*3)))
	{
		std::cout << "No cargo la imagen de la isla." << std::endl;
		return false;
	}
	else
	{
		textura = miTextura;
		return true;
	}
}

bool Assets::cargarTile(int num, sf::Texture &textura)
{
	sf::Texture miTextura;

	int x = 0;
	int y = 0;

	if (num < 17)
	{
		x = 64*(num - 1);
		y = 0;
	}
	else if (num < 33)
	{
		x = 64 * (num - 17);
		y = 64;
	}
	else if (num < 49)
	{
		x = 64 * (num - 33);
		y = 128;
	}
	else if (num < 65)
	{
		x = 64 * (num - 49);
		y = 192;
	}
	else if (num < 81)
	{
		x = 64 * (num - 65);
		y = 256;
	}
	else if (num < 97)
	{
		x = 64 * (num - 81);
		y = 320;
	}

	if (!miTextura.loadFromFile("../Assets/tiles_sheet.png", sf::IntRect(x, y, 64, 64)))
	{
		std::cout << "No cargo la imagen de la isla." << std::endl;
		return false;
	}
	else
	{
		textura = miTextura;
		return true;
	}
}

bool Assets::cannon(sf::Texture &textura)
{
	return Assets::cargarAsset("cannon.png", textura);
}

bool Assets::cannonBall(sf::Texture &textura)
{
	return Assets::cargarAsset("cannonBall.png", textura);
}

bool Assets::cannonLoose(sf::Texture &textura)
{
	return Assets::cargarAsset("cannonLoose.png", textura);
}

bool Assets::cannonMobile(sf::Texture &textura)
{
	return Assets::cargarAsset("cannonMobile.png", textura);
}

bool Assets::crew1(sf::Texture &textura)
{
	return Assets::cargarAsset("crew (1).png", textura);
}

bool Assets::crew2(sf::Texture &textura)
{
	return Assets::cargarAsset("crew (2).png", textura);
}

bool Assets::crew3(sf::Texture &textura)
{
	return Assets::cargarAsset("crew (3).png", textura);
}

bool Assets::crew4(sf::Texture &textura)
{
	return Assets::cargarAsset("crew (4).png", textura);
}

bool Assets::crew5(sf::Texture &textura)
{
	return Assets::cargarAsset("crew (5).png", textura);
}

bool Assets::crew6(sf::Texture &textura)
{
	return Assets::cargarAsset("crew (6).png", textura);
}

bool Assets::boteGrandeNuevo(sf::Texture &textura)
{
	return Assets::cargarAsset("dinghyLarge1.png", textura);
}

bool Assets::boteGrandeRoto1(sf::Texture &textura)
{
	return Assets::cargarAsset("dinghyLarge2.png", textura);
}

bool Assets::boteGrandeRoto2(sf::Texture &textura)
{
	return Assets::cargarAsset("dinghyLarge3.png", textura);
}

bool Assets::boteChicoNuevo(sf::Texture &textura)
{
	return Assets::cargarAsset("dinghySmall1.png", textura);
}

bool Assets::boteChicoRoto1(sf::Texture &textura)
{
	return Assets::cargarAsset("dinghySmall2.png", textura);
}

bool Assets::boteChicoRoto2(sf::Texture &textura)
{
	return Assets::cargarAsset("dinghySmall3.png", textura);
}

bool Assets::explosion1(sf::Texture &textura)
{
	return Assets::cargarAsset("explosion3.png", textura);
}

bool Assets::explosion2(sf::Texture &textura)
{
	return Assets::cargarAsset("explosion2.png", textura);
}

bool Assets::explosion3(sf::Texture &textura)
{
	return Assets::cargarAsset("explosion1.png", textura);
}

bool Assets::fuego1(sf::Texture &textura)
{
	return Assets::cargarAsset("fire1.png", textura);
}

bool Assets::fuego2(sf::Texture &textura)
{
	return Assets::cargarAsset("fire2.png", textura);
}

bool Assets::banderaBlanca(sf::Texture &textura)
{
	return Assets::cargarAsset("flag (1).png", textura);
}

bool Assets::banderaNegra(sf::Texture &textura)
{
	return Assets::cargarAsset("flag (2).png", textura);
}

bool Assets::banderaRoja(sf::Texture &textura)
{
	return Assets::cargarAsset("flag (3).png", textura);
}

bool Assets::banderaVerde(sf::Texture &textura)
{
	return Assets::cargarAsset("flag (4).png", textura);
}

bool Assets::banderaAzul(sf::Texture &textura)
{
	return Assets::cargarAsset("flag (5).png", textura);
}

bool Assets::banderaAmarillo(sf::Texture &textura)
{
	return Assets::cargarAsset("flag (6).png", textura);
}

bool Assets::barcoGrandeNuevo(sf::Texture &textura)
{
	return Assets::cargarAsset("hullLarge (1).png", textura);
}

bool Assets::barcoGrandeRoto1(sf::Texture &textura)
{
	return Assets::cargarAsset("hullLarge (2).png", textura);
}

bool Assets::barcoGrandeRoto2(sf::Texture &textura)
{
	return Assets::cargarAsset("hullLarge (3).png", textura);
}

bool Assets::barcoGrandeRoto3(sf::Texture &textura)
{
	return Assets::cargarAsset("hullLarge (4).png", textura);
}

bool Assets::barcoChicoNuevo(sf::Texture &textura)
{
	return Assets::cargarAsset("hullSmall (1).png", textura);
}

bool Assets::barcoChicoRoto1(sf::Texture &textura)
{
	return Assets::cargarAsset("hullSmall (2).png", textura);
}

bool Assets::barcoChicoRoto2(sf::Texture &textura)
{
	return Assets::cargarAsset("hullSmall (3).png", textura);
}

bool Assets::barcoChicoRoto3(sf::Texture &textura)
{
	return Assets::cargarAsset("hullSmall (4).png", textura);
}

bool Assets::nest(sf::Texture &textura)
{
	return Assets::cargarAsset("nest.png", textura);
}

bool Assets::mastil(sf::Texture &textura)
{
	return Assets::cargarAsset("pole.png", textura);
}

bool Assets::velaGrandeBlancaNueva(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (7).png", textura);
}

bool Assets::velaGrandeBlancaRota1(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (1).png", textura);
}

bool Assets::velaGrandeBlancaRota2(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (19).png", textura);
}

bool Assets::velaGrandeBlancaRota3(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (13).png", textura);
}

bool Assets::velaGrandeNegraNueva(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (8).png", textura);
}

bool Assets::velaGrandeNegraRota1(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (2).png", textura);
}

bool Assets::velaGrandeNegraRota2(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (20).png", textura);
}

bool Assets::velaGrandeNegraRota3(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (14).png", textura);
}

bool Assets::velaGrandeRojaNueva(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (9).png", textura);
}

bool Assets::velaGrandeRojaRota1(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (3).png", textura);
}

bool Assets::velaGrandeRojaRota2(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (21).png", textura);
}

bool Assets::velaGrandeRojaRota3(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (15).png", textura);
}

bool Assets::velaGrandeVerdeNueva(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (10).png", textura);
}

bool Assets::velaGrandeVerdeRota1(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (4).png", textura);
}

bool Assets::velaGrandeVerdeRota2(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (22).png", textura);
}

bool Assets::velaGrandeVerdeRota3(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (16).png", textura);
}

bool Assets::velaGrandeAzulNueva(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (11).png", textura);
}

bool Assets::velaGrandeAzulRota1(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (5).png", textura);
}

bool Assets::velaGrandeAzulRota2(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (23).png", textura);
}

bool Assets::velaGrandeAzulRota3(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (17).png", textura);
}

bool Assets::velaGrandeAmarillaNueva(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (12).png", textura);
}

bool Assets::velaGrandeAmarillaRota1(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (6).png", textura);
}

bool Assets::velaGrandeAmarillaRota2(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (24).png", textura);
}

bool Assets::velaGrandeAmarillaRota3(sf::Texture &textura)
{
	return Assets::cargarAsset("sailLarge (18).png", textura);
}

bool Assets::velaChicaRojaNueva(sf::Texture &textura)
{
	return Assets::cargarAsset("sailSmall (3).png", textura);
}

bool Assets::velaChicaRojaRota1(sf::Texture &textura)
{
	return Assets::cargarAsset("sailSmall (7).png", textura);
}

bool Assets::velaChicaRojaRota2(sf::Texture &textura)
{
	return Assets::cargarAsset("sailSmall (11).png", textura);
}

bool Assets::velaChicaVerdeNueva(sf::Texture &textura)
{
	return Assets::cargarAsset("sailSmall (4).png", textura);
}

bool Assets::velaChicaVerdeRota1(sf::Texture &textura)
{
	return Assets::cargarAsset("sailSmall (8).png", textura);
}

bool Assets::velaChicaVerdeRota2(sf::Texture &textura)
{
	return Assets::cargarAsset("sailSmall (12).png", textura);
}

bool Assets::velaChicaAzulNueva(sf::Texture &textura)
{
	return Assets::cargarAsset("sailSmall (5).png", textura);
}

bool Assets::velaChicaAzulRota1(sf::Texture &textura)
{
	return Assets::cargarAsset("sailSmall (9).png", textura);
}

bool Assets::velaChicaAzulRota2(sf::Texture &textura)
{
	return Assets::cargarAsset("sailSmall (13).png", textura);
}

bool Assets::velaChicaAmarillaNueva(sf::Texture &textura)
{
	return Assets::cargarAsset("sailSmall (6).png", textura);
}

bool Assets::velaChicaAmarillaRota1(sf::Texture &textura)
{
	return Assets::cargarAsset("sailSmall (10).png", textura);
}

bool Assets::velaChicaAmarillaRota2(sf::Texture &textura)
{
	return Assets::cargarAsset("sailSmall (1).png", textura);
}

bool Assets::velaChicaNegra(sf::Texture &textura)
{
	return Assets::cargarAsset("sailSmall (2).png", textura);
}

bool Assets::barcoBlancoNuevo(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (1).png", textura);
}

bool Assets::barcoBlancoRoto1(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (7).png", textura);
}

bool Assets::barcoBlancoRoto2(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (13).png", textura);
}

bool Assets::barcoBlancoRoto3(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (19).png", textura);
}

bool Assets::barcoNegroNuevo(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (2).png", textura);
}

bool Assets::barcoNegroRoto1(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (8).png", textura);
}

bool Assets::barcoNegroRoto2(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (14).png", textura);
}

bool Assets::barcoNegroRoto3(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (20).png", textura);
}

bool Assets::barcoRojoNuevo(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (3).png", textura);
}

bool Assets::barcoRojoRoto1(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (9).png", textura);
}

bool Assets::barcoRojoRoto2(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (15).png", textura);
}

bool Assets::barcoRojoRoto3(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (21).png", textura);
}

bool Assets::barcoVerdeNuevo(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (4).png", textura);
}

bool Assets::barcoVerdeRoto1(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (10).png", textura);
}

bool Assets::barcoVerdeRoto2(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (16).png", textura);
}

bool Assets::barcoVerdeRoto3(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (22).png", textura);
}

bool Assets::barcoAzulNuevo(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (5).png", textura);
}

bool Assets::barcoAzulRoto1(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (11).png", textura);
}

bool Assets::barcoAzulRoto2(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (17).png", textura);
}

bool Assets::barcoAzulRoto3(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (23).png", textura);
}

bool Assets::barcoAmarilloNuevo(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (6).png", textura);
}

bool Assets::barcoAmarilloRoto1(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (12).png", textura);
}

bool Assets::barcoAmarilloRoto2(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (18).png", textura);
}

bool Assets::barcoAmarilloRoto3(sf::Texture &textura)
{
	return Assets::cargarAsset("ship (24).png", textura);
}

bool Assets::madera1(sf::Texture &textura)
{
	return Assets::cargarAsset("wood (1).png", textura);
}

bool Assets::madera2(sf::Texture &textura)
{
	return Assets::cargarAsset("wood (2).png", textura);
}

bool Assets::madera3(sf::Texture &textura)
{
	return Assets::cargarAsset("wood (3).png", textura);
}

bool Assets::madera4(sf::Texture &textura)
{
	return Assets::cargarAsset("wood (4	).png", textura);
}

bool Assets::botonJugarNormal(sf::Texture &textura)
{
	return Assets::cargarBoton(1, textura);
}

bool Assets::botonJugarOver(sf::Texture &textura)
{
	return Assets::cargarBoton(2, textura);
}

bool Assets::botonJugarApretado(sf::Texture &textura)
{
	return Assets::cargarBoton(3, textura);
}

bool Assets::botonControlesNormal(sf::Texture &textura)
{
	return Assets::cargarBoton(4, textura);
}

bool Assets::botonControlesOver(sf::Texture &textura)
{
	return Assets::cargarBoton(5, textura);
}

bool Assets::botonControlesApretado(sf::Texture &textura)
{
	return Assets::cargarBoton(6, textura);
}

bool Assets::botonPuntajesNormal(sf::Texture &textura)
{
	return Assets::cargarBoton(7, textura);
}

bool Assets::botonPuntajesOver(sf::Texture &textura)
{
	return Assets::cargarBoton(8, textura);
}

bool Assets::botonPuntajesApretado(sf::Texture &textura)
{
	return Assets::cargarBoton(9, textura);
}

bool Assets::botonCreditosNormal(sf::Texture &textura)
{
	return Assets::cargarBoton(10, textura);
}

bool Assets::botonCreditosOver(sf::Texture &textura)
{
	return Assets::cargarBoton(11, textura);
}

bool Assets::botonCreditosApretado(sf::Texture &textura)
{
	return Assets::cargarBoton(12, textura);
}

bool Assets::botonVolverNormal(sf::Texture &textura)
{
	return Assets::cargarBoton(13, textura);
}

bool Assets::botonVolverOver(sf::Texture &textura)
{
	return Assets::cargarBoton(14, textura);
}

bool Assets::botonVolverApretado(sf::Texture &textura)
{
	return Assets::cargarBoton(15, textura);
}

bool Assets::botonSalirNormal(sf::Texture &textura)
{
	return Assets::cargarBoton(16, textura);
}

bool Assets::botonSalirOver(sf::Texture &textura)
{
	return Assets::cargarBoton(17, textura);
}

bool Assets::botonSalirApretado(sf::Texture &textura)
{
	return Assets::cargarBoton(18, textura);
}

bool Assets::islaCompleta(sf::Texture &textura)
{
	return Assets::cargarIsla(textura);
}

bool Assets::agua(sf::Texture &textura)
{
	return Assets::cargarTile(73, textura);
}


bool Assets::cargarFuenteJuego(sf::Font &fuente)
{
	sf::Font miFuente;

	if (!miFuente.loadFromFile("../Assets/Plumpfull.ttf"))
	{
		std::cout << "No cargo la fuente." << std::endl;
		return false;
	}
	else
	{
		fuente = miFuente;
		return true;
	}
}

bool Assets::cargarSonido(const char* nombreSonido, sf::SoundBuffer &buffer)
{
	sf::SoundBuffer miBuffer;

	if (!miBuffer.loadFromFile(nombreSonido))
	{
		std::cout << "No cargo el sonido " << nombreSonido << std::endl;
		return false;
	}
	else
	{
		buffer = miBuffer;
		return true;
	}
}

sf::SoundBuffer* Assets::bufferGolpe = nullptr;
sf::SoundBuffer* Assets::bufferMuerte = nullptr;
sf::SoundBuffer* Assets::bufferAtaque = nullptr;
sf::Sound* Assets::sonidoGolpe = nullptr;
sf::Sound* Assets::sonidoMuerte = nullptr;
sf::Sound* Assets::sonidoAtaque = nullptr;
sf::Music* Assets::miMusica = nullptr;

void Assets::playSonido(int num)
{
	switch (num)
	{
	case 0:
		if (bufferAtaque == nullptr)
		{
			bufferAtaque = new sf::SoundBuffer;
			cargarSonido("../Assets/Ataque.wav", *bufferAtaque);
		}
		if (sonidoAtaque == nullptr)
		{
			sonidoAtaque = new sf::Sound;
			sonidoAtaque->setBuffer(*bufferAtaque);
		}
		sonidoAtaque->play();
		break;
	case 1:
		if (bufferGolpe == nullptr)
		{
			bufferGolpe = new sf::SoundBuffer;
			cargarSonido("../Assets/Impacto.wav", *bufferGolpe);
		}
		if (sonidoGolpe == nullptr)
		{
			sonidoGolpe = new sf::Sound;
			sonidoGolpe->setBuffer(*bufferGolpe);
		}
		sonidoGolpe->play();
		break;
	case 2:
		if (bufferMuerte == nullptr)
		{
			bufferMuerte = new sf::SoundBuffer;
			cargarSonido("../Assets/Muerte.wav", *bufferMuerte);
		}
		if (sonidoMuerte == nullptr)
		{
			sonidoMuerte = new sf::Sound;
			sonidoMuerte->setBuffer(*bufferMuerte);
		}
		sonidoMuerte->play();
		break;
	default:
		break;
	}
}

void Assets::playMusica(int num)
{
	if (miMusica == nullptr)
	{
		miMusica = new sf::Music;
	}

	switch (num)
	{
	case 0:
		if (!miMusica->openFromFile("../Assets/Incoming.ogg"))
		{
			std::cout << "No cargo Incoming.ogg" << std::endl;
		}
		else
		{
			Datos::setMusicaMenuOn(true);
			miMusica->setLoop(true);
			miMusica->play();
		}
		break;
	case 1:
		if (!miMusica->openFromFile("../Assets/HelipadSiege.ogg"))
		{
			std::cout << "No cargo HelipadSiege.ogg" << std::endl;
		}
		else
		{
			miMusica->setLoop(true);
			miMusica->play();
		}
		break;
	case 2:
		if (!miMusica->openFromFile("../Assets/WARGODS.ogg"))
		{
			std::cout << "No cargo WARGODS.ogg" << std::endl;
		}
		else
		{
			miMusica->setLoop(true);
			miMusica->play();
		}
		break;
	default:
		break;
	}
}

void Assets::stopMusica()
{
	if (miMusica != nullptr)
	{
		Datos::setMusicaMenuOn(false);
		miMusica->stop();
	}
}

void Assets::borrarAssets()
{
	if (bufferAtaque != nullptr)
	{
		delete(bufferAtaque);
	}
	if (bufferGolpe != nullptr)
	{
		delete(bufferGolpe);
	}
	if (bufferMuerte != nullptr)
	{
		delete(bufferMuerte);
	}
	if (sonidoAtaque != nullptr)
	{
		delete(sonidoAtaque);
	}
	if (sonidoGolpe != nullptr)
	{
		delete(sonidoGolpe);
	}
	if (sonidoMuerte != nullptr)
	{
		delete(sonidoMuerte);
	}
	if (miMusica != nullptr)
	{
		delete(miMusica);
	}
}

}