#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


int obtmin(int n, vector<int>& bajo, vector<int>& alto, int h, int l){
    int m=0;
    auto it = lower_bound(bajo.begin(), bajo.end(), l);
    if (it != bajo.end()) {
        m += distance(it, bajo.end());
    }

    it = upper_bound(alto.begin(), alto.end(), h - l);
    if (it != alto.end()) {
        m += distance(it, alto.end());
    }

    return m;
}

int main(){
    int l,n,h,min=200000,rep=0,aux=1,x=0,y=0;
    cin>>n;
    cin>>h;
    vector<int> bajo(n/2),alto(n/2), resultado(h);
    for(int i=0;i<n;i++){
        if (i % 2 == 0) 
            cin >> bajo[i / 2];
        else 
            cin >> alto[i / 2];
    }

    sort(alto.begin(),alto.end());
    sort(bajo.begin(),bajo.end());


    for (int i=0;i<h;i++){
        resultado[i]=obtmin(n,bajo,alto,h,i+1);
        if (resultado[i]<min){
            min=resultado[i];
            rep=1;
        }
        else if(resultado[i]==min){
            rep+=1;
        }
    }
    cout<<min<<" "<<rep<<"\n";
}