#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


const string vocales = "AEIOU"; 
const string letras = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  
string s;

bool esvocal(char C) {
    return C=='A' || C=='E' || C=='I' || C=='O' || C=='U' ;
}

long long int procedure(int i, int l, int v, int c) {
    if (v == 3|| c == 3){
        return 0;
    }
    if (i==s.size()){
        if (l)
            return 1;
        return 0;
    }
    if (esvocal(s[i]))
        return procedure(i+1,l,v+1,0);
    if (s[i]=='_')
        return 5*procedure(i+1,l,v+1,0) + 20*procedure(i+1,l,0,c+1) + procedure(i+1,l+1,0,c+1);
    if (s[i]=='L')
        return procedure(i+1,l+1,0,c+1);
    return procedure(i+1,l,0,c+1);
}

int main() {
    cin >> s;  
    
    cout << procedure(0,0,0,0) << endl;
    return 0;
}