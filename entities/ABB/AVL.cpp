#include "AVL.hpp"

template <class Clave>
AVL<Clave>::AVL(NodoAVL<Clave>* raiz_): ABB<Clave>(raiz_), raiz(raiz_) {
  // std::cout << "Constructor de AVL" << '\n';
}

template <class Clave>
NodoAVL<Clave>* AVL<Clave>::buscar(Clave X) {
  // std::cout << "Funcion buscar AVL" << '\n';
  return buscarRama(raiz, X);
}

template <class Clave>
NodoAVL<Clave>* AVL<Clave>::buscarRama(NodoAVL<Clave>* nodo, Clave X) {
  // std::cout << "Funcion buscar Rama AVL" << '\n';
  if(nodo == NULL)  return NULL;
  CURRENT++; if(X == nodo->data) return nodo;
  CURRENT++; if(X < nodo->data)  return buscarRama(nodo->izq, X);
  return buscarRama(nodo->dcha, X);
}

template <class Clave>
void AVL<Clave>::rotacion_II(NodoAVL<Clave>* &nodo) {
  // std::cout << "Funcion rotacion II" << '\n';
  auto nodo1 = nodo->izq;
  nodo->izq = nodo1->dcha;
  nodo1->dcha = nodo;
  if(nodo1->bal == 1) {
    nodo->bal = 0;
    nodo1->bal = 0;
  } else {
    nodo->bal = 1;
    nodo1->bal = -1;
  }
  nodo = nodo1;
}

template <class Clave>
void AVL<Clave>::rotacion_DD(NodoAVL<Clave>* &nodo) {
  // std::cout << "Funcion rotacion_DD" << '\n';
  auto nodo1 = nodo->dcha;
  nodo->dcha = nodo1->izq;
  nodo1->izq = nodo;
  if(nodo1->bal == -1) {
    nodo->bal = 0;
    nodo1->bal = 0;
  } else {
    nodo->bal = -1;
    nodo1->bal = 1;
  }
  nodo = nodo1;
}

template <class Clave>
void AVL<Clave>::rotacion_ID(NodoAVL<Clave>* &nodo) {
  // std::cout << "Funcion rotacion_ID" << '\n';
  auto nodo1 = nodo->izq;
  auto nodo2 = nodo1->dcha;
  nodo->izq = nodo2->dcha;
  nodo2->dcha = nodo;
  nodo1->dcha = nodo2->izq;
  nodo2->izq = nodo1;
  if(nodo2->bal == -1) {
    nodo1->bal = 1;
  } else {
    nodo1->bal = 0;
  }
  if(nodo2->bal == 1) {
    nodo->bal = -1;
  } else {
    nodo->bal = 0;
  }
  nodo2->bal = 0;
  nodo = nodo2;
}

template <class Clave>
void AVL<Clave>::rotacion_DI(NodoAVL<Clave>* &nodo) {
  // std::cout << "Funcion rotacion_DI" << '\n';
  auto nodo1 = nodo->dcha;
  auto nodo2 = nodo1->izq;
  nodo->dcha = nodo2->izq;
  nodo2->izq = nodo;
  nodo1->izq = nodo2->dcha;
  nodo2->dcha = nodo1;
  if(nodo2->bal == 1) {
    nodo1->bal = -1;
  } else {
    nodo1->bal = 0;
  }
  if(nodo2->bal == -1) {
    nodo->bal = 1;
  } else {
    nodo->bal = 0;
  }
  nodo2->bal = 0;
  nodo = nodo2;
}

template <class Clave>
void AVL<Clave>::insertar(Clave x) {
  // std::cout << "Funcion insertar" << '\n';
  NodoAVL<Clave>* nuevo = new NodoAVL<Clave>(x);
  bool crece = false;
  inserta_bal( this->raiz, nuevo, crece );
  // this->ABB<Clave>::raiz = this->raiz;
}

template <class Clave>
void AVL<Clave>::inserta_bal(NodoAVL<Clave>* &nodo, NodoAVL<Clave>* &nuevo, bool& crece) {
  // std::cout << "Funcion inserta_bal" << '\n';
  if(nodo == NULL) {
    nodo = nuevo;
    crece = true;
  }
  else if(nodo->data == nuevo->data) {
    nodo->addColision();
  }
  else if(nuevo->data < nodo->data) {
    inserta_bal(nodo->izq, nuevo, crece);
    if(crece) {
      inserta_re_bal_izq(nodo, crece);
    }
  }
  else {
    inserta_bal(nodo->dcha, nuevo, crece);
    if(crece) {
      inserta_re_bal_dcha(nodo, crece);
    }
  }
}

