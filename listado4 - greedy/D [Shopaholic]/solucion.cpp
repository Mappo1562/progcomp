#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int comparar(int a,int b){
    return a>b;
}



int main(){
    int n;
    cin>>n;
    vector<int> carrito(n);
    for (int i=0;i<n;i++)
        cin>>carrito[i];
    
    sort(carrito.begin(),carrito.end(),comparar);
    long long int disscount=0;

    for (int i=2;i<n;i+=3){

        disscount+=carrito[i];
    }
    cout<<disscount<<"\n";
}