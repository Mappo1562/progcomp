#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


int main() {
    int H,W;
    int aux,c=0;
    cin>>H>>W;
    int arrh[2],arrw[2];
    for (int i=0;i<2;i++){
        cin>>arrh[i];
        cin>>arrw[i];
    }
    if (arrh[0]==arrh[1] && arrh[0]==H && arrw[0]+arrw[1]+W==H){
        cout<<"YES\n";
        return 0;
    }
    int falta=H-W;
    int dist1,dist2;
    c=0;
    if (arrh[c]==falta){
        dist1=arrw[c];
    }
    else if (arrw[c]==falta){
        dist1=arrh[c];
    }
    else{
        cout<<"NO\n";
        return 0;
    }

    c=1;
    if (arrh[c]==falta){
        dist2=arrw[c];
    }
    else if (arrw[c]==falta){
        dist2=arrh[c];
    }
    else{
        cout<<"NO\n";
        return 0;
    }
    if (H==dist1+dist2){
        cout<<"YES\n";
        return 0;
    }
    cout<<"NO\n";
}