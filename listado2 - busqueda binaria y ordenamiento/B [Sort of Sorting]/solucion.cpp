#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;




int comparar(string a, string b){
    if (a.substr(0,2)<=b.substr(0,2))
        return 1;
    return 0;
}

void merge(vector<string>& arr, int inicio, int centro, int final){
    int n1 = centro-inicio+1, n2 = final-centro;
    vector<string> izq(n1),der(n2);
    for(int i=0;i<n1;i++){
        izq[i]=arr[inicio+i];
    }
    for(int i=0;i<n2;i++){
        der[i]=arr[centro+1+i];
    }

    int i=0,j=0,k=inicio;
    while (i < n1 && j < n2) {
        if (comparar(izq[i],der[j])) {
            arr[k] = izq[i];
            i++;
        } 
        else {
            arr[k] = der[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = izq[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = der[j];
        j++;
        k++;
    }
}


void mergesort(vector<string>& arr, int inicio, int final){
    if (inicio<final){
        int centro=(inicio+final)/2;
        mergesort(arr,inicio,centro);
        mergesort(arr,centro+1,final);
        merge(arr, inicio, centro, final);      
    }

}


int main(){
    int n=1;
    vector<string> arr;
    string aux;
    while (n){
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>aux;
            arr.push_back(aux);
        }
        mergesort(arr,0,n-1);
        for (int i=0;i<n;i++){
            cout<<arr[i]<<"\n";
        }
        cout<<"\n"; 
        arr.clear();
    }
}