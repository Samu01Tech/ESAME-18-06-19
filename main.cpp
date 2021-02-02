#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define DIM 2
typedef enum Tbattello { CARGO, PASSEGGERI, GUERRA } Tbattello;
typedef struct Tnave{
    char nomeNave[20]; unsigned int annoVaro;
    float stazza;
    Tbattello tipoBattello;
    Tnave () {
        strcpy(nomeNave, "");
        annoVaro = 0;
        stazza = 0.0;
        tipoBattello = CARGO;
    }
    void stampa() const{
        cout << nomeNave << "(";
        switch(tipoBattello){
            case 0: {
                cout << "CARGO";
                break;
            }
            case 1: {
                cout << "PASSEGGERI";
                break;
            }
            case 2: {
                cout << "GUERRA";
                break;
            }
        }
        cout << ") " << stazza << " TON anno varo=" << annoVaro << endl;
    }
} Tnave;
typedef struct Tnodo {
    Tnave nave;
    Tnodo *next, *prev;
    Tnodo (Tnodo *n, Tnodo *p, Tnave _nave) {
        nave = _nave;
        next = n;
        prev = p;
    }
    Tnodo () {
        nave = Tnave();
        next = NULL;
        prev = NULL;
    }
    void stampa() const{
        //controllo nel main che non sia vuota
        Tnodo* s = next;
        while(s != NULL){
            s->stampa();
            s = s->next;
        }
        cout << endl;
    }
} Tnodo; // LISTA LIFO doppiamente concatenata

int main() {
    return 0;
}