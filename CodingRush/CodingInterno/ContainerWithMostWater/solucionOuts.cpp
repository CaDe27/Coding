#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int main() {
    int n;
    int arre[100000];
    const string nombreProblema = "containerWithMostWater";
    const string GRUPO = nombreProblema + "/cases/"; // sin_grupo/, easy/, ...
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
        cin>>n;

        for(int i = 0; i < n; ++i)
            cin>>arre[i];
        
        int resp = 0;
        for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            resp = max(resp, min(arre[i], arre[j])*(j-i));
        }
        }
        cout<<resp<<"\n";
    }
    return 0;
}