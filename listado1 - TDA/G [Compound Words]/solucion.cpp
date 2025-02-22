#include <iostream>
#include <string>
using namespace std;

int in(string* conjunto,int n,string word){
    for (int i=0;i<n;i++){
        if (conjunto[i]==word)
            return 1;
    }
    return 0;
}

void print(string* conjunto,int n){
    string anterior;
    anterior="";
    for (int i=0;i<n;i++){
        if (!(anterior==conjunto[i])){
            cout<<conjunto[i]<<"\n";
        }
        anterior=conjunto[i];
    }
}

void swap(string &a, string &b) {
    string aux = a;
    a = b;
    b = aux;
}

int partition(string arr[], int min, int max) {
    string pivote = arr[max];  
    int i = min - 1;          

    for (int j = min; j < max; j++) {
        if (arr[j] <= pivote) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[max]);
    return i + 1;
}


void quicksort(string arr[], int min, int max) {
    if (min < max) {
        int pi = partition(arr, min, max);  
        quicksort(arr, min, pi - 1);
        quicksort(arr, pi + 1, max);
    }
}

int main(){
    string conjunto[100],palabra,ret[10000];
    int n=0;
    while(cin>>palabra){
        if (!in(conjunto,n,palabra)){
            conjunto[n]=palabra;
            n++;
        }
        palabra="";
    }


    int pos=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (!(i==j)){
                ret[pos]=conjunto[i]+conjunto[j];
                pos++;
            }
        }
    }
    quicksort(ret,0,pos-1);
    print(ret,pos);

}