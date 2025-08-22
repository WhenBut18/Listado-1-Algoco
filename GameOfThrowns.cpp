#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <string>

int main(){
    stack<int> historialPosiciones;
    string instruccion;
    int posicion, undo, calc, cantidadAlumnos, cantidadInstrucciones = 0;
    cin >> cantidadAlumnos >> cantidadInstrucciones;
    historialPosiciones.push(posicion);
    for (int i = 0; i < cantidadInstrucciones; i++){\
        cin >> instruccion;
        if (instruccion == "undo"){
            cin >> undo;
            for (int j = 0; j < undo; j++){
                historialPosiciones.pop();
            }
            posicion = historialPosiciones.top();
            continue;
        }
        calc = posicion + stoi(instruccion);
        calc = calc%cantidadAlumnos;
        if (calc < 0){
            posicion = cantidadAlumnos + calc;
        } else {
            posicion = calc;
        }
        historialPosiciones.push(posicion);
    }
    cout << posicion << endl;
    return 0;
}