#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <string>

int main() {
    int casos;
    cin >> casos;

    while(casos--) {
        int n;
        cin >> n;
        map<int,int> sellMap;                
        map<int,int,greater<int>> buyMap;    
        int ultimoPrecio = -1;                   
        for(int i=0;i<n;i++) {
            string tipotrans, trash1, trash2;
            int cant, precio;
            cin >> tipotrans >> cant >> trash1 >> trash2 >> precio;
            if(tipotrans=="buy") {
                auto it = sellMap.begin();
                while(it != sellMap.end() && cant > 0) {
                    if(it->first > precio) break;
                    int trans = min(cant, it->second);
                    cant -= trans;
                    it->second -= trans;
                    ultimoPrecio = it->first;
                    if(it->second == 0) {
                        it = sellMap.erase(it);
                    } else {
                        ++it;
                    }
                }
                if(cant > 0) {
                    buyMap[precio] += cant;
                }
            } else { 
                auto it = buyMap.begin();
                while(it != buyMap.end() && cant > 0) {
                    if(it->first < precio){
                        break;
                    }
                    int trans = min(cant, it->second);
                    cant -= trans;
                    it->second -= trans;
                    ultimoPrecio = it->first;
                    if(it->second == 0) {
                        it = buyMap.erase(it);
                    } else {
                        ++it;
                    }
                }
                if(cant > 0) {
                    sellMap[precio] += cant;
                }
            }
            int sell = sellMap.empty() ? -1 : sellMap.begin()->first;
            int buy = buyMap.empty() ? -1 : buyMap.begin()->first;
            if(sell == -1) {
                cout<<"-";
            } else {
                cout<<sell;
            }
            cout<<" ";
            if (buy == -1) {
                cout<<"-"; 
            } else {
                cout << buy;
            }
            cout<<" ";
            if(ultimoPrecio==-1) {
                cout<<"-"; 
            } else {
                cout<<ultimoPrecio;
            }
            cout<<endl;
        }
    }

    return 0;
}