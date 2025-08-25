#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <string>

int main(){
    int casosPrueba, cantidadOrdenes, actualOferta, actualDemanda, actualVenta, aux1, aux2;
    string orden;
    vector<vector<int>> listaOferta, listaDemanda;
    cin >> casosPrueba;
    for (int i = 0; i < casosPrueba; i++){
        cin >> cantidadOrdenes;
        for (int j = 0; j < cantidadOrdenes; j++){
            cin >> orden;
            if (orden == "buy"){
                cin >> aux1 >> aux2 >> aux2 >> aux2;
                
            } else {

            }
        }
    }
    return 0;
}
