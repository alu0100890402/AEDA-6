#include "../entities/ABB/ABB.hpp"

int main() {

  // for((i=16; i<256; i++)); do
  //   printf "\e[48;5;${i}m%03d" $i;
  //   printf '\e[0m';
  //   [ ! $((($i - 15) % 6)) -eq 0 ] && printf ' ' || printf '\n'
  // done

  ABB<int> arbol;

  int modo;
  std::cout << "Bienvenido" << '\n';
  std::cout << "Seleccione el modo del programa: " << '\n'
  << "0. Demostracion" << "\n1. Estadistica\t";
  std::cin >> modo;
  std::cout << "Seleccionado modo " << (modo == 1 ? "Estadistica" : "Demostracion") << '\n';

  if(modo != 1) {
    int opcion;
    do {
      std::cout << "[0] Salir" << '\n';
      std::cout << "[1] Insertar Clave" << '\n';
      std::cout << "[2] Eliminar Clave" << "\t: ";
      std::cin >> opcion;
      if(opcion > 0) {
        int clave;  bool res;
        std::cout << "Clave: ";
        std::cin >> clave;
        if(opcion == 1) arbol.insertar(clave);
        else  {
          res = arbol.eliminar(clave);
          if(!res)  std::cout << "No se encuentra esta clave en el ABB" << '\n';
        }
      }
      arbol.show();
    } while (opcion != 0);
  } else {
    std::cout << "Funcion en desarrollo" << '\n';
  }

  // arbol.insertar(5);
  // arbol.insertar(7);
  // arbol.insertar(3);
  // arbol.insertar(2);
  // arbol.insertar(4);
  // arbol.insertar(6);
  // arbol.insertar(8);

  // std::cout << "├── Cuadratica.cpp" << '\n';
  // std::cout << "↘ ↙⤵" << '\n';
  //
  // std::cout << "Nv 0:     ╭─[6]─╮" << '\n';
  // std::cout << "Nv 1:  ╭[4]╮   ╭[8]╮" << '\n';
  // std::cout << "Nv 1: [3] [5] [7] [9]" << '\n';
  // arbol.show();

  // std::cout << "Profundidad actual del arbol: " << arbol.prof() << '\n';
//
  return 0;
}
