#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <string>

int main(){
    vector<string> instrucciones;
    set<string> resultado;
    string instruccion;
    while (cin >> instruccion){
        instrucciones.push_back(instruccion);
    }
    for (int i = 0; i <  instrucciones.size(); i++){
        for (int j = 0; j < instrucciones.size(); j++){
            if (!(instrucciones[i] == instrucciones[j])){
                resultado.insert(instrucciones[i]+instrucciones[j]);
            }
        }
    }
    for (auto i : resultado) 
        cout << i << endl;
    return 0;
}
