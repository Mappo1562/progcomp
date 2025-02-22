#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;


void swap(int &a, int &b){
    int aux = a;
    a = b;
    b = aux;
}

int insertar(vector<int>& vect, int elm, int n){
    int sum=0;
    int i=0;
    for (;i<n;i++){
        if (vect[i]>elm)
            break;
    }
    swap(vect[i],elm);
    i++;
    for (;i<n+1;i++){
        swap(vect[i],elm);
        sum += 1;
    }
    return sum;
}

void print(vector<int>& vect){
    for (int i=0;i<20;i++)
        cout<<vect[i]<<" ";
    cout<<"\n";
}



int main(){
    int n;
    cin>>n;
    int nfila, altura, pasos=0;
    vector<int> vect(20,0);
    for (int j=0 ; j<n ; j++){
        cin>>nfila;

        for (int i=0;i<20;i++){
            cin>>altura;
            pasos += insertar(vect, altura,i);
        }
        cout<<nfila<<" "<<pasos<<"\n";
        pasos = 0;
        vect.clear();
    }
}