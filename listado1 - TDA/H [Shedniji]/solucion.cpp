
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,b;
    cin>>n>>b;
    vector<int> arr(n);
    int x = -1; 
    for (int i=0;i<n;i++){
        cin>>arr[i];
        if (arr[i] == b){
            x = i;
        }
    }
    if (x==-1){
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
    int r=0;
    pos=0;

    for (int i=x+1;i<n;i++){
        if (arr[i]<b)
            pos--;
        else
            pos++;
        r += map[-pos]; //si existe el inverso, se suman todas las repeticiones
    }
    r+=map[0];
    cout<<r<<"\n";
}