#include "NodoBB.hpp"

template <class Clave>
NodoBB<Clave>::NodoBB(Clave X, NodoBB* iz, NodoBB* dc): data(X), izq(iz), dcha(dc) {
  // std::cout << "Constructor de NodoBB" << '\n';
}

template <class Clave>
void NodoBB<Clave>::addColision() {
  colisiones.addOne();
}

template <class Clave>
int NodoBB<Clave>::getColisiones() const {
  return colisiones.getData();
}

template <class Clave>
void NodoBB<Clave>::removeColision() {
  colisiones.subOne();
}

template class NodoBB<int>;
template class NodoBB<DNI>;
