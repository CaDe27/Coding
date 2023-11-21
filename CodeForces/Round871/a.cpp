#include <iostream>
#include <string>
using namespace std;
 
void resolverCaso() {
  string codeforces = "codeforces";
  string s;
  int contador = 0;
  cin >> s;
  for (int i = 0; i < 10; i++) {
    if (codeforces[i] != s[i]) {
      ++contador;
    }
  }
  cout<<contador<<"\n";
}
 
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    resolverCaso();
  }
  return 0;
}