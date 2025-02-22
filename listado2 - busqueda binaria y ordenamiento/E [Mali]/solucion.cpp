#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int n,a,b;
    cin>>n;

    vector<int> A(101,0),B(101,0);
    for (int i=0;i<n;i++){
        int acuma=0,acumb=0,max=0,k=0;
        cin>>a>>b;
        A[a]++;
        B[b]++;
        for (int j=100;j>0;j--){
            if (A[j]!=0){
                acuma+=A[j];
                while (acumb<acuma){
                    k++;
                    acumb+=B[k];
                }
                if (max<j+k){
                    max=j+k;
                }
            }
        }
        cout<<max<<"\n";
    }
}