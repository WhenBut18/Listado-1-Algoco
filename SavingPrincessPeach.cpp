#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <string>

int main(){
    int totalObstaculos = 0, registradosObstaculos = 0, aux = 0;
    cin >> totalObstaculos >> registradosObstaculos;
    vector<int> obstaculos;
    for (int i = 0; i < registradosObstaculos; i++){
        cin >> aux;
        if (find(obstaculos.begin(), obstaculos.end(), aux) == obstaculos.end()){
            obstaculos.push_back(aux);
        }
    }
    sort(obstaculos.begin(),obstaculos.end());
    aux = 0;
    for (int i = 0; i < totalObstaculos; i++){
        if(obstaculos.size() > aux){
            if(i == obstaculos[aux]){
                aux++;
                continue;
            }
        }
        cout << i << endl;
    }
    cout << "Mario got "<< aux << " of the dangerous obstacles.";
    return 0;
}
