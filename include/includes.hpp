#pragma once
#include <iostream>
#include <queue>
#include <cmath>

extern int MAX, MIN, CURRENT;

// int p = prof();
// int nivel = 0;
// std::queue<NodoBB<Clave>*> cola;
// cola.push(raiz);
// while(!cola.empty()) {
//   std::cout << "Nv " << nivel << ": ";
//   int offset = pow(2, (p-nivel));
//   int offsetAnterior = pow(2, (p-(nivel-1)));
//   int offsetSiguiente = pow(2, (p-(nivel+1)));
//   int i = cola.size();
//   while(i-- > 0) {
//     for(int x=1; x<offsetSiguiente; x++)
//       std::cout << "   ";
//     if(cola.front() != NULL) std::cout << " ╭─";
//     for(int x=1; x<offsetSiguiente; x++)
//       std::cout << "───";
//     // if(cola.front() != NULL && i!=cola.size()-1) {
//     //   std::cout << " ╭─";
//     //   for(int x=1; x<offsetSiguiente; x++)
//     //     std::cout << "───";
//     // }
//     if(cola.front() == NULL && nivel != p) {
//       std::cout << "   ";
//       for(int x=1; x<offsetSiguiente; x++)
//         std::cout << "   ";
//     }
//     std::cout << "[";
//     if(cola.front() != NULL) {
//       std::cout << cola.front()->data;
//       cola.push(cola.front()->izq);
//       cola.push(cola.front()->dcha);
//     } else {
//       std::cout << ".";
//     }
//     std::cout << "]" ;
//     if(cola.front() != NULL) {
//       for(int y=1; y<offsetSiguiente; y++) {
//         std::cout << "───";
//       }
//       std::cout << "─╮ ";
//     }
//     if(cola.front() == NULL && nivel != p) {
//       std::cout << "   ";
//       for(int x=1; x<offsetSiguiente; x++)
//         std::cout << "   ";
//     }
//     for(int z=1; z<(offsetAnterior-offset); z++) {
//       std::cout << "   ";
//     }
//
//     if(offset == 1) {
//       std::cout << "   ";
//     }
//     cola.pop();
//   }
//   nivel++;
//   std::cout << '\n';
// }
