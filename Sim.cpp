#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <string>

int main(){
    int casos, cursor = 0;
    vector<string> instrucciones;
    string instruccion, resultado;
    cin >> casos;
    cin.ignore();
    for (int i = 0; i < casos; i++){
        getline(cin, instruccion);
        instrucciones.push_back(instruccion);
    }
    for(auto l: instrucciones){
        for(auto p: l){
            if (p == '[') {
                cursor = 0;
            } else if (p == ']'){
                cursor = resultado.size();
            } else if (p == '<'){
                if (!(cursor == 0)){
                    cursor--;
                    resultado.erase(cursor,1);
                }
            } else {
                resultado.insert(cursor, 1, p);
                cursor++;
            }
        }
        cout << resultado << endl;
        cursor = 0;
        resultado.clear();
    }
    return 0;
}
