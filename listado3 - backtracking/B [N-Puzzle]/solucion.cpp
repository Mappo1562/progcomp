
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;


void init(unordered_map <char, pair<int,int>>& god){
    char L='A';
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            god[L].first=i;
            god[L].second=j;
            L++;
        }
    }
}

int calc(unordered_map <char, pair<int,int>>& god){
    int sum=0;
    char L;
    pair<int,int> aux;
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            cin>>L;
            aux = god[L];
            if (L!='.')
                sum += (abs(aux.first-i) + abs(aux.second-j));
        }
    }
    return sum;
}

int main(){
    int sum=0;
    unordered_map <char, pair<int,int>> god;
    init(god);
    sum=calc(god);
    cout<<sum<<"\n";
}