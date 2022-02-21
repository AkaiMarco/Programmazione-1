#include <iostream>
using namespace std;



//potenza iterativa intera

int pow(int base, int esponente){
  int potenza = 1;
  if(esponente >= 0){
    for(int i=0; i<esponente; i++){
      potenza *= base;
    }
  }
  else{
    cout <<"la funzione prende solo valori positivi."<< endl;
    exit(0);
  }
  return potenza;
}



//potenza iterativa decimale

long double pow(double base, int esponente){
  long double potenza = 1.0;
  if(esponente >= 0){
    for(int i=0; i<esponente; i++){
      potenza *= base;
    }
  }
  else{
    for(int i=0; i<(-esponente); i++){
      potenza *= base;
    }
    potenza = 1/potenza;
  }
  return potenza;
}



//potenza ricorsiva decimale

long double pow(double base, int esponente){
  long double potenza;
  if(esponente == 0){
    potenza = 1.0;
  }
  else if(esponente > 0){
    potenza = base * pow(base, esponente-1);
  }
  else if(esponente < 0){
    potenza = 1/(base * pow(base, (-esponente)-1));
  }
  return potenza;
}



//potenza ricorsiva intera

int pow(int base, int esponente){
  int potenza;
  if(esponente > 0){
    potenza = base * pow(base, esponente-1);
  }
  else if(esponente == 0){
    potenza = 1;
  }
  else{
     cout <<"la funzione prende solo valori positivi."<< endl;
     exit(0);
  }
  return potenza;
}




//valore assoluto intero

int val_assoluto(int x){
  int val;
  if(x >= 0){
    val = x;
  }
  else{
    val = -x;
  }
  return val;
}



// valore assoluto decimale

double val_assoluto(double x){
  double val;
  if(x<0){
    val = -x;
  }
  else{
    val = x;
  }
  return val;
}


//-------------------------------------------------------------------


//strlen

int strlen(char* array){
  int len = 0;
  for(int i=0; array[i] != '\0'; i++){
    len += 1;
  }
  return len;
}



//strcpy

void strcpy(char* a, char* b){
  int p;
  for(int i=0; a[i] != '\0'; i++){
    b[i] = a[i];
    p = i+1;
  }
  b[p] = '\0';
}



//-----------------------------------------------------------
//FINE FUNZIONI
//-----------------------------------------------------------

int main(){
  return 0;
}
