#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
using namespace std;



void merge(vector<vector<string>>& arr, int inicio, int centro, int final, int c){
    int n1 = centro-inicio+1, n2 = final-centro;
    vector<vector<string>> izq(n1),der(n2);
    for(int i=0;i<n1;i++){
        izq[i]=arr[inicio+i];
    }
    for(int i=0;i<n2;i++){
        der[i]=arr[centro+1+i];
    }

    int i=0,j=0,k=inicio;
    while (i < n1 && j < n2) {
        if (izq[i][c]<=der[j][c]) {
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

void mergesort(vector<vector<string>>& arr, int inicio, int final, int c){
    if (inicio<final){
        int centro=(inicio+final)/2;
        mergesort(arr,inicio,centro, c);
        mergesort(arr,centro+1,final, c);
        merge(arr, inicio, centro, final, c);      
    }

}

void print(vector<string> arr){
    for (string p : arr) {
        cout << p << " ";
    }
    cout<<"\n";
}

void print(vector<vector<string>> l,int x,int y){

    for (int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<l[i][j]<<" ";
        }
        cout<<"\n";
    }

}

int main(){
    vector<string> dios;
    int n,indice,n2;
    string linea, palabra;
    getline(cin, linea);
    stringstream ss(linea);
    while (ss >> palabra) {
        dios.push_back(palabra);
    }
    int god=dios.size();
    cin>>n;
    vector<vector<string>> data(n , vector<string>(god));
    for (int i=0;i<n;i++){
        for (int j=0;j<god;j++){
            cin>>data[i][j];
        }
    }

    cin>>n2;
    for (int i=0;i<n2;i++){
        cin>>palabra;
        for (int j=0;j<god;j++){
            if (palabra==dios[j]){
                indice = j;
                break;
            }
        }
        mergesort(data,0,n-1,indice);
        print(dios);
        print(data,n,god);
        cout<<"\n";
    }

}