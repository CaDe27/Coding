#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int main() {
    const string nombreProblema = "";
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

        //resto del codigo
    }
    return 0;
}