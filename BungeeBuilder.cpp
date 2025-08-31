#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <string>

int main(){
    list<int> alturas;
    int cantMontañas, altura, MaxIzqAltura, MaxDerAltura, MinIzqAltura, MinDerAltura, DifIzq, DifDer;
    cin >> cantMontañas;
    while (cantMontañas--){
        cin >> altura;
        alturas.push_back(altura);
    }
    auto DerCursor = prev(alturas.end()), IzqCursor = alturas.begin();
    MaxIzqAltura = *IzqCursor, MinIzqAltura = *IzqCursor, MaxDerAltura = *DerCursor, MinDerAltura = *DerCursor, DifDer = 0, DifIzq = 0;
    cantMontañas = alturas.size();
    while ((cantMontañas--) - 1){
        --DerCursor, ++IzqCursor;
        if (MaxDerAltura <= *DerCursor){
            MaxDerAltura == *DerCursor;
            MinDerAltura == *DerCursor;
        }
        if (MaxIzqAltura <= *IzqCursor){
            MaxIzqAltura == *IzqCursor;
            MinIzqAltura == *IzqCursor;
        }
        if (MinDerAltura > *DerCursor){
            MinDerAltura = *DerCursor;
        }
        if (MinIzqAltura > *IzqCursor){
            MinIzqAltura = *IzqCursor;
        }
        if (DifDer < MaxDerAltura-MinDerAltura){
            DifDer = MaxDerAltura-MinDerAltura;
        }
        if (DifIzq < MaxIzqAltura-MinIzqAltura){
            DifIzq = MaxIzqAltura-MinIzqAltura;
        }
    }
    if (DifDer >= DifIzq){
        cout << DifDer;
    } else {
        cout << DifIzq;
    }
    return 0;
}
