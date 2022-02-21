#include <iostream>
#include <fstream>

using namespace std;

//dichiarazioni funzioni aggiuntive

int main(int argc, char* argv[]){
  if(argc != '3'){
    cerr << "Usage: ./a.out <input> <output>" << endl;
    exit(0);
  }

  fstream input,output;
  input.open(argv[1],ios::in);
  if(input.fail()){
    cerr <<"Errore apertura file di input." << endl;
    exit(1);
  }

  output.open(argv[1],ios::out);
  if(output.fail()){
    input.close();
    cerr << "Errore apertura file di output." << endl;
    exir(2);
  }

  //corpo del main.

  input.close();
  output.close();

  return 0;
}



//definizioni funzioni aggiuntive
