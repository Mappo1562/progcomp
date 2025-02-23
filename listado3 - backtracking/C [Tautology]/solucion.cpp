#include <iostream>
#include <algorithm>
#include <array>
using namespace std;


array<int,5> var;
string linea;


int procedure(int &i){
    char c = linea[i];
    if (c > 'Z'){// es minuscula (variable)
        return var[c-'p'];
    }
    int aux1,aux2;
    i++;
    if (c == 'N'){
        return !procedure(i);
    }
    if (c == 'K'){
        aux1=procedure(i);
        i++;
        aux2=procedure(i);
        return aux1&&aux2;
    }
    if (c == 'A'){
        aux1=procedure(i); 
        i++;
        aux2=procedure(i);
        return aux1||aux2;
    }
    if (c == 'C'){
        aux1 = procedure(i);
        i++;
        aux2 = procedure(i);
        if (aux1 && !aux2)
            return 0;
        return 1;
    }
    if (c == 'E'){
        aux1=procedure(i);
        i++;
        aux2=procedure(i);
        return aux1==aux2;
    }
}

int main() {
    int r;
    while (1){
        cin>>linea;
        if (linea=="0")
            break;

        for (int mask=0;mask<32;mask++){
            for (int i=0;i<5;i++){
                var[i]=(mask>>i)&1;
            }
            int value=0;
            r=procedure(value);
            if (!r){
                cout<<"not\n";
                break;
            }
        }
        if (r)
            cout<<"tautology\n";
    }
    return 0;
}