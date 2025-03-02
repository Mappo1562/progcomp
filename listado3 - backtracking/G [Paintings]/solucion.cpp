#include <bits/stdc++.h>
using namespace std;

vector<string> perm;
vector<bool> usado;
vector<string> respuesta;

unordered_map<string,unordered_set<string>> inaceptable;
vector<string> arr;
long long sum;


void permute() {
    if (perm.size() == arr.size()) {
        if (respuesta.empty()){
            for (string x:perm)
                respuesta.push_back(x);
        }
        sum++;
        return;
    }

    for (unsigned int i = 0; i < arr.size(); i++) {
        if (!usado[i]) {
            if (!perm.empty()) {
                string prev = perm.back();
                if (inaceptable[prev].count(arr[i])) {
                    continue;
                }
            }

            usado[i] = true;
            perm.push_back(arr[i]);
            permute();
            perm.pop_back();
            usado[i] = false;
        }
    }
}

int main(){
    int n,m,t;
    cin>>t;
    for(;t>0;t--){
        string salida;
        cin>>n;
        arr.assign(n, ""); 
        usado.assign(n, false); 
        for (int i=0;i<n;i++){
            cin>>arr[i];
        }
        string aux1,aux2;
        cin>>m;
        for (int i=0;i<m;i++){
            cin>>aux1>>aux2;
            inaceptable[aux1].insert(aux2);
            inaceptable[aux2].insert(aux1);
        }
        // funcion q ve las combinaciones
        permute();
        cout<<sum<<"\n";
        for (auto x:respuesta)
            cout<<x<<" ";
        cout<<"\n";
        inaceptable.clear();
        arr.clear();
        usado.clear();
        respuesta.clear();
        sum=0;
    }

} 