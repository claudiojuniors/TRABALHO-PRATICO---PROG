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

 obterTamanho(tLista* pLista){
  return pLista->tamanho;
}
bool listaVazia(tLista* pLista){
  return (pLista -> tamanho == 0);
}

bool finalLista(tLista* pLista){
  return (pLista->marcador == NULL);
}

void incluirNoFim(tLista* pLista, int info){
  tComplexos* Complex;
  Complex = criaComplex(info);

  if(listaVazia(pLista)){
    pLista -> primeiro = Complex;
  }
else{
    pLista -> ultimo -> proximo = Complex;
  }

  pLista -> ultimo = Complex;
  pLista -> marcador = Complex;
  pLista -> tamanho ++;
}

int main() {
  
  int opt=1, Real, imag;
  
ofstream Gravar;
ifstream Ler;

tLista* Complexos = new tLista;

inicializaLista(Complexos)

if (opt==1){

while (opt==1){
  
  cout<<"Digite a parte REAL do número complexo"<<endl;
  cin>> Real<<endl;
  
  
  cout<<"Digite a parte IMAGINARIA do numero complexo"<<endl;
  cin>> imag<<endl;
  
  incluirNoFim(Real, imag);
  
  cout<<"Deseja continuar digitando? (se SIM aperte 1, se NÃO,aperte 2)"<<endl;
  cin>>opt<<endl;
    }
  }else {
   Gravar.open("Complexos.txt",ios::out);
   
 
    } 
  }
}