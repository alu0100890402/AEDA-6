#include "ABB.hpp"
#include "../NodoBB/NodoAVL.hpp"

template <class Clave>
class AVL : public ABB<Clave> {

public:
  AVL(NodoAVL<Clave>* = NULL);

  void rotacion_II(NodoAVL<Clave>*&);
  void rotacion_DD(NodoAVL<Clave>*&);
  void rotacion_ID(NodoAVL<Clave>*&);
  void rotacion_DI(NodoAVL<Clave>*&);

  void insertar(Clave);
  void inserta_bal(NodoAVL<Clave>*&, NodoAVL<Clave>*&, bool&);
  void inserta_re_bal_izq(NodoAVL<Clave>*&, bool&);
  void inserta_re_bal_dcha(NodoAVL<Clave>*&, bool&);
  bool eliminar(Clave);
  bool elimina_rama(NodoAVL<Clave>*&, Clave, bool&);
  void sustituye(NodoAVL<Clave>*&, NodoAVL<Clave>*&, bool&);
  void eliminar_re_bal_izq(NodoAVL<Clave>*&, bool&);
  void eliminar_re_bal_dcha(NodoAVL<Clave>*&, bool&);


};
