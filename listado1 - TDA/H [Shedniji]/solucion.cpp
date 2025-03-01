// A ask price :  el precio mas bajo que alguien esta dispuesto a VENDER
// B bird price:  el precio mas alto que alguien esta dispuesto a PAGAR
// S stock price: el precio de la ultima operacion

// B >= A -> hay trato, se vende al valor de A
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr;
    int n,b,pos;
    cin>>n>>b;
    int x = -1; 
    for (int i=0;i<n;i++){
        cin>>arr[i];
        if (arr[i] = b){
            x = i;
        }
    }
    if (x=-1){
        cout<<"0\n";
        return 0;
    }

    // en el unordered_map la key ve la diferencia entre cantidad de numeros mayores y menores
    // el valor que guarda, es la cantidad de veces que se repite esa diferencia
    unordered_map<int,int> map;
    int pos=0;
    map[0] = 1; // caso trivial

    // se comienza revisando la primera mitad
    for (int i=x-1;i>-1;i--){
        if (arr[i]<b)
            pos--;
        else
            pos++;
        map[pos]++;
    }
    
    // la otra mitad tambien se revisa, y se guarda el resultado en r
    int r=1;
    pos=0;
    for (int i=x+1;i<n;i++){
        if (arr[i]<b)
            pos--;
        else
            pos++;
        r += map[-pos]; //si existe el inverso, se suman todas las repeticiones
    }
    cout<<r<<"\n";
}