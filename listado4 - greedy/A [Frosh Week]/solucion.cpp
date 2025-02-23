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

int comparar(int a,int b){
    return a<b;
}

int main(){
    int n,m,sum=0;
    cin>>n>>m;
    vector<int> silencio(m), tareas(n);
    for (int i=0;i<n;i++)
        cin>>tareas[i];

    for (int i=0;i<m;i++)
        cin>>silencio[i];

    sort(silencio.begin(),silencio.end());

    //cout<<"\n";
    for (int i=0;i<n;i++){
        //cout<<"tarea: "<<tareas[i]<<"\n";
        //print(silencio);
        auto it = lower_bound(silencio.begin(),silencio.end(),tareas[i]);
        //cout<<"silencio: "<<*it<<"\n\n";
        if (it!=silencio.end()){
            silencio.erase(it);
            sum++;
        }
        
    }
    //print(silencio);
    cout<<sum<<"\n";
}