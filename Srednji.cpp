#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <string>

int main() {
    int sizeVector, mediana;
    cin >> sizeVector >> mediana;
    vector<int> numeros(sizeVector);
    for (int i = 0; i < sizeVector; ++i) {
        cin >> numeros[i];
    }
    int pos_mediana = 0;
    for (int i = 0; i < sizeVector; ++i) {
        if (numeros[i] == mediana) {
            pos_mediana = i;
            break;
        }
    }
    unordered_map<int,int> conteo_balance;
    conteo_balance[0] = 1;
    int balance = 0;
    for (int i = pos_mediana - 1; i >= 0; --i) {
        if (numeros[i] < mediana) {
            --balance;
        } else {
            ++balance;
        }
        ++conteo_balance[balance];
    }
    int cantSubArreglo = 0;
    balance = 0;
    for (int i = pos_mediana; i < sizeVector; ++i) {
        if (numeros[i] < mediana) {
            --balance;
        } else if (numeros[i] > mediana) {
            ++balance;
        }
        cantSubArreglo += conteo_balance[-balance];
    }

    cout << cantSubArreglo << endl;
}