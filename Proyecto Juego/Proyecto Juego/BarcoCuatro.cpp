#include "BarcoCuatro.h"

namespace Octavio
{

BarcoCuatro::BarcoCuatro() : sprite2(new sf::Sprite()), sprite3(new sf::Sprite())
{
	setDisparos(Datos::getDisparosBarcoCuatro());
	setResistencia(Datos::getVidaBarcoCuatro());
}

BarcoCuatro::~BarcoCuatro()
{
	delete (sprite2);
	delete (sprite3);
}

void BarcoCuatro::setSprite2(const sf::Sprite &unSprite)
{
	*sprite2 = unSprite;
}

void BarcoCuatro::setSprite2(const sf::Texture &miTextura)
{
	sprite2->setTexture(miTextura);
}

void BarcoCuatro::setSprite3(const sf::Sprite &unSprite)
{
	*sprite3 = unSprite;
}

void BarcoCuatro::setSprite3(const sf::Texture &miTextura)
{
	sprite3->setTexture(miTextura);
}

void BarcoCuatro::setMedio2()
{
	sprite2->setOrigin(sf::Vector2f(sprite2->getLocalBounds().width, sprite2->getLocalBounds().height) / 2.f);
}

void BarcoCuatro::setMedio3()
{
	sprite3->setOrigin(sf::Vector2f(sprite3->getLocalBounds().width, sprite3->getLocalBounds().height) / 2.f);
}

void BarcoCuatro::setRotation2(float num)
{
	sprite2->setRotation(num);
}

void BarcoCuatro::setRotation3(float num)
{
	sprite3->setRotation(num);
}

void BarcoCuatro::atacar()
{
	if (getUso() && !estaPoseido)
	{
		if (getSprite().getPosition().x < 0 + getSprite().getLocalBounds().width / 2 || getSprite().getPosition().x > Datos::getAnchoPantalla() - getSprite().getLocalBounds().width / 2 ||
			getSprite().getPosition().y < 0 + getSprite().getLocalBounds().height / 2 || getSprite().getPosition().y > Datos::getAltoPantalla() - getSprite().getLocalBounds().height / 2)
		{
			resetAtaque();
		}
		else
		{
			for (int i = 0; i < listaDeBalas.count() - 3; i++)
			{
				if (!(listaDeBalas[i]->getUso()) && !(listaDeBalas[i + 1]->getUso()) && !(listaDeBalas[i + 2]->getUso()) && !(listaDeBalas[i + 3]->getUso()))
				{
					resetAtaque();
					listaDeBalas[i]->restartUso();
					listaDeBalas[i + 1]->restartUso();
					listaDeBalas[i + 2]->restartUso();
					listaDeBalas[i + 3]->restartUso();
					listaDeBalas[i]->setPosition(getSprite().getPosition().x - Datos::getPixelesExtraDelBarco(),
												 getSprite().getPosition().y + getSprite().getLocalBounds().height / 2 - Datos::getPixelesExtraDelBarco());
					listaDeBalas[i + 1]->setPosition(getSprite().getPosition().x + Datos::getPixelesExtraDelBarco(),
													 getSprite().getPosition().y + getSprite().getLocalBounds().height / 2 - Datos::getPixelesExtraDelBarco());
					listaDeBalas[i + 2]->setPosition(getSprite().getPosition().x - Datos::getPixelesExtraDelBarco(),
													 getSprite().getPosition().y - getSprite().getLocalBounds().height / 2 + Datos::getPixelesExtraDelBarco());
					listaDeBalas[i + 3]->setPosition(getSprite().getPosition().x + Datos::getPixelesExtraDelBarco(),
													 getSprite().getPosition().y - getSprite().getLocalBounds().height / 2 + Datos::getPixelesExtraDelBarco());
					listaDeBalas[i]->getComportamiento()->setData(5, true);
					listaDeBalas[i + 1]->getComportamiento()->setData(5, true);
					listaDeBalas[i + 2]->getComportamiento()->setData(1, true);
					listaDeBalas[i + 3]->getComportamiento()->setData(1, true);
					i = listaDeBalas.count();
				}
			}
		}
	}
	else if (getUso() && estaPoseido && disparos > 0)
	{
		for (int i = 0; i < listaDeBalas.count() - 3; i++)
		{
			if (!(listaDeBalas[i]->getUso()) && !(listaDeBalas[i + 1]->getUso()) && !(listaDeBalas[i + 2]->getUso()) && !(listaDeBalas[i + 3]->getUso()))
			{
				resetAtaque();
				listaDeBalas[i]->restartUso();
				listaDeBalas[i + 1]->restartUso();
				listaDeBalas[i + 2]->restartUso();
				listaDeBalas[i + 3]->restartUso();
				listaDeBalas[i]->setPosition(getSprite().getPosition().x - Datos::getPixelesExtraDelBarco(),
					getSprite().getPosition().y + getSprite().getLocalBounds().height / 2 - Datos::getPixelesExtraDelBarco());
				listaDeBalas[i + 1]->setPosition(getSprite().getPosition().x + Datos::getPixelesExtraDelBarco(),
					getSprite().getPosition().y + getSprite().getLocalBounds().height / 2 - Datos::getPixelesExtraDelBarco());
				listaDeBalas[i + 2]->setPosition(getSprite().getPosition().x - Datos::getPixelesExtraDelBarco(),
					getSprite().getPosition().y - getSprite().getLocalBounds().height / 2 + Datos::getPixelesExtraDelBarco());
				listaDeBalas[i + 3]->setPosition(getSprite().getPosition().x + Datos::getPixelesExtraDelBarco(),
					getSprite().getPosition().y - getSprite().getLocalBounds().height / 2 + Datos::getPixelesExtraDelBarco());
				listaDeBalas[i]->getComportamiento()->setData(5, false);
				listaDeBalas[i + 1]->getComportamiento()->setData(5, false);
				listaDeBalas[i + 2]->getComportamiento()->setData(1, false);
				listaDeBalas[i + 3]->getComportamiento()->setData(1, false);
				disparos--;
				Datos::usarBalas();
				i = listaDeBalas.count();
			}
		}
	}
}

void BarcoCuatro::abordar()
{
	estaPoseido = true;
	setRotation(Datos::getRotacionPoseido());
	setRotation1(Datos::getRotacionPoseido());
	setRotation2(Datos::getRotacionPoseido());
	setRotation3(Datos::getRotacionPoseido());

	Datos::setVida(resistencia);
	Datos::setBalas(3);

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

void BarcoCuatro::abandonar()
{
	estaPoseido = false;
	setRotation(Datos::getRotacionInicial());
	setRotation1(Datos::getRotacionInicial());
	setRotation2(Datos::getRotacionInicial());
	setRotation3(Datos::getRotacionInicial());
	morir();
}

void BarcoCuatro::resetBarco()
{
	estaPoseido = false;
	resistencia = Datos::getVidaBarcoCuatro();
	puedeSerGolpeado = true;
	setSprite(*sprite1);
	setRotation(Datos::getRotacionInicial());
	setRotation1(Datos::getRotacionInicial());
	setRotation2(Datos::getRotacionInicial());
	setRotation3(Datos::getRotacionInicial());
	setZ(Datos::getZDeBarcos());
	setDisparos(Datos::getDisparosBarcoCuatro());
	cdRecuperacion = sf::Time::Zero;
}

void BarcoCuatro::impacto()
{
	if (puedeSerGolpeado && resistencia != 0)
	{
		resistencia--;
		switch (resistencia)
		{
		case 1:
			sprite3->setPosition(getSprite().getPosition().x, getSprite().getPosition().y);
			setSprite(*sprite3);
			if (estaPoseido)
			{
				Datos::restarVida();
			}
			break;
		case 2:
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
				Datos::addPuntos(3);
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