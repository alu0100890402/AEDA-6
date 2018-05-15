#include "../NodoBB/NodoBB.hpp"

template <class Clave>
class ABB {
  NodoBB<Clave>* raiz;
public:
  ABB(NodoBB<Clave>* = NULL);
  ~ABB();

  void podar(NodoBB<Clave>*);

  NodoBB<Clave>* buscar(Clave X);
  NodoBB<Clave>* buscarRama(NodoBB<Clave>*, Clave);
  virtual void insertar(Clave X);
  void insertarRama(NodoBB<Clave>*&, Clave);
  virtual bool eliminar(Clave X);
  bool eliminarRama(NodoBB<Clave>*&, Clave);
  void sustituye(NodoBB<Clave>*&, NodoBB<Clave>*&);

  virtual void show();
};
