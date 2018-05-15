#include "NodoAVL.hpp"

template <class Clave>
NodoAVL<Clave>::NodoAVL(Clave x, NodoAVL<Clave>*iz, NodoAVL<Clave>*de): NodoBB<Clave>(x, iz, de), bal(0), izq(iz), dcha(de) {
  std::cout << "Constructor de la clase NodoAVL" << '\n';
}

template class NodoAVL<int>;
template class NodoAVL<DNI>;
