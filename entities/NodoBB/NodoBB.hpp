#include "../../include/includes.hpp"

template <class Clave>
class NodoBB {
  Clave data;
  NodoBB* izq;
  NodoBB* dcha;
public:
  NodoBB(Clave X);

  bool insertar(Clave X);
  bool buscar(Clave X);
  bool eliminar(Clave X);
};
