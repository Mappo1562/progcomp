#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
vector<pair<int,int>> vec;
vector<vector<int>> tabla;




int main() {
    int c,n,v,p;
    while (cin>>c){
        cin>>n;
        tabla.assign(n + 1, vector<int>(c + 1, 0)); 
        for (int i=0;i<n;i++){
            cin>>v;
            cin>>p;
            vec.push_back(make_pair(v,p));
        }
        for(int i=0;i<=n;++i){ // se revisa el elemento i+1, i=0 es no elemento
            for(int j=0;j<=c;++j){ // se ve la capacidad de la mochila
                if (i==0 || j==0){
                    tabla[i][j] = 0;
                }
                else{
                    int r1= tabla[i-1][j];
                    int r2 = 0;
                    if (vec[i-1].second <= j)
                        r2 = tabla[i-1][j-vec[i-1].second] + vec[i-1].first;
                    tabla[i][j] = max(r1,r2);
                }
            }
        }
        int i=n;
        int j=c;
        vector<int> tilin;
        while (i>0 && j>0){
            if (tabla[i][j] != tabla[i - 1][j] ){
                //cout<<"### j = "<<j<<" ###\n";
                //cout<<i-1<<" ";
                tilin.push_back(i-1);
                j = j-vec[i-1].second;
            }
            i-=1;
        }

        cout<<tilin.size()<<"\n";
        for(int a:tilin){
            cout<<a<<" ";
        }
        cout<<"\n";
        tabla.clear();
        vec.clear();

    }
    return 0;
}