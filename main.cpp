//
//  main.cpp
//  ActividadIntegradora4v2
//
//

#include "utlierias.hpp"

int main(int argc, const char * argv[]) {

  Graph<string> grafo = cargaBitacora4("/Users/soteroosuna/Desktop/botnetwork/botnetwork/bitacoraACT4_3_B.txt");

  //grafo.showNodes();

  cout << "IP addresses with the most fan-outs: " << endl;

  grafo.maxFanOut();
    
  return 0;
}

/*
¿Qué nodos tienen el mayor fan-out?

Los nodos con ip:

77.89.221.25
185.109.34.183

¿En qué dirección ip presumiblemente se encuentra el botmaster?

Se puede asumir que el botmaster se encuentra en la dirección ip con mayor fan-outs, ya que sería la que tendría más intentos de conectarse a otros dispositivos.

*/
