#include "Barco.h"

namespace Octavio
{

sf::Texture* Barco::texturaBala = nullptr;
sf::Texture* Barco::texturaMarinero = nullptr;
sf::Time Barco::tiempoInmune = sf::seconds(2.0f);

Marinero* Barco::marinero = nullptr;

Barco::Barco() : disparos(Datos::getDisparosBarco()), estaPoseido(false), listaDeBalas(Lista<Bala*>(new Bala())), sprite1(new sf::Sprite()), resistencia(Datos::getVidaBarco()),
				 puedeSerGolpeado(true), miExplosion(nullptr)
{
	setPosition(-500, -500);

	if (texturaBala == nullptr)
	{
		texturaBala = new sf::Texture();
		Assets::cannonBall(*texturaBala);
	}

	for (int i = 0; i < Datos::getBalasPorBarco() - 1; i++)
	{
		listaDeBalas.addBack(new Bala());
		listaDeBalas[i]->setBarcoOrigen(this);
		listaDeBalas[i]->setSprite(*texturaBala);
		listaDeBalas[i]->setMedio();
		listaDeBalas[i]->setZ(Datos::getZDeBalas());
	}

	miExplosion = new Explosion();
	miExplosion->setSprite(*(Explosion::getTextura3()));
	miExplosion->setMedio();
	miExplosion->setZ(Datos::getZDeExplosion());
	miExplosion->resetExplosion();
}

Barco::~Barco()
{
	listaDeBalas.removeAll();

	if (texturaBala != nullptr)
	{
		delete(texturaBala);
		texturaBala = nullptr;
	}

	if (texturaMarinero != nullptr)
	{
		delete(texturaMarinero);
		texturaMarinero = nullptr;
	}

	delete(sprite1);
}

int Barco::getDisparos() const
{
	return disparos;
}

int Barco::getResistencia() const
{
	return resistencia;
}

int Barco::getValorPuntos() const
{
	return valorPuntos;
}

bool Barco::getEstaPoseido() const
{
	return estaPoseido;
}

sf::Time Barco::getCDRecuperacion() const
{
	return cdRecuperacion;
}

bool Barco::getPuedeSerGolpeado() const
{
	return puedeSerGolpeado;
}

void Barco::setSprite1(const sf::Sprite &unSprite)
{
	*sprite1 = unSprite;
}

void Barco::setSprite1(const sf::Texture &miTextura)
{
	sprite1->setTexture(miTextura);
}

void Barco::setMedio1()
{
	sprite1->setOrigin(sf::Vector2f(sprite1->getLocalBounds().width, sprite1->getLocalBounds().height) / 2.f);
}

void Barco::setRotation1(float num)
{
	sprite1->setRotation(num);
}

void Barco::mover(sf::Keyboard::Key tecla)
{
	if (tecla == sf::Keyboard::D && getX() + getSprite().getLocalBounds().width / 2 <= Datos::getAnchoPantalla())
	{
		move(Datos::getVelocidadJugador(), 0.0f);
	}
	else if (tecla == sf::Keyboard::A && getX() - getSprite().getLocalBounds().width / 2 >= 0)
	{
		move(- (Datos::getVelocidadJugador()), 0.0f);
	}
	else if (tecla == sf::Keyboard::S && getY() + getSprite().getLocalBounds().height / 2 <= Datos::getAltoPantalla())
	{
		move(0.0f, Datos::getVelocidadJugador());
	}
	else if (tecla == sf::Keyboard::W && getY() - getSprite().getLocalBounds().height / 2 >= 0)
	{
		move(0.0f, -(Datos::getVelocidadJugador()));
	}
}

void Barco::setDisparos(int num)
{
	disparos = num;
}

void Barco::setResistencia(int num)
{
	resistencia = num;
}

void Barco::atacar()
{
	if (getUso() && !estaPoseido)
	{
		for (int i = 0; i < listaDeBalas.count(); i++)
		{
			if (!(listaDeBalas[i]->getUso()))
			{
				resetAtaque();
				listaDeBalas[i]->restartUso();
				listaDeBalas[i]->setPosition(getSprite().getPosition().x - getSprite().getLocalBounds().width / 2, getSprite().getPosition().y);
				listaDeBalas[i]->getComportamiento()->setData(7, true);
				i = listaDeBalas.count();
			}
		}
	}
	else if (getUso() && estaPoseido && disparos > 0)
	{
		for (int i = 0; i < listaDeBalas.count(); i++)
		{
			if (!(listaDeBalas[i]->getUso()))
			{
				resetAtaque();
				listaDeBalas[i]->restartUso();
				listaDeBalas[i]->setPosition(getSprite().getPosition().x + getSprite().getLocalBounds().width / 2, getSprite().getPosition().y);
				listaDeBalas[i]->getComportamiento()->setData(3, false);
				disparos--;
				Datos::usarBalas();
				Assets::playSonido(0);
				i = listaDeBalas.count();
			}
		}
	}
}

void Barco::impacto()
{
	if (puedeSerGolpeado && resistencia != 0)
	{
		resistencia--;
		if (!estaPoseido)
		{
			Datos::addPuntos(1);
		}
		else
		{
			Datos::restarVida();
		}
		morir();
	}
}

void Barco::impactoDeBarco()
{
	if (puedeSerGolpeado)
	{
		impacto();
		puedeSerGolpeado = false;
		cdRecuperacion = Datos::timerJuego.getElapsedTime();
	}
}

void Barco::morir()
{
	Assets::playSonido(2);
	miExplosion->setPosition(getSprite().getPosition().x, getSprite().getPosition().y);
	miComportamiento->activarReciclar();
	miExplosion->iniciarExplosion();
}

void Barco::abordar()
{
	estaPoseido = true;
	setRotation(Datos::getRotacionPoseido());
	setRotation1(Datos::getRotacionPoseido());
	Datos::setVida(resistencia);
	Datos::setBalas(1);

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

void Barco::abandonar()
{
	estaPoseido = false;
	setRotation(Datos::getRotacionInicial());
	setRotation1(Datos::getRotacionInicial());
	setZ(Datos::getZDeBarcos());
	morir();
}

void Barco::resetBarco()
{
	setPosition(-500, -500);
	estaPoseido = false;
	resistencia = Datos::getVidaBarco();
	puedeSerGolpeado = true;
	setRotation(Datos::getRotacionInicial());
	setRotation1(Datos::getRotacionInicial());
	setZ(Datos::getZDeBarcos());
	setDisparos(Datos::getDisparosBarco());
	cdRecuperacion = sf::Time::Zero;
}

void Barco::resetExtra()
{
	miExplosion->resetExplosion();

	for (int i = 0; i < Datos::getBalasPorBarco(); i++)
	{
		listaDeBalas[i]->resetBala();
	}
}

void Barco::dispararMarinero()
{
	if (getUso() && estaPoseido && !(marinero->getUso()))
	{
		marinero->setBarcoOrigen(this);
		marinero->restartUso();
		marinero->setPosition(getSprite().getPosition().x + getSprite().getLocalBounds().width / 2, getSprite().getPosition().y);
	}
}

void Barco::checkTimers()
{
	if (Datos::timerJuego.getElapsedTime() - cdRecuperacion >= tiempoInmune && !puedeSerGolpeado)
	{
		puedeSerGolpeado = true;
	}
}

Lista<Bala*> Barco::getListaDeBalas() const
{
	return listaDeBalas;
}

void Barco::activarComportamiento()
{
	if (miComportamiento != nullptr && !estaPoseido)
	{
		miComportamiento->iniciarComportamiento(this);
	}
}

Marinero* Barco::getMarinero()
{
	if (texturaMarinero == nullptr)
	{
		texturaMarinero = new sf::Texture();
		Assets::crew1(*texturaMarinero);
	}

	if (marinero == nullptr)
	{
		marinero = new Marinero();

		marinero->setSprite(*texturaMarinero);
		marinero->setZ(Datos::getZDeMarinero());
		marinero->setMedio();
	}

	return marinero;
}

Explosion* Barco::getExplosion() const
{
	return miExplosion;
}

}