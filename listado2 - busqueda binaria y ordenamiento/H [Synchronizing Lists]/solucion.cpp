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

void quicksort(vector<int>& arr, int inicio, int final){
    if (final<=inicio)
        return;
    int pivote=arr[final],j=inicio-1;
    for (int i=inicio;i<final;i++){
        if (arr[i]<pivote){
            j++;
            swap(arr[i],arr[j]);
        }
    }
    j++;
    swap(arr[j],arr[final]);
    quicksort(arr,inicio,j-1);
    quicksort(arr,j+1,final);
}

/*
a -> vector 1 ordenado
b -> vector 2 ordenado
origin -> vector 1
*/
vector<int> lolmerge(vector<int> a,vector<int> b,vector<int> origin){
    vector<int> ret(a.size());
    for (unsigned int i=0;i<a.size();i++){
        for (unsigned int j = 0;j<a.size();j++){
            if (a[i]==origin[j]){
                ret[j]=b[i];
                break;
            }
        }
    }
    return ret;
}

int main(){
    int n,aux;
    vector<int> uno,dos,cop1,cop2;
    while (1){
        cin>>n;
        if (n==0) break;
        for (int i=0;i<n;i++){
            cin>>aux;
            uno.push_back(aux);
        }
        for (int i=0;i<n;i++){
            cin>>aux;
            dos.push_back(aux);
        }
        cop1=uno;
        cop2=dos;
        quicksort(cop1,0,n-1);
        quicksort(cop2,0,n-1);
        dos = lolmerge(cop1,cop2,uno);
        for (int a:dos){
            cout<<a<<"\n";
        }
        cout<<"\n";
        uno.clear();
        dos.clear();
        cop1.clear();
        cop2.clear();
    }
    
}