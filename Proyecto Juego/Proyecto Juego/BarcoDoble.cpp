#include "BarcoDoble.h"

namespace Octavio
{

BarcoDoble::BarcoDoble() : sprite2(new sf::Sprite())
{
	setDisparos(Datos::getDisparosBarcoDoble());
	setResistencia(Datos::getVidaBarcoDoble());
}

BarcoDoble::~BarcoDoble()
{
	delete(sprite2);
}

void BarcoDoble::setSprite2(const sf::Sprite &unSprite)
{
	*sprite2 = unSprite;
}

void BarcoDoble::setSprite2(const sf::Texture &miTextura)
{
	sprite2->setTexture(miTextura);
}

void BarcoDoble::setMedio2()
{
	sprite2->setOrigin(sf::Vector2f(sprite2->getLocalBounds().width, sprite2->getLocalBounds().height) / 2.f);
}

void BarcoDoble::setRotation2(float num)
{
	sprite2->setRotation(num);
}

void BarcoDoble::atacar()
{
	if (getUso() && !estaPoseido)
	{
		for (int i = 0; i < listaDeBalas.count() - 1; i++)
		{
			if (!(listaDeBalas[i]->getUso()) && !(listaDeBalas[i + 1]->getUso()))
			{
				resetAtaque();
				listaDeBalas[i]->restartUso();
				listaDeBalas[i + 1]->restartUso();
				listaDeBalas[i]->setPosition(getSprite().getPosition().x - Datos::getPixelesExtraDelBarco(),
											 getSprite().getPosition().y + getSprite().getLocalBounds().height / 2 - Datos::getPixelesExtraDelBarco());
				listaDeBalas[i + 1]->setPosition(getSprite().getPosition().x - Datos::getPixelesExtraDelBarco(),
												 getSprite().getPosition().y - getSprite().getLocalBounds().height / 2 + Datos::getPixelesExtraDelBarco());
				listaDeBalas[i]->getComportamiento()->setData(6, true);
				listaDeBalas[i + 1]->getComportamiento()->setData(8, true);
				i = listaDeBalas.count();
			}
		}
	}
	else if (getUso() && estaPoseido && disparos > 0)
	{
		for (int i = 0; i < listaDeBalas.count() - 1; i++)
		{
			if (!(listaDeBalas[i]->getUso()) && !(listaDeBalas[i + 1]->getUso()))
			{
				resetAtaque();
				listaDeBalas[i]->restartUso();
				listaDeBalas[i + 1]->restartUso();
				listaDeBalas[i]->setPosition(getSprite().getPosition().x + Datos::getPixelesExtraDelBarco(),
					getSprite().getPosition().y + getSprite().getLocalBounds().height / 2 - Datos::getPixelesExtraDelBarco());
				listaDeBalas[i + 1]->setPosition(getSprite().getPosition().x + Datos::getPixelesExtraDelBarco(),
					getSprite().getPosition().y - getSprite().getLocalBounds().height / 2 + Datos::getPixelesExtraDelBarco());
				listaDeBalas[i]->getComportamiento()->setData(4, false);
				listaDeBalas[i + 1]->getComportamiento()->setData(2, false);
				disparos--;
				Datos::usarBalas();
				Assets::playSonido(0);
				i = listaDeBalas.count();
			}
		}
	}
}

void BarcoDoble::abordar()
{
	estaPoseido = true;
	setRotation(Datos::getRotacionPoseido());
	setRotation1(Datos::getRotacionPoseido());
	setRotation2(Datos::getRotacionPoseido());

	Datos::setVida(resistencia);
	Datos::setBalas(2);

	if (getX() < 0 + getSprite().getLocalBounds().width / 2)
	{
		setPosition(getSprite().getLocalBounds().width / 2, getY());
	}
	if (getX() > Datos::getAnchoPantalla() - getSprite().getLocalBounds().width / 2)
	{
		setPosition(Datos::getAnchoPantalla() - getSprite().getLocalBounds().width / 2, getY());
	}
	if (getY() < 0 + getSprite().getLocalBounds().height / 2)
	{
		setPosition(getX(), getSprite().getLocalBounds().height / 2);
	}
	if (getY() > Datos::getAltoPantalla() - getSprite().getLocalBounds().height / 2)
	{
		setPosition(getX(), Datos::getAltoPantalla() - getSprite().getLocalBounds().height / 2);
	}

	setZ(Datos::getZDelJugador());
}

void BarcoDoble::abandonar()
{
	estaPoseido = false;
	setRotation(Datos::getRotacionInicial());
	setRotation1(Datos::getRotacionInicial());
	setRotation2(Datos::getRotacionInicial());
	morir();
}

void BarcoDoble::resetBarco()
{
	estaPoseido = false;
	resistencia = Datos::getVidaBarcoDoble();
	puedeSerGolpeado = true;
	setSprite(*sprite1);
	setRotation(Datos::getRotacionInicial());
	setRotation1(Datos::getRotacionInicial());
	setRotation2(Datos::getRotacionInicial());
	setZ(Datos::getZDeBarcos());
	setDisparos(Datos::getDisparosBarcoDoble());
	cdRecuperacion = sf::Time::Zero;
}

void BarcoDoble::impacto()
{
	if (puedeSerGolpeado && resistencia != 0)
	{
		resistencia--;
		switch (resistencia)
		{
		case 1:
			Assets::playSonido(1);
			sprite2->setPosition(getSprite().getPosition().x, getSprite().getPosition().y);
			setSprite(*sprite2);
			if (estaPoseido)
			{
				Datos::restarVida();
			}
			break;
		default:
			if (!estaPoseido)
			{
				Datos::addPuntos(2);
			}
			else
			{
				Datos::restarVida();
			}
			morir();
			break;
		}
	}
}

}