#include <iostream>
#include <thread>
#include <time.h>
#include <random>
#include <chrono>
#define fin 50
using namespace std;
int sum = 0;
thread Hcaballos[10];

struct caballo{
  int idcab;
  int dist;
  caballo() : dist(0){};
};

void carrera (caballo c){

  while (true){

    if (c.dist >= fin){
      cout << "El caballo " << c.idcab << " llego a la meta" << endl;
      return;
    }

    c.dist = c.dist+(rand()% 50 + 1);
    int seg = rand()%3+1;

    cout << "El caballo " << c.idcab << " recorrio " << c.dist << " metros" << endl;
    
    cout << "El caballo " << c.idcab << " descanza " << seg << " segundos" << endl;

    std::this_thread::sleep_for(seg*1000ms);
    c.dist = c.dist + sum;
    

  }
  
}


int main() {
  srand (time(NULL));
  int numcaballos;
  cout << "Ingrese cantidad de caballos: ";
  cin >> numcaballos;
  caballo c1;
  for (int i=0; i<numcaballos; i++){
    c1.idcab = i+1;
    Hcaballos[i] = thread (carrera, c1);
  }
  for (int i=0; i<numcaballos; i++){
    Hcaballos[i].join();
  }
}
