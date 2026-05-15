#include <iostream>
using namespace std;

struct Nodo
{
  int dato;
  Nodo *siguiente;
};

void agregarNodo(Nodo *&cabeza, Nodo *&cola, int valor)
{
  Nodo *nuevoNodo = new Nodo();
  nuevoNodo->dato = valor;
  nuevoNodo->siguiente = nullptr;

  if (cabeza == nullptr)
  {
    cabeza = nuevoNodo;
    cola = nuevoNodo;
  }
  else
  {
    cola->siguiente = nuevoNodo;
    cola = nuevoNodo;
  }
}

void mostrarLista(Nodo *cabeza)
{
  if (cabeza == nullptr)
  {
    cout << "\n  (La lista está vacía)\n";
    return;
  }

  cout << "\nContenido de la lista:\n  ";

  Nodo *actual = cabeza;
  while (actual != nullptr)
  {
    if (actual->siguiente != nullptr)
    {
      cout << "[" << actual->dato << " | *] --> ";
    }
    else
    {
      cout << "[" << actual->dato << " | NULL]";
    }
    actual = actual->siguiente;
  }
  cout << "\n";
}

void liberarMemoria(Nodo *&cabeza)
{
  Nodo *actual = cabeza;
  while (actual != nullptr)
  {
    Nodo *temp = actual->siguiente;
    delete actual;
    actual = temp;
  }
  cabeza = nullptr;
  cout << "\nMemoria liberada correctamente.\n";
}

int main()
{
  Nodo *cabeza = nullptr; // puntero al primer nodo
  Nodo *cola = nullptr;   // puntero al último nodo

  cout << "+====================================+\n";
  cout << "|   Lista Enlazada Dinámica en C++   |\n";
  cout << "+====================================+\n";

  char opcion;

  do
  {
    cout << "\n¿Desea ingresar un nuevo valor? (S/N): ";
    cin >> opcion;
    opcion = toupper(opcion);

    if (opcion == 'S')
    {
      int valor;
      cout << "Ingrese el valor entero: ";
      cin >> valor;
      agregarNodo(cabeza, cola, valor);
      cout << "  Nodo agregado correctamente.\n";
    }
    else if (opcion != 'N')
    {
      cout << "  Opción inválida. Ingrese S o N.\n";
    }

  } while (opcion != 'N');

  mostrarLista(cabeza);

  liberarMemoria(cabeza);

  cout << "\n--- Programa finalizado ---\n";
  return 0;
}
