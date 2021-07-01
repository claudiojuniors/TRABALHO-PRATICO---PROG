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

 