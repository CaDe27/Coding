#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
typedef int64_t ll;
int n;

int main() {
    const string nombreProblema = "maxPairMatching";
    const string GRUPO = nombreProblema + "/cases/"; // sin_grupo/, easy/, ...
    vector<ll> proms;
    for(int t = 0; t < 15; ++t){
        string CASO = to_string(t); 
        
        ifstream in(GRUPO + CASO + ".in");

        streambuf *cinbuf = cin.rdbuf();
        cin.rdbuf(in.rdbuf());
        
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        ofstream out(GRUPO + CASO +".out");
        streambuf *coutbuf = cout.rdbuf(); 
        cout.rdbuf(out.rdbuf()); 

        ll a, b;
        cin>>n;
        ll resp = 0;
        
        proms.clear();
        for(int i=0; i<2*n; ++i){
            cin>>a>>b;
            if(a > b) swap(a,b);
            resp += (b-a);
            proms.push_back(a+b);
        }
        sort(proms.begin(), proms.end());
        for(int i = 0; i < n; ++i){
            resp += proms[2*n-1-i] - proms[i];
        }
        resp >>=1;
        cout<<resp<<"\n";
    }
    return 0;
}