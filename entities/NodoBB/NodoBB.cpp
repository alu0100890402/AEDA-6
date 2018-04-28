#include "NodoBB.hpp"

template <class Clave>
NodoBB<Clave>::NodoBB(Clave X, NodoBB* iz, NodoBB* dc): data(X), izq(iz), dcha(dc) {
  // std::cout << "Constructor de NodoBB" << '\n';
}

// template <class Clave>
// bool NodoBB<Clave>::insertar(Clave X) {
//   if(X > data) {
//     if(dcha == nullptr) {
//       dcha = new NodoBB(X);
//     } else {
//       dcha->insertar(X);
//     }
//   } else {
//     if(izq == nullptr) {
//       izq = new NodoBB(X);
//     } else {
//       izq->insertar(X);
//     }
//   }
// }
//
// template <class Clave>
// bool NodoBB<Clave>::buscar(Clave X) {
//   std::cout << "Funcion buscar" << '\n';
// }
//
// template <class Clave>
// bool NodoBB<Clave>::eliminar(Clave X) {
//   std::cout << "Funcion eliminar" << '\n';
// }

template class NodoBB<int>;
template class NodoBB<DNI>;
