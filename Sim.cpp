#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <string>

int main(){
    int casos;
    list<char> resultado;
    auto bis = resultado.begin();
    string instruccion;
    cin >> casos;
    cin.ignore();
    for (int i = 0; i < casos; i++){
        auto cursor = resultado.end();
        getline(cin, instruccion);
        for(auto p: instruccion){ 
            if (p == '[') {
                cursor = resultado.begin();
            } else if (p == ']'){
                cursor = resultado.end();
            } else if (p == '<'){
                if (cursor != resultado.begin()){
                    cursor--;
                    cursor = resultado.erase(cursor);
                }
            } else {
                cursor = resultado.insert(cursor, p);
                cursor++;
            }
        }
        for (auto p : resultado){
            cout << p;
        }
        cout << endl;
        resultado.clear();
    }  
    return 0;
}
