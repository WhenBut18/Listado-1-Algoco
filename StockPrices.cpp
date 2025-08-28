#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <string>

int main(){
    int casosPrueba, cantidadOrdenes, actualOferta = 0, actualDemanda = 0, actualVenta = 0, aux3, aux4;
    string orden, aux1, aux2;
    map<int,int> mapOferta;
    map<int,int, greater<int>> mapDemanda;
    vector<vector<string>> ordenes;
    cin >> casosPrueba;
    for (int i = 0; i < casosPrueba; i++){
        cin >> cantidadOrdenes;
        for (int j = 0; j < cantidadOrdenes; j++){
            cin >> orden >> aux1 >> aux2 >> aux2 >> aux2;
            ordenes.push_back({orden, aux1, aux2});
        }
        ordenes.push_back({"next"});
    }

    for (int i = 0; i < ordenes.size()-1; i++){
        if (ordenes[i][0] == "next"){
            mapDemanda.clear(), mapOferta.clear();
            continue;
        }
        if (ordenes[i][0] == "buy"){
            if (mapOferta.empty()){
                mapDemanda[stoi(ordenes[i][2])] += stoi(ordenes[i][1]);
            }
            aux3 = stoi(ordenes[i][1]);
            for (auto oferta : mapOferta) {
                cout << "oferta: " << oferta.first << endl;
                if (oferta.first > stoi(ordenes[i][2])){
                    cout << "no hay match de precio" << endl;
                    mapDemanda[stoi(ordenes[i][2])] += stoi(ordenes[i][1]);
                    break;
                }
                aux4 = oferta.second;
                if (aux4 >= aux3){
                    actualVenta = oferta.first;
                    aux4 -= aux3;
                    if (aux4 == 0){
                        cout << "cantidad igual" << endl;
                        mapOferta.erase(oferta.first);
                    } else {
                        cout << "cantidad mayor" << endl;
                        mapOferta[oferta.first] = aux4;
                    }
                    break;
                }
                aux3 -= aux4;
                actualVenta = oferta.first;
                mapOferta.erase(oferta.first);
            }
            if (aux3 > 0){
                mapDemanda[stoi(ordenes[i][2])] += aux3;
            }
        }
        if (ordenes[i][0] == "sell"){
            if (mapDemanda.empty()){
                mapOferta[stoi(ordenes[i][2])] += stoi(ordenes[i][1]);
            }
            aux3 = stoi(ordenes[i][1]);
            for (auto demanda : mapDemanda) {
                cout << "demanda " << demanda.first<< endl;
                if (demanda.first < stoi(ordenes[i][2])){
                    cout << "no hay match de precio" << endl;
                    cout << stoi(ordenes[i][2]) << " " << stoi(ordenes[i][1]) << endl;
                    mapDemanda[stoi(ordenes[i][2])] += stoi(ordenes[i][1]);
                    break;
                }
                aux4 = demanda.second;
                if (aux3 >= aux4){
                    actualVenta = demanda.first;
                    aux4 -= aux3;
                    if (aux4 == 0){
                        cout << "cantidad igual" << endl;
                        mapDemanda.erase(demanda.first);
                    } else {
                        cout << "cantidad mayor" << endl;
                        mapDemanda[demanda.first] = aux4;
                    }
                    break;
                }
                aux3 -= aux4;
                actualVenta = demanda.first;
                mapDemanda.erase(demanda.first);
            }
            if (aux3 > 0){
                mapOferta[stoi(ordenes[i][2])] += aux3;
            }
        }
        if (mapOferta.empty()){
            actualOferta = 0;
        } else {
            auto it = mapOferta.begin();
            actualOferta = it->first;
        }
        if (mapDemanda.empty()){
            actualDemanda = 0;
        } else {
            auto it = mapDemanda.begin();
            actualDemanda = it->first;
        }
        if (!actualOferta){
            cout << "- ";
        } else {
            cout << actualOferta << " ";
        }
        if (!actualDemanda){
            cout << "- ";
        } else {
            cout << actualDemanda << " ";
        }
        if (!actualVenta){
            cout << "-" << endl;
        } else {
            cout << actualVenta << endl;
        }
    }
    return 0;
}