template <class Clave>
void AVL<Clave>::inserta_re_bal_izq(NodoAVL<Clave>* &nodo, bool& crece) {
  // std::cout << "Funcion inserta_re_bal_izq" << '\n';
  switch (nodo->bal) {
    case -1:  nodo->bal = 0;
              crece = false;
              break;
    case 0:   nodo->bal = 1;
              break;
    case 1:   auto nodo1 = nodo->izq;
              if(nodo1->bal == 1)
                rotacion_II(nodo);
              else
                rotacion_ID(nodo);
              crece = false;
  }
}

template <class Clave>
void AVL<Clave>::inserta_re_bal_dcha(NodoAVL<Clave>* &nodo, bool& crece) {
  // std::cout << "Funcion inserta_re_bal_dcha" << '\n';
  switch (nodo->bal) {
    case 1:   nodo->bal = 0;
              crece = false;
              break;
    case 0:   nodo->bal = -1;
              break;
    case -1:  auto nodo1 = nodo->dcha;
              if(nodo1->bal == -1)
                rotacion_DD(nodo);
              else
                rotacion_DI(nodo);
              crece = false;
  }
}

template <class Clave>
bool AVL<Clave>::eliminar(Clave x) {
  // std::cout << "Funcion eliminar (AVL)" << '\n';
  bool decrece = false;
  elimina_rama( this->raiz, x, decrece );
}

template <class Clave>
bool AVL<Clave>::elimina_rama(NodoAVL<Clave>* &nodo, Clave x, bool& decrece) {
  // std::cout << "Funcion eliminar_rama" << '\n';
  if(nodo == NULL)  return false;
  if(x < nodo->data) {
    elimina_rama(nodo->izq, x, decrece);
    if(decrece) {
      eliminar_re_bal_izq(nodo, decrece);
    }
  } else if(x > nodo->data) {
    elimina_rama(nodo->dcha, x, decrece);
    if(decrece) {
      eliminar_re_bal_dcha(nodo, decrece);
    }
  } else {
    if(nodo->getColisiones() > 0) {
      nodo->removeColision();
      return true;
    }
    auto eliminado = nodo;
    if(nodo->izq == NULL) {
      nodo = nodo->dcha;
      decrece = true;
    } else if(nodo->dcha == NULL) {
      nodo = nodo->izq;
      decrece = true;
    } else {
      sustituye(eliminado, nodo->izq, decrece);
      if(decrece) {
        eliminar_re_bal_izq(nodo, decrece);
      }
    }
    delete eliminado;
    return true;
  }

}

template <class Clave>
void AVL<Clave>::sustituye(NodoAVL<Clave>* &eliminado, NodoAVL<Clave>* &sust, bool& decrece) {
  // std::cout << "Funcion sustituye" << '\n';
  if(sust->dcha != NULL) {
    sustituye(eliminado, sust->dcha, decrece);
    if(decrece) {
      eliminar_re_bal_dcha(sust, decrece);
    }
  } else {
    eliminado->data = sust->data;
    eliminado = sust;
    sust = sust->izq;
    decrece = true;
  }
}

template <class Clave>
void AVL<Clave>::eliminar_re_bal_izq(NodoAVL<Clave>* &nodo, bool& decrece) {
  // std::cout << "Funcion eliminar_re_bal_izq" << '\n';
  switch (nodo->bal) {
    case -1: {
      auto nodo1 = nodo->dcha;
      if(nodo1->bal > 0) {
        rotacion_DI(nodo);
      } else {
        if(nodo1->bal == 0) {
          decrece = false;
        }
        rotacion_DD(nodo);
      }
      break;
    }
    case 0: {
      nodo->bal = -1;
      decrece = false;
      break;
    }
    case 1:   nodo->bal = 0;
  }
}

template <class Clave>
void AVL<Clave>::eliminar_re_bal_dcha(NodoAVL<Clave>* &nodo, bool& decrece) {
  // std::cout << "Funcion eliminar_re_bal_dcha" << '\n';
  switch (nodo->bal) {
    case 1: {
      auto nodo1 = nodo->izq;
      if(nodo1->bal < 0) {
        rotacion_ID(nodo);
      } else {
        if(nodo1->bal == 0) {
          decrece = false;
        }
        rotacion_II(nodo);
      }
      break;
    }
    case 0: {
      nodo->bal = 1;
      decrece = false;
      break;
    }
    case -1:  nodo->bal = 0;
  }
}

template <class Clave>
void AVL<Clave>::show() {

  int nivel = 0;
  std::queue<NodoAVL<Clave>*> cola;
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



template class AVL<int>;
template class AVL<DNI>;
