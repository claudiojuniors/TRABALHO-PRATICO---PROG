#include<iostream>
#include<fstream>
using namespace std;


/*struct tComplexos{
      float *real;
      float *imag;
    };*/

struct tComplexos{
  int info;
  tComplexos* proximo;
}; 

tComplexos* criaComplex(int item){
  tComplexos* Complex = new tComplexos;

  Complex -> info = item;
  Complex -> proximo = NULL;

  return Complex;
}
 tComplexos* primeiro;
struct tLista{
  tComplexos* ultimo;
  tComplexos* marcador;
  int tamanho;
};

void inicializaLista(tLista* pLista){
  pLista -> primeiro = NULL;
  pLista -> ultimo = NULL;
  pLista -> marcador = NULL;
  pLista -> tamanho = 0;
}

int
