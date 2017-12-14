#ifndef LISTA
#define LISTA

namespace Octavio
{

template <typename T>
struct Node {
	T guardado;
	Node* nodoSiguiente = nullptr;
	Node* nodoAnterior = nullptr;
};

template <typename T>
class Lista {
private:
	Node<T>* primero;
	Node<T>* ultimo;

	int cantidadDeNodos = 0;
		
	void actualizarPrimero(Node<T>* miNodo)
	{
		primero = miNodo;
	}

	void actualizarUltimo(Node<T>* miNodo)
	{
		ultimo = miNodo;
	}

public:
	Lista(T dato) :	cantidadDeNodos(1),	primero(new Node<T>)
	{
		primero->guardado = dato;
		primero->nodoAnterior = nullptr;
		primero->nodoSiguiente = nullptr;
		actualizarUltimo(primero);
	}

	virtual ~Lista()
	{
	//	removeAll();
	}

	bool sum(double &total)
	{
		if (primero != nullptr)
		{
			Node<T>* nodoActual = primero;
			total = primero->guardado;

			while (nodoActual->nodoSiguiente != nullptr)
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

	bool average(double &total)
	{
		if (primero != nullptr)
		{
			Node<T>* nodoActual = primero;
			total = primero->guardado;
			double contador = 1;

			while (nodoActual->nodoSiguiente != nullptr)
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

	bool min(double &min)
	{
		if (primero != nullptr)
		{
			Node<T>* nodoActual = primero;
			min = primero->guardado;

			while (nodoActual->nodoSiguiente != nullptr)
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

	bool max(double &max)
	{
		if (primero != nullptr)
		{
			Node<T>* nodoActual = primero;
			max = primero->guardado;

			while (nodoActual->nodoSiguiente != nullptr)
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

	int count() const
	{
		return cantidadDeNodos;
	}

	Node<T>* first() const
	{
		return primero;
	}

	Node<T>* last() const
	{
		return ultimo;
	}

	void addFront(T dato)
	{
		Node<T>* nuevoNodo = new Node<T>;
		nuevoNodo->guardado = dato;
		if (cantidadDeNodos != 0)
		{
			primero->nodoAnterior = nuevoNodo;
			nuevoNodo->nodoSiguiente = primero;
			nuevoNodo->nodoAnterior = nullptr;
		}
		else
		{
			actualizarUltimo(nuevoNodo);
			nuevoNodo->nodoAnterior = nullptr;
			nuevoNodo->nodoSiguiente = nullptr;
		}
		cantidadDeNodos++;
		actualizarPrimero(nuevoNodo);
	}

	void addBack(T dato)
	{
		Node<T>* nuevoNodo = new Node<T>;
		nuevoNodo->guardado = dato;
		if (cantidadDeNodos != 0)
		{
			ultimo->nodoSiguiente = nuevoNodo;
			nuevoNodo->nodoAnterior = ultimo;
			nuevoNodo->nodoSiguiente = nullptr;
		}
		else
		{
			actualizarPrimero(nuevoNodo);
			nuevoNodo->nodoAnterior = nullptr;
			nuevoNodo->nodoSiguiente = nullptr;
		}
		cantidadDeNodos++;
		actualizarUltimo(nuevoNodo);
	}

	bool addAt(int posicion, T nuevoDato)
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

	void removeFirst()
	{
		if (cantidadDeNodos > 0)
		{
			cantidadDeNodos--;
			if (primero->nodoSiguiente != nullptr)
			{
				Node<T>* temporal = primero->nodoSiguiente;
				delete(primero);
				temporal->nodoAnterior = nullptr;
				actualizarPrimero(temporal);
			}
			else
			{
				delete(primero);
				actualizarPrimero(nullptr);
				actualizarUltimo(nullptr);
			}
		}
	}

	void removeLast()
	{
		if (cantidadDeNodos > 0)
		{
			cantidadDeNodos--;
			if (ultimo->nodoAnterior != nullptr)
			{
				Node<T>* temporal = ultimo->nodoAnterior;
				delete(ultimo);
				temporal->nodoSiguiente = nullptr;
				actualizarUltimo(temporal);
			}
			else
			{
				delete(ultimo);
				actualizarPrimero(nullptr);
				actualizarUltimo(nullptr);
			}
		}
	}

	void removeAll()
	{
		int contador = cantidadDeNodos;
		for (int i = 0; i < contador; i++)
		{
			removeFirst();
		}
	}

	bool removeAt(int num)
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
				temporal->nodoAnterior = nullptr;
				temporal->nodoSiguiente = nullptr;
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
				temporal->nodoAnterior = nullptr;
				temporal->nodoSiguiente = nullptr;
				delete(temporal);
			}

			return true;
		}

		else
		{
			return false;
		}
	}

	void removeValue(double num)
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

	bool showList()
	{
		if (cantidadDeNodos > 0)
		{
			Node<T>* temporal = primero;

			for (int i = 0; i < cantidadDeNodos; i++)
			{
				if (temporal != nullptr)
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

	T operator [](int num)
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
		else
		{
			return 0;
		}
	}
};

}

#endif