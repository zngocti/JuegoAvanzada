#ifndef LISTA_H
#define LISTA_H

namespace Octavio
{
	template <typename T>
	struct Node {
		T guardado;
		Node* nodoSiguiente = NULL;
		Node* nodoAnterior = NULL;
	};

	template <typename T>
	class Lista
	{
	private:
		Node<T>* primero;
		Node<T>* ultimo;

		int cantidadDeNodos = 0;

		void actualizarPrimero(Node<T>* miNodo);
		void actualizarUltimo(Node<T>* miNodo);

	public:
		Lista(T dato);
		~Lista();

		bool sum(double &total);
		bool average(double &total);
		bool min(double &min);
		bool max(double &max);
		int count() const;
		Node<T>* first() const;
		Node<T>* last() const;
		void addFront(T dato);
		void addBack(T dato);
		bool addAt(int posicion, T nuevoDato);
		void removeFirst();
		void removeLast();
		void removeAll();
		bool removeAt(int num);
		void removeValue(double num);
		bool showList();
		T operator [](int num);
	};
}

#endif