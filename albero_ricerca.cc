#include <iostream>
#include <fstream>
using namespace std;

struct nodo{
  int value;
  nodo* left;
  nodo* right;
};
typedef nodo* albero;

void inserisciNodo(albero,nodo*);


albero creaAlberoRicerca(char* file){
  albero radice = NULL;
  fstream input;

  input.open(file, ios::in);
  //TODO guardia
  int numero;
  input >> numero;
  radice = new nodo{numero, NULL, NULL};

  while(input >> numero){
    nodo* nuovoNodo = new nodo{numero, NULL, NULL};
    inserisciNodo(radice, nuovoNodo);
  }
  input.close();
}
return radice;
}

void inserisciNodo(albero radice, nodo* nuovoNodo){
  if(nuovoNodo->value > radice-> value){
    if(radice->right == NULL){
      radice->right = nuovoNodo;
    }
    else{
      inserisciNodo(radice->right, nuovoNodo);
    }
  }
  else {
    if(radice->left == NULL) {
      radice->left == nuovoNodo;
    }
    else{
      inserisciNodo(radice->left,nuovoNodo);
    }
  }
}

void stampaAlbero(albero radice, int spazio){
  if(radice != NULL) {
    spazio++;
    
    stampaAlbero(radice->right,spazio);

    for(int i=1; i<spazio; i++){
      cout<<"\t";
    }
    cout << radice->value<<"\n";

    stampaAlbero(radice->left, spazio);
  }
}
