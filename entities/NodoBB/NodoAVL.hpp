#include "NodoBB.hpp"

template <class Clave>
class NodoAVL : public NodoBB<Clave> {

public:
  NodoAVL(Clave, NodoAVL<Clave>* =NULL,NodoAVL<Clave>* =NULL);

  NodoAVL<Clave>* izq;
  NodoAVL<Clave>* dcha;

  int bal;

};
