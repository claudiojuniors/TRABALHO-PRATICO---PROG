#include <iostream>
#include<fstream>

using namespace std;

struct tComplexos{
  int info;
  tComplexos* proximo;
}; 

tComplexos* criaNo(int item){
  tComplexos* no = new tComplexos;

  no -> info = item;
  no -> proximo = NULL;

  return no;
}

struct tLista{
  tComplexos* primeiro;
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

int obterTamanho(tLista* pLista){
  return pLista->tamanho;
}
bool listaVazia(tLista* pLista){
  return (pLista -> tamanho == 0);
}

bool finalLista(tLista* pLista){
  return (pLista->marcador == NULL);
}

void incluirNoFim(tLista* pLista, int info){
  tComplexos* no;
  no = criaNo(info);

  if(listaVazia(pLista)){
    pLista -> primeiro = no;
  }
  else{
        pLista -> ultimo -> proximo = no;
  }

  pLista -> ultimo = no;
  pLista -> marcador = no;
  pLista -> tamanho ++;
}

void imprimirLista(tLista* pLista){
  pLista->marcador = pLista->primeiro;

  while(!finalLista(pLista)){
    int informacao = pLista->marcador->info;
    cout << "A informacao eh: " << informacao << endl;
        pLista->marcador = pLista->marcador->proximo;
  }
}

int main (){
    
	int opcao,numeros, Real, imag;
  char ComplexInt;
	ofstream Gravar;
	ifstream Ler;

	tLista *Complexos = new tLista;

	inicializaLista(Complexos);
    

	cout << "Digite 1 se quiser gravar o arquivo, digite 2 para ler o arquivo"
		 << endl;
	cin >> opcao;

	if (opcao == 1) {
	  
	  cout<<"Quantos números quer gravar?: "<<endl;
	  cin>>numeros;
	  
		Gravar.open("Complexos.txt", ios::out);

		for (int i=0; i<numeros;i++) {
			cout << "Digite a parte REAL do número complexo" << endl;
			cin >> Real;

			cout << "Digite a parte IMAGINARIA do numero complexo" << endl;
			cin >>imag;

       //ComplexInt=Real&&imag;
       
			incluirNoFim(Complexos,Real);
			
		}
					
			Gravar<<Real<<"+"<<imag<<"i"<<endl;
	}
	Gravar.close();

	if (opcao==2){
		Ler.open("Complexos.txt", ios::in);
	 
	}
	Ler.close();
}

