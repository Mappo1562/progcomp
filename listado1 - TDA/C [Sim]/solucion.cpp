#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

typedef char tElemLista;

struct tNodo{
    tElemLista info;
    tNodo* sig;
    tNodo* ant;
};



class tLista {
    private:
        tNodo* head;
        tNodo* tail;
        tNodo* curr;//                                      apuntara siempre al nodo anterior del actual, para acceder al valor seria curr->sig->info
        int listSize;
        int pos; // posicion actual en la lista
    public:

tLista() {
 head = tail = curr = new tNodo;
 listSize = 0;
 pos = 0;
}



void clear() {
    tNodo* aux;
    curr = head;
    while (curr->sig != NULL) {
        aux = curr->sig; 
        curr->sig = aux->sig;
        delete aux; 
    }
    tail = head;
    curr = head;
    listSize = 0;
    pos = 0;
}

int insert(tElemLista item) {
    tNodo* aux = curr->sig;
    curr->sig = new tNodo;
    curr->sig->info = item;
    curr->sig->ant = curr;
    curr->sig->sig = aux;
    if (curr == tail)   
        tail = curr->sig;
    listSize++;
    return pos;
}


void moveToStart() { 
    curr = head; 
    pos = 0; 
}


void moveToEnd() { 
    curr = tail; 
    pos = listSize; 
}


int prev() {
    if (curr != head) { 
        curr = curr->ant; 
        pos--;
        return 1;
    } 
    else
        return 0;
}


void next() { 
    if (curr != tail) { 
        curr = curr->sig; 
        pos++; 
    } 
}


    tElemLista erase() {
        if (curr->sig == nullptr) return '\0';  

        tNodo* aux = curr->sig;
        tElemLista ret = aux->info;

        if (aux == tail) {
            tail = curr;
            curr->sig = nullptr;
        }
        else {
            curr->sig = aux->sig;
            aux->sig->ant = curr;
        }

        delete aux;
        listSize--;
        return ret;
    }






void print(){
    curr=head;
    pos=0;
    if (curr->sig==NULL){
        cout<<"\n";
        return;
    }
    while(curr->sig!=NULL){
        cout<<curr->sig->info;
        curr=curr->sig;
        pos++;
    }
    cout<<"\n";
}

};

int main(){
    tLista lista;
    string texto;
    int n;
    cin>>n;
    cin.ignore();
    for (int i=0; i<n; i++){
        getline(cin, texto);
        for(char c : texto){
            if (c==']'){
                lista.moveToEnd();
            }
            else if (c=='['){
                lista.moveToStart();
            }
            else if (c=='<'){
                if (lista.prev())
                    lista.erase();
            }
            else{
                lista.insert(c);
                lista.next();

            }
        }
        lista.print();
        lista.clear();
    }

}