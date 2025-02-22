#include <iostream>
#include <sstream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;



void print(const vector< pair<string , string> >& arr) {
    for (auto& pair : arr) {
        cout <<pair.first/*<<" value -> "<<pair.second*/<<"\n";

    }
    cout<<"==============================\n";
}

bool compare(const pair<string,string>& a, const pair<string,string>& b ){
    if (a.second == b.second)
        return a.first<b.first;
    int n =min(a.second.length(),b.second.length());
    int i=0;
    char last;
    for (;i<n;i++){
        if(a.second[i]!=b.second[i])
            return a.second>b.second;
        last=a.second[i];
    }
    int aux=a.second.length()-b.second.length();
    if (aux>0){
        for (;i<a.second.length();i++){
            if(a.second[i]!=last){
                if(a.second[i]<last)
                    return 0;
                return 1;
            }
        }
    }
    else{
        for (;i<b.second.length();i++){
            if(b.second[i]!=last){
                if(b.second[i]<last)
                    return 1;
                return 0;
            }
        }
    }
    return a.first<b.first;
}

int main(){
    int y,t,m;
    cin>>t;
    string linea,nombre,subclass,trash,lol;
    for (int o=0;o<t;o++){
        cin>>y;
        cin.ignore();
        vector<vector<string>> aux(y);
        vector< pair<string , string> > arr(y);
        m=0;
        for(int i=0;i<y;i++){
            cin>>nombre>>linea>>trash;
            nombre = nombre.substr(0, (int)nombre.size()-1);
            stringstream ss(linea);
            
            while (getline(ss, subclass, '-')) {
                if (subclass=="middle" || subclass=="middle class")
                    aux[i].push_back("2");
                else if(subclass=="lower" || subclass=="lower class")
                    aux[i].push_back("1");
                else
                    aux[i].push_back("3");
            }
            reverse(aux[i].begin(),aux[i].end());
            arr[i].first=nombre;
            m=max(m,(int)aux[i].size());
        }
        for (int i=0;i<y;i++){
            arr[i].second="";
            for (string x:aux[i]){
                arr[i].second+=x;
            }
            for (int j=0;j<m-(int)aux[i].size();j++){
                arr[i].second+="2";
            }
        }
        sort(arr.begin(),arr.end(),compare);
        print(arr);
        arr.clear();
        aux.clear();
    }
}