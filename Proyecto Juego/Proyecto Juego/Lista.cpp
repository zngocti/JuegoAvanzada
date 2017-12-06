#include "Lista.h"

namespace Octavio
{
	template <typename T>
	void Lista::actualizarPrimero(Node<T>* miNodo)
	{
		primero = miNodo;
	}

	template <typename T>
	void Lista::actualizarUltimo(Node<T>* miNodo)
	{
		ultimo = miNodo;
	}

	template <typename T>
	Lista::Lista(T dato) : cantidadDeNodos(1) 
	{
		Node<T>* primerNodo = new Node<T>;
		primerNodo->guardado = dato;
		primerNodo->nodoAnterior = NULL;
		primerNodo->nodoSiguiente = NULL;
		actualizarPrimero(primerNodo);
		actualizarUltimo(primerNodo);
	}

	template <typename T>
	virtual Lista::~List()
	{
		removeAll();
	}

	template <typename T>
	bool Lista::sum(double &total)
	{
		if (primero != NULL)
		{
			Node<T>* nodoActual = primero;
			total = primero->guardado;

			while (nodoActual->nodoSiguiente != NULL)
			{
				nodoActual = nodoActual->nodoSiguiente;
				total = total + nodoActual->guardado;
			}

			return true;
		}
		else
		{
			return false;
		}
	}

	template <typename T>
	bool Lista::average(double &total)
	{
		if (primero != NULL)
		{
			Node<T>* nodoActual = primero;
			total = primero->guardado;
			double contador = 1;

			while (nodoActual->nodoSiguiente != NULL)
			{
				nodoActual = nodoActual->nodoSiguiente;
				total = total + nodoActual->guardado;
				contador++;
			}

			total = (total / contador);
			return true;
		}
		else
		{
			return false;
		}
	}

	template <typename T>
	bool Lista::min(double &min)
	{
		if (primero != NULL)
		{
			Node<T>* nodoActual = primero;
			min = primero->guardado;

			while (nodoActual->nodoSiguiente != NULL)
			{
				nodoActual = nodoActual->nodoSiguiente;
				if (nodoActual->guardado < min)
				{
					min = nodoActual->guardado;
				}
			}

			return true;
		}
		else
		{
			return false;
		}
	}

	template <typename T>
	bool Lista::max(double &max)
	{
		if (primero != NULL)
		{
			Node<T>* nodoActual = primero;
			max = primero->guardado;

			while (nodoActual->nodoSiguiente != NULL)
			{
				nodoActual = nodoActual->nodoSiguiente;
				if (nodoActual->guardado > max)
				{
					max = nodoActual->guardado;
				}
			}

			return true;
		}
		else
		{
			return false;
		}
	}

	template <typename T>
	int Lista::count() const
	{
		return cantidadDeNodos;
	}

	template <typename T>
	Node<T>* Lista::first() const
	{
		return primero;
	}

	template <typename T>
	Node<T>* Lista::last() const
	{
		return ultimo;
	}

	template <typename T>
	void Lista::addFront(T dato)
	{
		Node<T>* nuevoNodo = new Node<T>;
		nuevoNodo->guardado = dato;
		if (cantidadDeNodos != 0)
		{
			primero->nodoAnterior = nuevoNodo;
			nuevoNodo->nodoSiguiente = primero;
			nuevoNodo->nodoAnterior = NULL;
		}
		else
		{
			actualizarUltimo(nuevoNodo);
			nuevoNodo->nodoAnterior = NULL;
			nuevoNodo->nodoSiguiente = NULL;
		}
		cantidadDeNodos++;
		actualizarPrimero(nuevoNodo);
	}

	template <typename T>
	void Lista::addBack(T dato)
	{
		Node<T>* nuevoNodo = new Node<T>;
		nuevoNodo->guardado = dato;
		if (cantidadDeNodos != 0)
		{
			ultimo->nodoSiguiente = nuevoNodo;
			nuevoNodo->nodoAnterior = ultimo;
			nuevoNodo->nodoSiguiente = NULL;
		}
		else
		{
			actualizarPrimero(nuevoNodo);
			nuevoNodo->nodoAnterior = NULL;
			nuevoNodo->nodoSiguiente = NULL;
		}
		cantidadDeNodos++;
		actualizarUltimo(nuevoNodo);
	}

