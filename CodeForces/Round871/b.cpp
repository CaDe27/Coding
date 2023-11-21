#include <iostream>
#include <string>
using namespace std;

void resolverCaso() {
  int n; 
  cin>>n;

  int a[n];
  for(int i = 0; i < n; ++i){
    cin>>a[i];
  }
  
  int maximo = 0, contador = 0;
  for(int i = 0; i < n; ++i){
    if(a[i] == 0){
      ++contador;
    }
    else{
      contador = 0;
    }
    if(contador > maximo) 
        maximo = contador;
  }

  cout<<maximo<<"\n";
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    resolverCaso();
  }
  return 0;
}