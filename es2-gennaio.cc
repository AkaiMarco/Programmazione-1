#include <iostream>
#include <cstdlib>
#include <cassert>

struct node {
		char info;
		node * next;
};

void dealloca(node *& s) {
		while(s != NULL) {
				node * t = s;
				s = s->next;
				delete t;
		}
}

void stampa_lista(const char * testo, node * s) {
		std::cout << testo;
		for( ; s!= NULL; s=s->next) {
				std::cout << " " << s->info;
		}
		std::cout << std::endl;
}

// Scrivere qui sotto la dichiarazione della funzione compute_lists ed
// eventuali funzioni accessorie
void compute_lists(const char* l,node* & s1,node* & s2);
// Scrivere qui sopra la dichiarazione della funzione compute_lists ed
// eventuali funzioni accessorie

int main(int argc, char **argv) {
		if (argc != 2) {
				std::cout << "Usage: " << argv[0]
														<< " \"stringa di caratteri\"" << std::endl;
				exit(1);
		}
		node * s1, * s2;
		std::cout << "La stringa da analizzare e': " << argv[1] << std::endl;

		compute_lists(argv[1], s1, s2);

		stampa_lista("Lista s1:", s1);
		stampa_lista("Lista s2:", s2);
		dealloca(s1);
		dealloca(s2);
}

// Scrivere qui sotto la definizione della funzione compute_lists ed
// eventuali funzioni accessorie
void compute_lists(const char* l, node* & s1, node* & s2){
  if (*l=='\0'){
    s1=s2=NULL;
  }
  else if(*l >= '0' && *l <= '4'){
    char p = ('4' - *l) + '0';
    compute_lists(l+1, s1, s2);
    node* ns = new node;
    ns->info = p;
    ns->next = s1;
    s1=ns;
  }
  else if(*l >='5' && *l <= '9'){
    char q = ('9' - *l) + '5';
    compute_lists(l+1,s1,s2);
    node* ns = new node;
    ns->info = q;
    ns->next = s2;
    s2=ns;
  }
  else{
    compute_lists(l+1,s1,s2);
  }
}
// Scrivere qui sopra la definizione della funzione compute_lists ed
// eventuali funzioni accessorie
