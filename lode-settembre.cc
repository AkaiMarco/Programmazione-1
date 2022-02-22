#include <iostream>


// Inserire qui sotto dichiarazione funzione compute_pi
double compute_pi(int n);
// Inserire qui sopra dichiarazione funzione compute_pi

int main(int argc, char ** argv) {


  int N;

  std::cout << "Inserire numero positivo N= ";
  std::cin >> N;

  std::cout << "Valore approssimato serie Leibniz-Madhava(N="
	    << N << ") = " << compute_pi(N) << std::endl;
  return 0;
}


// Inserire definizione di compute_pi qui sotto
double compute_pi(int n){
  double pi;
  double val;
  if(n<0){
    std::cerr<<"N deve essere positivo o nullo" << std::endl;
    exit(0);
  }
  else{
    if(n==0){
      pi = 4;
    }
    else if(n%2 == 0){
      val = (2*n) + 1;
      pi = 4/val + compute_pi(n-1);
    }
    else if(n%2 != 0){
      val = -(2*n + 1);
      pi = 4/val + compute_pi(n-1);
    }
  }
  return pi;
}
// Inserire definizione di compute_pi qui sopra
