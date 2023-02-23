#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;
typedef long long int lld;

const int MAXN = 100002;

vector < int > adj[MAXN];
int padre[MAXN][25];
int level[MAXN];
    lld costo[MAXN];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  while(n != 0) {
    for (int i = 0; i < n; ++i) adj[i].clear();

    level[0] = 0;
    costo[0] = 0;
    padre[0][0] = 0;
    
    for (int i = 1; i < n; ++i) {
      int p; lld c;
      cin >> p >> c;
      padre[i][0] = p;
      level[i] = level[p] + 1;
      costo[i] = costo[p] + c;
      adj[p].push_back(i);
    }
    for (int nodo = 1; nodo < n; ++nodo) {
      for (int k = 1; k < 25; ++k) {
        padre[nodo][k] = padre[padre[nodo][k-1]][k-1];
      }
    }
    
    int Q;
    cin >> Q;
    for (int caso = 0; caso < Q; ++caso) {
      int s, t;
      cin >> s >> t;
      
      // Find lca
      int a = s, b = t;
      if (level[a] < level[b]) swap(a, b);
      
      for (int i = 24; i >= 0; --i) {
        if (level[padre[a][i]] > level[b]) {
          a = padre[a][i];
        }
      }
      if (level[a] > level[b]) a = padre[a][0];
      
      for (int i = 24; i >= 0; --i) {
      		if (padre[a][i] != padre[b][i]) {
      		  a = padre[a][i];
      		  b = padre[b][i];
      		}
      }
      
      int lca = a;
      if (a != b) lca = padre[lca][0];
      
      if (caso) cout << " ";
      cout << costo[s] + costo[t] - 2ll * costo[lca];
    }
    cout << "\n";
    cin >> n;
  }
  return 0;
}