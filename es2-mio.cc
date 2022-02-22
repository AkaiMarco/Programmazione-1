#include <iostream>


/* Inserire qui sotto la dichiarazione della funzione extract */
char* extract(const char* source);
char* aux(const char* source, int i, int n);
/* Inserire qui sopra la dichiarazione della funzione extract */

/* Solo di esempio, non fate assunzioni su questo valore */
const int DIM = 255;

int main(int argc, char ** argv) {
  char input_string[DIM+1];
  char * extracted;
  char answer;

  do {
    std::cout << "Inserire la stringa da controllare: ";
    std::cin >> input_string;

    extracted = extract(input_string);
    std::cout << "La stringa estratta e': " << extracted << std::endl;

    delete [] extracted;
    std::cout << "Si vuole inserire un'altra stringa? [*/n]";
    std::cin >> answer;
  } while (answer != '\0' && answer != 'N' && answer != 'n');
  return 0;
}

/* Inserire qui sotto la definizione della funzione estract */
char* extract(const char* source){
  return aux(source, 0, 0);
}

char* aux(const char* source, int i, int n){
  char * chiocciole;
  if(source[i] == '\0'){
    chiocciole = new char[n+1];
    chiocciole[n] = '\0';
  }
  else if(source[i] == '@'){
    chiocciole = aux(source, i+1, n+1);
    chiocciole[n] = '@';
  }
  else if(source[i] != '@'){
    chiocciole = aux(source, i+1, n);
  }
  return chiocciole;
}
  
/* Inserire qui sopra la definizione della funzione estract */
