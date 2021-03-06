// Online C++ compiler to run C++ program online
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
        nave.stampa();
    }
} Tnodo; // LISTA LIFO doppiamente concatenata

int random(int max, int min);
void newNave(Tnave* nave);
void addNave(Tnodo* por[], int dim, Tnave nave);
Tnodo* insertFirstConc(Tnodo* s, Tnave d);
Tnodo* insertLastConc(Tnodo* s, Tnave d);
void stampaPorti(Tnodo* por[], int dim);

int main() {
    
    cout << "OK" << endl;
    
    Tnodo* porti[DIM];
    Tnave nave;
    for (int i=0; i<DIM; i++) { porti[i] = NULL; }
    for (int i=0; i<5; i++) {
     newNave(&nave);
     nave.stampa();
     addNave(porti, DIM, nave);
    }
    
    stampaPorti(porti, DIM);
    /*
    cout << “\nnavi” << rimuoviESalvaNavi (porti, DIM, GUERRA);
    */
   system("PAUSE");
    return 0;
}

int random(int max, int min){
    return rand() % (max - min + 1) + min;
}

void newNave(Tnave* nave){
    //battello
    switch(random(2, 0)){
        case 0: {
            nave->tipoBattello = CARGO;
            break;
        }
        case 1: {
            nave->tipoBattello = PASSEGGERI;
            break;
        }
        case 2: {
            nave->tipoBattello = GUERRA;
            break;
        }
    }
    //annoVaro
    do{
        cout << "Anno: ";
        cin >> nave->annoVaro;
    }while(nave->annoVaro < 1990 || nave->annoVaro > 2019);
    //stazza
    nave->stazza = random(6000000, 2500000)/100;
    //nome nave
    char ins[20];
    cout << "Nome: ";
    cin >> ins;
    strcpy(nave->nomeNave, ins);
    cout << "==========" << endl;
}

void addNave(Tnodo* por[], int dim, Tnave nave){
    int x = random(dim, 0);
    por[x] = insertLastConc(por[x], nave);
}

Tnodo* insertLastConc(Tnodo* s, Tnave d){
  if(s == NULL){
    return insertFirstConc(s, d);
  }
  Tnodo* p = s;
  while(p->next != NULL){
    p = p->next;
  }
  Tnodo* t = new Tnodo(NULL, p, d);
  p->next = t;
  return s;
}

Tnodo* insertFirstConc(Tnodo* s, Tnave d){
  Tnodo* q = new Tnodo();
  q->nave = d;
  q->next = s;
  q->prev = NULL;
  if(s != NULL){
    s->prev = q;
  }
  return q;
}

void stampaPorti(Tnodo* por[], int dim){
	Tnodo* tmp;
	int i;
	for(i=0 ; i<dim ; i++){
		tmp = por[i];
		while(tmp){
			tmp->stampa();
			printf("\n");
			tmp = tmp->next;
		}
	}
}
