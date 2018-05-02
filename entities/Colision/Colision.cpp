#include "Colision.hpp"

Colision::Colision(): n(0) {
  // std::cout << "Constructor de Colision" << '\n';
}

int Colision::getData() const {
  return n;
}

void Colision::addOne() {
  n++;
}

void Colision::subOne() {
  n--;
}
