#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <string>

int main(){
    deque<string> listaActual;
    string instruccion, lista, numero;
    bool state = false, state2 = true;
    int casos, tamañolista;
    cin >> casos;
    for (int i = 0; i < casos; i++){
        cin >> instruccion;
        cin >> tamañolista;
        cin.ignore(2);
        for (int j = 0; j < tamañolista; j++){
            if (j+1 == tamañolista){
                getline(cin, numero, ']');
            } else {
                getline(cin, numero, ',');
            }
            listaActual.push_back(numero);
        }
        for (auto p : instruccion){
            if (p == 'R'){
                state = !state;
            } else if (p == 'D'){
                if (listaActual.empty()){
                    cout << "error" << endl;
                    state2 = false;
                    break;
                }
                if (state){
                    listaActual.pop_back();
                } else {
                    listaActual.pop_front();
                }
            } 
        }
        if (state2){
            cout << "[";
            if (state){
                for (int i = listaActual.size() - 1; i >= 0; --i) {
                    cout << listaActual[i];
                    if (i != 0){
                        cout << ",";
                    }
                }
            } else {
                for (int i = 0; i < listaActual.size(); i++) {
                    cout << listaActual[i];
                    if ((i + 1) != listaActual.size()){
                        cout << ",";
                    }
                }
            }
            cout << "]" << endl;
        }
        state2 = true;
        listaActual.clear();
        state = false;
    }
    return 0;
}