	template <typename T>
	bool Lista::addAt(int posicion, T nuevoDato)
	{
		if (posicion == 0)
		{
			addFront(nuevoDato);
			return true;
		}
		else if (posicion == cantidadDeNodos)
		{
			addBack(nuevoDato);
			return true;
		}
		else if (posicion > cantidadDeNodos)
		{
			return false;
		}

		else
		{
			Node<T>* nodoActual = primero;
			Node<T>* tAnterior = primero;
			for (int i = 0; i < posicion; i++)
			{
				tAnterior = nodoActual;
				nodoActual = nodoActual->nodoSiguiente;
			}

			Node<T>* nuevoNodo = new Node<T>;
			nuevoNodo->guardado = nuevoDato;
			nuevoNodo->nodoAnterior = nodoActual->nodoAnterior;
			nuevoNodo->nodoSiguiente = nodoActual;
			nodoActual->nodoAnterior = nuevoNodo;
			tAnterior->nodoSiguiente = nuevoNodo;
			cantidadDeNodos++;
			return true;
		}
	}

	template <typename T>
	void Lista::removeFirst()
	{
		if (cantidadDeNodos > 0)
		{
			cantidadDeNodos--;
			if (primero->nodoSiguiente != NULL)
			{
				Node<T>* temporal = primero->nodoSiguiente;
				delete(primero);
				temporal->nodoAnterior = NULL;
				actualizarPrimero(temporal);
			}
			else
			{
				delete(primero);
				actualizarPrimero(NULL);
				actualizarUltimo(NULL);
			}
		}
	}

	template <typename T>
	void Lista::removeLast()
	{
		if (cantidadDeNodos > 0)
		{
			cantidadDeNodos--;
			if (ultimo->nodoAnterior != NULL)
			{
				Node<T>* temporal = ultimo->nodoAnterior;
				delete(ultimo);
				temporal->nodoSiguiente = NULL;
				actualizarUltimo(temporal);
			}
			else
			{
				delete(ultimo);
				actualizarPrimero(NULL);
				actualizarUltimo(NULL);
			}
		}
	}

	template <typename T>
	void Lista::removeAll()
	{
		int contador = cantidadDeNodos;
		for (int i = 0; i < contador; i++)
		{
			removeFirst();
		}
	}

	template <typename T>
	bool Lista::removeAt(int num)
	{
		if (num < cantidadDeNodos)
		{
			if (num == 0)
			{
				removeFirst();
			}
			else if (num == cantidadDeNodos - 1)
			{
				removeLast();
			}
			else if (num <= cantidadDeNodos / 2)
			{
				Node<T>* temporal = primero;
				for (int i = 0; i < num; i++)
				{
					temporal = temporal->nodoSiguiente;
				}
				cantidadDeNodos--;
				Node<T>* tSiguiente = temporal->nodoSiguiente;
				Node<T>* tAnterior = temporal->nodoAnterior;
				tSiguiente->nodoAnterior = tAnterior;
				tAnterior->nodoSiguiente = tSiguiente;
				temporal->nodoAnterior = NULL;
				temporal->nodoSiguiente = NULL;
				delete(temporal);
			}
			else
			{
				num = cantidadDeNodos - num;
				Node<T>* temporal = ultimo;
				for (int i = 0; i < num - 1; i++)
				{
					temporal = temporal->nodoAnterior;
				}
				cantidadDeNodos--;
				Node<T>* tSiguiente = temporal->nodoSiguiente;
				Node<T>* tAnterior = temporal->nodoAnterior;
				tSiguiente->nodoAnterior = tAnterior;
				tAnterior->nodoSiguiente = tSiguiente;
				temporal->nodoAnterior = NULL;
				temporal->nodoSiguiente = NULL;
				delete(temporal);
			}

			return true;
		}

		else
		{
			return false;
		}
	}

	template <typename T>
	void Lista::removeValue(double num)
	{
		if (cantidadDeNodos > 0)
		{
			Node<T>* temporal = primero;
			for (size_t i = 0; i < cantidadDeNodos; i++)
			{
				if (temporal->guardado == num)
				{
					removeAt(i);
					i = cantidadDeNodos;
				}
			}
		}
	}

	template <typename T>
	bool Lista::showList()
	{
		if (cantidadDeNodos > 0)
		{
			Node<T>* temporal = primero;

			for (int i = 0; i < cantidadDeNodos; i++)
			{
				if (temporal != NULL)
				{
					std::cout << temporal->guardado << " ";
					if (i != cantidadDeNodos - 1)
					{
						temporal = temporal->nodoSiguiente;
					}
				}
			}
			std::cout << std::endl;

			return true;
		}

		else
		{
			return false;
		}
	}

	template <typename T>
	T Lista::operator [](int num)
	{
		if (cantidadDeNodos != 0 && num < cantidadDeNodos)
		{
			Node<T>* actual = primero;
			for (int i = 0; i < num; i++)
			{
				actual = actual->nodoSiguiente;
			}

			return actual->guardado;
		}
	}
}