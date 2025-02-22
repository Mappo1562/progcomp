#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    int n,m,x;
    long long sum=0;
    cin>>n;
    cin>>m;
    vector<int> pinturas(n);
    for(int i=0;i<n;i++)
        cin>>pinturas[i];

    sort(pinturas.begin(),pinturas.end());

    
    for (int i=0;i<m;i++){
        cin>>x;
        auto it = lower_bound(pinturas.begin(), pinturas.end(), x);
        if (it != pinturas.end()) {
            sum += *it - x;
        }
    }
    cout<<sum<<"\n";
}