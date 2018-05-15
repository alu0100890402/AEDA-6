#include "AVL.hpp"

template <class Clave>
AVL<Clave>::AVL(NodoAVL<Clave>* raiz_): ABB<Clave>(raiz_) {
  std::cout << "Constructor de AVL" << '\n';
}

template <class Clave>
void AVL<Clave>::rotacion_II(NodoAVL<Clave>* &nodo) {
  std::cout << "Funcion rotacion II" << '\n';
}

template <class Clave>
void AVL<Clave>::rotacion_DD(NodoAVL<Clave>* &nodo) {
  std::cout << "Funcion rotacion_DD" << '\n';
}

template <class Clave>
void AVL<Clave>::rotacion_ID(NodoAVL<Clave>* &nodo) {
  std::cout << "Funcion rotacion_ID" << '\n';
}

template <class Clave>
void AVL<Clave>::rotacion_DI(NodoAVL<Clave>* &nodo) {
  std::cout << "Funcion rotacion_DI" << '\n';
}

template <class Clave>
void AVL<Clave>::insertar(Clave) {
  std::cout << "Funcion insertar" << '\n';
}

template <class Clave>
void AVL<Clave>::inserta_bal(NodoAVL<Clave>* &nodo) {
  std::cout << "Funcion inserta_bal" << '\n';
}

template <class Clave>
void AVL<Clave>::inserta_re_bal_izq(NodoAVL<Clave>* &nodo) {
  std::cout << "Funcion inserta_re_bal_izq" << '\n';
}

template <class Clave>
void AVL<Clave>::inserta_re_bal_dcha(NodoAVL<Clave>* &nodo) {
  std::cout << "Funcion inserta_re_bal_dcha" << '\n';
}

template <class Clave>
bool AVL<Clave>::eliminar(Clave x) {
  std::cout << "Funcion eliminar (AVL)" << '\n';
}

template <class Clave>
bool AVL<Clave>::elimina_rama(NodoAVL<Clave>* &nodo, Clave x, bool& decrece) {
  std::cout << "Funcion eliminar_rama" << '\n';
}

template <class Clave>
void AVL<Clave>::sustituye(NodoAVL<Clave>* &eliminado, NodoAVL<Clave>* &sust, bool& decrece) {
  std::cout << "Funcion sustituye" << '\n';
}

template <class Clave>
void AVL<Clave>::eliminar_re_bal_izq(NodoAVL<Clave>* &nodo, bool& decrece) {
  std::cout << "Funcion eliminar_re_bal_izq" << '\n';
}

template <class Clave>
void AVL<Clave>::eliminar_re_bal_dcha(NodoAVL<Clave>* &nodo, bool& decrece) {
  std::cout << "Funcion eliminar_re_bal_dcha" << '\n';
}
