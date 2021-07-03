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
    
	int opcao, Real, imag;

	ofstream Gravar;
	ifstream Ler;

	tLista *Complexos = new tLista;

	inicializaLista(Complexos);
    

	cout << "Digite 1 se quiser gravar o arquivo, digite 2 para ler o arquivo"
		 << endl;
	cin >> opcao << endl;

	if (opcao == 1) {
		Gravar.open("Complexos.txt", ios::out);

		while (opcao == 1) {
			cout << "Digite a parte REAL do número complexo" << endl;
			cin >> Real << endl;

			cout << "Digite a parte IMAGINARIA do numero complexo" << endl;
			cin >> imag << endl;

			incluirNoFim(Real, imag);

			cout << "Deseja continuar digitando? (se SIM aperte 1, se "
					"NÃO,aperte 2)"
				 << endl;
			cin >> opcao << endl;
		}
	}
	Gravar.close();

	if (opcao==2){
		Ler.open("Complexos.txt", ios::in);
	 
	}
	Ler.close();
}



/*#include <fstream>
#include <iostream>
using namespace std;

/*struct tComplexos{
	  float *real;
	  float *imag;
	};

struct tComplexos {
	int info;
	tComplexos *proximo;
};

tComplexos *criaComplex(int item) {
	tComplexos *Complex = new tComplexos;

	Complex->info = item;
	Complex->proximo = NULL;

	return Complex;
}

struct tLista {
  tComplexos *primeiro;
	tComplexos *ultimo;
	tComplexos *marcador;
	int tamanho;
};

void inicializaLista(tLista *pLista) {
	pLista->primeiro = NULL;
	pLista->ultimo = NULL;
	pLista->marcador = NULL;
	pLista->tamanho = 0;
}

bool obterTamanho(tLista *pLista) {
	return pLista->tamanho;
}
bool listaVazia(tLista *pLista) {
	return (pLista->tamanho == 0);
}

bool finalLista(tLista *pLista) {
	return (pLista->marcador == NULL);
}

void incluirNoFim(tLista *pLista, int info) {
	tComplexos *Complex;
	Complex = criaComplex(info);

	if (listaVazia(pLista)) {
		pLista->primeiro = Complex;
	} else {
		pLista->ultimo->proximo = Complex;
	}

	pLista->ultimo = Complex;
	pLista->marcador = Complex;
	pLista->tamanho++;
}

void imprimirLista(tLista* pLista){
  pLista->marcador = pLista->primeiro;

  while(!finalLista(pLista)){
    int informacao = pLista->marcador->info;
    cout << "A informacao eh: " << informacao << endl;
    
    pLista->marcador = pLista->marcador->proximo;
  }
}
int main() {
	int opt, Real, imag;

	ofstream Gravar;
	ifstream Ler;

	tLista *Complexos = new tLista;

	inicializaLista(Complexos);

	cout << "Digite 1 se quiser gravar o arquivo, digite 2 para ler o arquivo"
		 << endl;
	cin >> opt << endl;

	if (opt == 1) {
		Gravar.open("Complexos.txt", ios::out);

		while (opt == 1) {
			cout << "Digite a parte REAL do número complexo" << endl;
			cin >> Real << endl;

			cout << "Digite a parte IMAGINARIA do numero complexo" << endl;
			cin >> imag << endl;

			incluirNoFim(Real, imag);

			cout << "Deseja continuar digitando? (se SIM aperte 1, se "
					"NÃO,aperte 2)"
				 << endl;
			cin >> opt << endl;
		}
	}
	Gravar.close();

	if (opt==2){
		Ler.open("Complexos.txt", ios::in);
	 imprimirLista();
	}
	Ler.close();
}*/
