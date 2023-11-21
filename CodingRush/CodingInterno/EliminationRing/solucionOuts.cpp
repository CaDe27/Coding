#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int main() {
    const string GRUPO = "eliminationRing/cases/"; // sin_grupo/, easy/, ...
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

        int n; cin>>n;
        set<int> diferentes;
        int num;
        int i = 0;
        for(int i = 0; i < n; ++i){
            cin>>num;
            if(diferentes.size() < 3)
                diferentes.insert(num);
        }
        
        int resp = diferentes.size() == 2? n/2 + 1 : n;
        cout<<resp<<"\n";
    }
    return 0;
}