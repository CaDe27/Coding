#include <iostream>
#include <string>
using namespace std;

void resolverCaso() {
  string a = "abc", s;
  int diferentes = 0;
  cin>>s;
  for(int i = 0; i < 3; ++i)
    if(s[i] != a[i])
        ++diferentes;
  if(diferentes > 2)
    cout<<"NO\n";
  else
    cout<<"YES\n";
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    resolverCaso();
  }
  return 0;
}