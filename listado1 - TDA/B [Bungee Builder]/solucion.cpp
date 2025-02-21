#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;

int calc(int* lista,int n,int maxi, int max){
    int ret=0,menor;
    menor=max;
    for (int i=maxi-1;i>=0;i--){
        if (lista[i]<menor)
            menor=lista[i];
        if ((lista[i]-menor)>ret)
            ret=lista[i]-menor;
    }
    menor=max;
    for (int i=maxi+1;i<n;i++){
        if (lista[i]<menor)
            menor=lista[i];
        if ((lista[i]-menor)>ret)
            ret=lista[i]-menor;
    }
    return ret;
}



int main(){
    int n,respuesta,max=0,maxi=0;
    cin>>n;
    cin.ignore();
    int arr[n];
    for (int j=0;j<n;j++){
        cin>>arr[j];
        if (arr[j]>max){
            max=arr[j];
            maxi=j;
        }
    }
    respuesta=calc(arr,n,maxi,max);
    cout<<respuesta<<"\n";
}