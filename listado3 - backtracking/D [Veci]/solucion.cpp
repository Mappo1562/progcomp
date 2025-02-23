#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;



vector<vector<char>> permutaciones;
string numero;
string perm;
vector<bool> usado;
int respuesta;
int n;


void permute() {
    if (perm.size() == numero.size()) {
        if (stoi(perm) > n)
            if (stoi(perm)<respuesta)
                respuesta=stoi(perm);
        return;
    }

    for (int i = 0; i < numero.size(); i++) {
        if (!usado[i]) {
            usado[i] = true;
            perm.push_back(numero[i]);
            permute();
            perm.pop_back();
            usado[i] = false;
        }
    }
}

int main() {
    respuesta=9999999;
    cin >> numero;

    n = stoi(numero);

    usado.assign(numero.size(), false); 

    permute();
    if (respuesta==9999999)
        cout<<"0\n";
    else
        cout<<respuesta<<"\n";

    return 0;
}