#pragma once
#include "../../include/includes.hpp"
#include "../DNI/DNI.hpp"
#include "../Colision/Colision.hpp"

template <class Clave>
class NodoBB {

  Colision colisiones;

public:
  NodoBB(Clave, NodoBB<Clave>* =NULL, NodoBB<Clave>* =NULL);

  Clave data;
  NodoBB<Clave>* izq;
  NodoBB<Clave>* dcha;

  void addColision();
  void removeColision();
  int getColisiones() const;


  // bool insertar(Clave X);
  // bool buscar(Clave X);
  // bool eliminar(Clave X);
};
