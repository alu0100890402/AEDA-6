#include "../NodoBB/NodoBB.hpp"

template <class Clave>
class ABB {
  NodoBB<Clave>* raiz;
public:
  ABB();
  ~ABB();

  void podar(NodoBB<Clave>*);

  NodoBB<Clave>* buscar(Clave X);
  NodoBB<Clave>* buscarRama(NodoBB<Clave>*, Clave);
  void insertar(Clave X);
  void insertarRama(NodoBB<Clave>*&, Clave);
  bool eliminar(Clave X);
  bool eliminarRama(NodoBB<Clave>*&, Clave);
  void sustituye(NodoBB<Clave>*&, NodoBB<Clave>*&);


};
