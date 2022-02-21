#include <iostream>
using namespace std;

struct nodo{
  char* nome;
  nodo* next;
};
//typedef nodo* lista;

struct coda{
  nodo* tail;
  nodo* head;
};

coda Q;


bool vuota(){
  return(Q.head==NULL);
}


void init(){
  Q.head ==NULL;
}


bool enqueue(char* n){
  bool ris_op;
  nodo* nuovoNodo = new nodo;
  if(nuovoNodo == NULL){
    ris_op = NULL;
  }
  else{
    nuovoNodo->nome = n;
    nuovoNodo->next = NULL;
    if(vuota()){
      Q.head = nuovoNodo;
    }
    else{
      Q.tail->next = nuovoNodo;
    }
    Q.tail = nuovoNodo;
    ris_op = true;
  }
  return ris_op;
}


bool dequeue(){
  bool ris_op;
  if(vuota()){
    ris_op = false;
  }
  else{
    nodo* primoNodo;
    primoNodo = Q.head;
    Q.head = Q.head->next;
    delete primoNodo;
    ris_op = true;
  }
  return ris_op;
}


bool first(char * &n){
  bool ris_op;
  if(vuota()){
    ris_op = false;
  }
  else{
    n = Q.head->nome;
    ris_op = true;
  }
  return ris_op;
}


void deinit(){
  char* tmp;
  while(first(tmp)){
      dequeue();
    }
}


void print(){
  if(!vuota()){
    nodo* nodoCorrente = Q.head;
    do{
      cout << nodoCorrente->nome << endl;
      nodoCorrente = nodoCorrente->next;
    } while (nodoCorrente != NULL);
  }
}
