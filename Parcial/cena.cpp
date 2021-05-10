#include <iostream>
#include <thread>
#include <time.h>
using namespace std;

int totalcomida=50,aux;
int estado[10];

struct tenedor{
  int libre;
};

struct filosofo {
  int name=1, energia, cantplato, t1, t2;
  struct tenedor ten1;
  struct tenedor ten2;
  filosofo() : t1(name), t2((name+1)%aux), cantplato(6), energia(40){}
};

void mesa (filosofo &fil) {
  while (true){
    if (totalcomida < 0){
      cout << fil.name << "° filosofo TERMINO." << endl;
      break;
    }

    else{
      estado[fil.name] = 2;
      int pensar = rand()%3+1;
      cout << fil.name << "° filosofo esta pensando" << endl;
      fil.energia -= pensar; 
      std::this_thread::sleep_for(pensar*1000ms);

      if(fil.energia < 0){
        cout << fil.name <<"° filosofo MURIO de hambre." << endl;
        break;
      }

      if (estado[fil.name]==2 && estado[fil.t1]!=3 && estado[fil.t2]!=3 && fil.cantplato >0){
        estado[fil.name] = 3;
        fil.ten1.libre = 1; fil.ten2.libre = 1;
        cout << fil.name << "° filosofo agarro dos tenedores" << endl;

        while (fil.cantplato > 0){
          estado[fil.name] = 3;
          int comer = rand()%6+1;
          cout << fil.name <<"° filosofo esta comiendo" << endl;
          fil.energia += comer;
          fil.cantplato -= comer;
          std::this_thread::sleep_for(pensar*1000ms);
          if(fil.energia > 50){
            fil.energia = 50;
          } 

        }
        fil.ten1.libre = 0; fil.ten2.libre = 0;
        fil.cantplato = 6;
        totalcomida -= fil.cantplato;
        cout<< fil.name << "° filosofo dejo de comer" << endl;
        estado[fil.name] = 2;
        int pensar = rand()%3+1;

      }

    }

  }

}

int main() {
  int numfilo;
  cout << "Ingrese cantidad de filosofos: ";
  cin >> numfilo;
  aux = numfilo;
  filosofo filos[numfilo];
  thread cantmesa[numfilo];
  for(int i=0; i<numfilo; i++){
    srand(time(NULL));
    filos[i].name=i;
    cantmesa[i] = thread(mesa, ref(filos[i]));
  }
  
  for(int i=0; i<numfilo; i++){
    cantmesa[i].join();
  }
  
}
