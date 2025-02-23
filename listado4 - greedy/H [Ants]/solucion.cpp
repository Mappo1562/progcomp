#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int comparar(pair<int,int>& a,pair<int,int>& b){
    return a.first<b.first;
}


int main(){
    int casos,l,n,pos,dir;
    vector<int> hormigas;
    cin>>casos;
    for(int _=0;_<casos;_++){
        cin>>l;
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>pos;
            hormigas.push_back(pos);
        }

        // buscar el minimo:
        int mi = min(hormigas[0], l-hormigas[0]);
        int ma = max(hormigas[0], l-hormigas[0]);

        for (int i=0;i<n;i++){
            mi = max(mi, min(hormigas[i], l-hormigas[i]));
            ma = max(ma, max(hormigas[i], l-hormigas[i]));
        }
        cout<<mi<<" "<<ma<<"\n";
        hormigas.clear();
    }
}