#include "../entities/ABB/ABB.hpp"

int MAX=0, MIN=1000, CURRENT=0;

ABB<DNI> *arbol;

float* testData(std::vector<DNI>&, int, int, int);

int main() {

  // for((i=16; i<256; i++)); do
  //   printf "\e[48;5;${i}m%03d" $i;
  //   printf '\e[0m';
  //   [ ! $((($i - 15) % 6)) -eq 0 ] && printf ' ' || printf '\n'
  // done

  arbol = new ABB<DNI>;

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
        std::string input;  bool res;
        std::cout << "DNI: ";
        std::cin >> input;
        DNI clave(false, input);
        if(opcion == 1) arbol->insertar(clave);
        else  {
          res = arbol->eliminar(clave);
          if(!res)  std::cout << "No se encuentra esta clave en el ABB" << '\n';
        }
      }
      arbol->show();
    } while (opcion != 0);
  } else {
    int N, nPruebas;
    std::cout << "Selecciona el tamaño del arbol: ";
    std::cin >> N;
    std::cout << "Selecciona el numero de pruebas: ";
    std::cin >> nPruebas;
    std::vector<DNI> bancoPruebas;

    for (size_t i=0; i<N*2; i++) {
      bancoPruebas.push_back( DNI(true) );
    }
    for (size_t i=0; i<N; i++) {
      arbol->insertar(bancoPruebas[i]);
    }

    float* resBusqu = testData(bancoPruebas, nPruebas, 0, bancoPruebas.size()/2);
    float* resInser = testData(bancoPruebas, nPruebas, bancoPruebas.size()/2, bancoPruebas.size());

    // Salida del programa
    std::cout << "\n\tN\tPruebas\tMinimo\tMedio\tMaximo" << '\n';
    std::cout << "Busq.\t"<< N <<"\t"<< nPruebas <<"\t"<< resBusqu[0] <<"\t"<<resBusqu[1]<<"\t"<< resBusqu[2] << '\n';
    std::cout << "Inserc.\t"<< N <<"\t"<< nPruebas <<"\t"<< resInser[0] <<"\t"<<resInser[1]<<"\t"<< resInser[2]<< '\n';

  }
  // std::cout << "├── Cuadratica.cpp" << '\n';
  // std::cout << "↘ ↙⤵" << '\n';
  //
  // std::cout << "Nv 0:     ╭─[6]─╮" << '\n';
  // std::cout << "Nv 1:  ╭[4]╮   ╭[8]╮" << '\n';
  // std::cout << "Nv 1: [3] [5] [7] [9]" << '\n';

  return 0;
}


float* testData(std::vector<DNI>& banco, int nPruebas, int idxmin, int idxmax) {
  MAX=0, MIN=1000, CURRENT=0;
  // Pruebas
  int idxtotal = idxmax - idxmin;
  int acumulado=CURRENT, cont=nPruebas, i=0;
  while(cont-- > 0) {
    int indice = (i++)%(idxtotal)+idxmin;
    auto res = arbol->buscar(banco[indice]);
    if(CURRENT < MIN){ MIN = CURRENT; std::cout << "El minimo ahora es: " << MIN << '\n';}
    if(CURRENT > MAX){ MAX = CURRENT; std::cout << "El maximo ahora es: " << MAX << '\n';}
    acumulado += CURRENT;
    CURRENT = 0;
  }
  float *resultados = new float[3];
  resultados[0] = MIN;
  resultados[1] = (float)acumulado/nPruebas;
  resultados[2] = MAX;
  return resultados;
}
