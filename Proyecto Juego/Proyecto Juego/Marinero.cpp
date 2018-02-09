#include "Marinero.h"

namespace Octavio
{

Marinero::Marinero()
{
	setPosition(-500, -500);
	setComportamiento(new MovimientoBala());
	miComportamiento->setData(3, false);
}

Marinero::~Marinero()
{

}

}