/*
 * Esempio di cambio base usando una look-up table invece di
 * if/else che sono meno generali.  Per esempio:
 *
 * > ./a.out 3 123456 
 * "101101" = 45 in base 2. Caratteri non usati <>
 *
 * > ./a.out 17 abcdh0
 * "abcdh0" = 52526 in base 17. Caratteri non usati <h0>
 *
 */

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdlib.h>

constexpr const unsigned char UNDEF = 255;

// Inizializza la tabella usata per trasformare caratteri.  
// Questo e' un approccio generale.  Costruisci una tabella,
// scegli valori speciali per segnalare errori e riempi la 
// tabella con quelli, poi riempi le posizione di interesse.
void init(unsigned char* p, int base) {
    // Inizia a riempire le posizione da 0 a 9.
    for (int i = 0; i < 10 && i < base ; ++i) {
        p['0' + i] = i;
    }

    // Nel caso la base sia minore o uguale a diece questo loop
    // non viene mai eseguito
    for (int i = 0; i < base - 10; ++i) {
        p['a' + i] = 10 + i;
        p['A' + i] = 10 + i;
    }
}



// Questa funzione scrive il risultato in n (passato per referenza) e ritorna
// il punto della stringa oltre i caratteri che  sono stati consumati per il numero.
// Questa e' una cosa abbastanza normale.
char* cambia_base(char* s, int& n, int base, unsigned char* translation_table) {
    n = 0;

    // s e' una copia del puntatore nella funzione chiamante.  Qui possiamo 
    // modificarlo (invece di prendere una ulteriore copia).
    for ( ; *s > 0; ++s ) {   
        unsigned char c = translation_table[(int)(*s)];
        if ( c == UNDEF ) break;
        n = n * base + c;   // Tipico.  Permette di iniziare dall'inizio.
    }
    return s;
}



int main(int argc, char* argv[]) {

    if ( argc != 3 ) {
        return 1;
    }

    int base;
    std::stringstream{argv[1]} >> base;
    if ( base > 34 ) {
        // Error message here
        return 1;
    }

    unsigned char translation_table[256];
    memset(translation_table, UNDEF, 256);
    init(translation_table, base);

    int n;
    char* p = cambia_base(argv[2], n, base, translation_table);

    std::cout << "\"" << argv[2] << "\" = " << n << " in base " << base
              << ". Caratteri non usati <" << p << ">" << std::endl;
    return 0;
}
