#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int cambia_base(char[]);
int calcola(int,int,char);

int main(int argc, char* argv[]){
  fstream input, output;
  
  if(argc != 3){
    cerr<< "Usage: ./a.out <input> <output> " << endl;
    exit(0);
  }
  
  input.open(argv[1], ios::in);
  if(input.fail()){
    exit(0);
  }
  
  output.open(argv[2], ios::out);
  if(output.fail()){
    input.close();
    exit(1);
  }

  char a[11],b[11],op;
  
  while(input >> a >> op >> b){
    int numero1=0,numero2=0;
    
    numero1 = cambia_base(a);
    numero2 = cambia_base(b);

    output << calcola(numero1, numero2, op) << endl;
  }
  
  input.close();
  output.close();
  
  return 0;
}



int cambia_base(char numero[]){
  int numero_dec = 0;
  int posizione = 1;
  for(int i = strlen(numero)-1 ; i >= 0 ; i--){
    if(numero[i] >= 'A' && numero[i] <= 'G'){
      numero_dec += ((numero[i] - 'A') + 10) * posizione;
    }
    else{
      numero_dec += (numero[i]-'0') * posizione;
    }
    posizione *= 17;
  }
  return numero_dec;
}

int calcola(int a, int b, char op){
  int risultato=0;
  switch (op) {
  case '-':
    risultato = a - b;
    break;
  case '/':
    risultato = a / b;
    break;
  case '%':
    risultato = a % b;
    break;
  default:
    cerr << "Operazione non riuscita!"<< endl;
  }
  return risultato;
}
  
