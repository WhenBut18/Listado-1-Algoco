#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <string>

int main(){
  int cantMont; 
  cin>>cantMont;
  vector<int> mont(cantMont);
  for(int &i: mont) {
    cin>>i;
  }
  int max = mont[0];
  int min = mont[0];
  int maxdiff = 0;
  bool adyacent = 1;
  for(int i = 1; i < cantMont; i++) {
    if (mont[i] >= max) {
      if (maxdiff < max-min) maxdiff = max-min;
      max = mont[i];
      min = mont[i];
    } else if (mont[i] < min) {
      min = mont[i];
    }
  }
  max = mont[cantMont-1];
  min = mont[cantMont-1];
  for(int i = cantMont-2; i >= 0; i--) {
    if (mont[i] >= max) {
      if (maxdiff < max-min) maxdiff = max-min;
      max = mont[i];
      min = mont[i];
    } else if (mont[i] < min) {
      min = mont[i];
    }
  }
  cout<<maxdiff;
  cout<<endl;
  return 0;
}