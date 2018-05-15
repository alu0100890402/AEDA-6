#include "ABB.hpp"

template <class Clave>
ABB<Clave>::ABB(NodoBB<Clave>* raiz_): raiz(raiz_){
  // std::cout << "Constructor ABB" << '\n';
}


template <class Clave>
ABB<Clave>::~ABB() {
  // std::cout << "Destructor ABB" << '\n';
  podar(raiz);
}

template <class Clave>
void ABB<Clave>::podar(NodoBB<Clave>* nodo) {
  // std::cout << "Funcion podar" << '\n';
  if(nodo == NULL) return;
  podar(nodo->izq);
  podar(nodo->dcha);
  delete nodo;
  nodo = NULL;
}

template <class Clave>
NodoBB<Clave>* ABB<Clave>::buscar(Clave X) {
  // std::cout << "Funcion buscar ABB" << '\n';
  return buscarRama(raiz, X);
}

template <class Clave>
NodoBB<Clave>* ABB<Clave>::buscarRama(NodoBB<Clave>* nodo, Clave X) {
  if(nodo == NULL)  return NULL;
  CURRENT++; if(X == nodo->data) return nodo;
  CURRENT++; if(X < nodo->data)  return buscarRama(nodo->izq, X);
  return buscarRama(nodo->dcha, X);
}

template <class Clave>
void ABB<Clave>::insertar(Clave X) {
  // std::cout << "Funcion insertar ABB" << '\n';
  insertarRama(raiz, X);
}

template <class Clave>
void ABB<Clave>::insertarRama(NodoBB<Clave>* &nodo, Clave X) {
    if(nodo == NULL)
        nodo = new NodoBB<Clave>(X);
    else
        if(X == nodo->data)
            nodo->addColision();
        else
            if(X < nodo->data)
                insertarRama(nodo->izq, X);
            else
                insertarRama(nodo->dcha, X);
}

template <class Clave>
bool ABB<Clave>::eliminar(Clave X) {
  // std::cout << "Funcion eliminar ABB" << '\n';
  return eliminarRama(raiz, X);
}

template <class Clave>
bool ABB<Clave>::eliminarRama(NodoBB<Clave>* &nodo, Clave X) {
  if(nodo == NULL)  return false;
  if(X < nodo->data)  return eliminarRama(nodo->izq, X);
  if(X > nodo->data)  return eliminarRama(nodo->dcha, X);
  auto eliminado = nodo;  // X == nodo->data
  if(nodo->getColisiones() > 0) {
    nodo->removeColision();
    return true;
  } else if(nodo->dcha == NULL)   nodo = nodo->izq;
  else if(nodo->izq == NULL)    nodo = nodo->dcha;
  else  sustituye(eliminado, nodo->izq);
  delete eliminado;
  return true;
}

template <class Clave>
void ABB<Clave>::sustituye(NodoBB<Clave>* &eliminado, NodoBB<Clave>* &sust) {
  if(sust->dcha != NULL) {
    sustituye(eliminado, sust->dcha);
  } else {
    eliminado->data = sust->data;
    eliminado = sust;
    sust = sust->izq;
  }
}

template <class Clave>
void ABB<Clave>::show() {

  int nivel = 0;
  std::queue<NodoBB<Clave>*> cola;
  cola.push(raiz);
  while(!cola.empty()) {
    std::cout << "Nv " << nivel++ << ": ";
    int i = cola.size();
    while(i-- > 0) {
      std::cout << "[";
      if(cola.front() != NULL) {
        std::cout << cola.front()->data;
        if(cola.front()->getColisiones() > 0)
          std::cout << "("<< (cola.front()->getColisiones()) << ")";
        cola.push(cola.front()->izq);
        cola.push(cola.front()->dcha);
      } else {
        std::cout << ".";
      }
      std::cout << "]  " ;
      cola.pop();
    }
    std::cout << '\n';
  }
}

template class ABB<int>;
template class ABB<DNI>;
