#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <string>

int main(){
    int casos, iteraciones, precio, cant;
    string tipotrans, trash;
    cin >> casos;
    while (casos--){
        map<int,int> sellMap;
        map<int,int,greater<int>> buyMap;
        list<int> output = {0,0,0};
        cin >> iteraciones;
        while (iteraciones--){
            cin >> tipotrans >> cant >> trash >> trash >> precio;
            if (tipotrans == "buy"){
                for (auto p : sellMap){
                    if (p.first > precio){
                        break;
                    }
                    if (p.second > cant){
                        sellMap[p.first] = p.second - cant;
                        cant = 0;
                    } else {
                        cant -= p.second;
                        sellMap.erase(p.first);
                    }
                }
                if (cant > 0){
                    buyMap[precio] += cant;
                }
            } else {
                for (auto p : buyMap){
                    
                }
            }
        }
        
    }
    
    
    return 0;
}