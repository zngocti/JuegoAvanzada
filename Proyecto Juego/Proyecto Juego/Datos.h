#ifndef DATOS_H
#define DATOS_H

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
public:
	static int getAnchoPantalla();
	static int getAltoPantalla();
	static int getAnchoDeTitleAgua();
	static int getZDelAgua();
	static int getTilesExtra();
};

}

#endif
