#include "../../include/includes.hpp"
#include "../DNI/DNI.hpp"

template <class Clave>
class NodoBB {

public:
  NodoBB(Clave, NodoBB<Clave>* =NULL, NodoBB<Clave>* =NULL);

  Clave data;
  NodoBB<Clave>* izq;
  NodoBB<Clave>* dcha;

  // bool insertar(Clave X);
  // bool buscar(Clave X);
  // bool eliminar(Clave X);
};
