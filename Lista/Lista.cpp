#include <iostream>

class Nodo
{
public:
    int numeroNodo;
    Nodo* siguiente;
};

class Lista
{
    Nodo* PrimerNodo;

public:
    Lista()
    {
        PrimerNodo = nullptr;
    }

    ~Lista()
    {
        Nodo* NodoActual = PrimerNodo;
        Nodo* NodoTemporal;
        while (NodoActual != nullptr)
        {
            NodoTemporal = NodoActual;
            NodoActual = NodoActual->siguiente;
            delete NodoTemporal;
        }
        std::cout << "Lista destruida\n";
    }

    void mostrar()
    {
        if (PrimerNodo == nullptr)
        {
            std::cout << "La lista esta vacia\n";
            return;
        }

        Nodo* apunta = PrimerNodo;
        while (apunta != nullptr)
        {
            std::cout << "[ " << apunta->numeroNodo << " ]-> ";
            apunta = apunta->siguiente;
        }
        std::cout << "[NULL] ";
    }

    void insertarInicio(int dato)
    {
        Nodo* NuevoNodo = new Nodo();
        NuevoNodo->numeroNodo = dato;
        NuevoNodo->siguiente = PrimerNodo;
        PrimerNodo = NuevoNodo;
    }

    void insertarFinal(int dato)
    {
        Nodo* NuevoNodo = new Nodo();
        NuevoNodo->numeroNodo = dato;
        NuevoNodo->siguiente = nullptr;

        if (PrimerNodo == nullptr)
        {
            PrimerNodo = NuevoNodo;
            return;
        }

        Nodo* NodoActual = PrimerNodo;
        while (NodoActual->siguiente != nullptr)
        {
            NodoActual = NodoActual->siguiente;
        }
        NodoActual->siguiente = NuevoNodo;
    }
    void insertarEnMedio(int dato, int posicion)
    {
        if (posicion <= 0)
        {
            std::cout << "Posicion invalida\n";
            return;
        }

        if (posicion == 1)
        {
            insertarInicio(dato);
            return;
        }

        Nodo* NuevoNodo = new Nodo();
        NuevoNodo->numeroNodo = dato;

        Nodo* NodoActual = PrimerNodo;
        int contador = 1;
        while (NodoActual != nullptr && contador < posicion - 1)
        {
            NodoActual = NodoActual->siguiente;
            contador++;
        }

        if (NodoActual == nullptr)
        {
            std::cout << "Posicion invalida\n";
            return;
        }

        NuevoNodo->siguiente = NodoActual->siguiente;
        NodoActual->siguiente = NuevoNodo;
    }
    void eliminarNodo(int dato)
    {
        if (PrimerNodo == nullptr)
        {
            std::cout << "La lista está vacia, no se puede eliminar el nodo.\n";
            return;
        }

        Nodo* NodoActual = PrimerNodo;
        Nodo* NodoAnterior = nullptr;

        if (NodoActual != nullptr && NodoActual->numeroNodo == dato)
        {
            PrimerNodo = NodoActual->siguiente;
            delete NodoActual;
            return;
        }

        while (NodoActual != nullptr && NodoActual->numeroNodo != dato)
        {
            NodoAnterior = NodoActual;
            NodoActual = NodoActual->siguiente;
        }

        if (NodoActual == nullptr)
        {
            std::cout << "El nodo con el valor " << dato << " no se encontro en la lista.\n";
            return;
        }

        NodoAnterior->siguiente = NodoActual->siguiente;
        delete NodoActual;
    }
};

int main()
{
    Lista lista;
    lista.insertarInicio(10);
    lista.insertarFinal(20);
    lista.insertarEnMedio(15, 2);

    lista.mostrar();
    lista.eliminarNodo(20); // Eliminar el nodo con valor 2

    std::cout << "\nLista después de eliminar el nodo:\n";
    lista.mostrar();
}

