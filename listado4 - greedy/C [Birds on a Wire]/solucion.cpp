#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



void print(vector<int> A){
    for (int i=0;i<A.size();i++){
        cout<<" "<<A[i];
    }
    cout<<"\n";
}

int main(){
    const int DP = 6;
    int l, d, n;
    cin>>l>>d>>n;
    //l = l - 2*DP; //distancia efectiva
    vector<int> pajaros(n);
    int a;
    for (int i=0;i<n;i++){
        cin>>a;
        pajaros[i]=a;
    }
    sort(pajaros.begin(),pajaros.end());
    int atras=0;
    int agregados=0;
    //print(pajaros);
    if (n>0){
        agregados += (pajaros[0] - 6) / d;
        //cout<<"agregados: "<<agregados<<"\n";
        for (int i=1;i<n;i++){
            agregados += (pajaros[i] - pajaros[i-1]) / d - 1;
            //cout<<"agregados: "<<agregados<<"\n";
        }
        agregados += (l-6 - pajaros[n-1]) / d ;
        //cout<<"agregados: "<<agregados<<"\n";
    }
    else
        agregados += (l - 12) / d + 1;
    //print(pajaros);
    cout<<agregados<<"\n";
}