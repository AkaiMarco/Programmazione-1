#include <iostream>
using namespace std;

struct nodo {
  //possiamo variare il tipo di 'val' per cambiare la struttura. 
  int val;
  nodo *next;
};
//typedef nodo* lista

nodo* pila;

bool vuota(){
  return(pila==NULL);
}

void init(){
  pila = NULL;
}

bool top(int &n){
  //ritorna val bool, sostituisce all'argomento il valore del elemento superiore
  
  bool risultatoOperazione;
  if(vuota()){
    risultatoOperazione = false;
  }
  else{
    n=pila->val;
    risultatoOperazione = true;
  }
  return risultatoOperazione;
}

bool push(int n){
  //ritorna se l'operazione è avvenuta, aggiunge un nodo.
  bool ris_op;
  nodo* nuovoNodo = new nodo;
  if(nuovoNodo == NULL){
    ris_op = false;
  }
  else{
    nuovoNodo->val = n;
    nuovoNodo->next = pila;
    pila = nuovoNodo;
    ris_op = true;
  }
  return ris_op;
}

bool pop(){
  bool ris_op;
  if(vuota()){
    ris_op = false;
  }
  else {
    nodo* primoNodo = pila;
    pila = pila->next;
    delete primoNodo;
    ris_op = true;
  }
  return ris_op;
}


void deinit(){
  int tmp;
  while(top(tmp)){
    pop();
  }
}
