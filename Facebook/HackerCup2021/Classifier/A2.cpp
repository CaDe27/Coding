#include <iostream>
#include <string>

#define loop(i, a, b) for(int i = a; i < b; ++i)
using namespace std;

const int alphabetSize = 'Z'-'A'+1;
int costPath[alphabetSize][alphabetSize];

#define INF 10000
void cleanCostMatrix(){
    loop(i, 0, alphabetSize)
    loop(j, 0, alphabetSize)
        costPath[i][j] = i == j? 0 : INF;
}

void floydWarshall(){
    loop(k, 0, alphabetSize){
        loop(i, 0, alphabetSize)
        loop(j, 0, alphabetSize){
            costPath[i][j] = min(costPath[i][j], costPath[i][k] + costPath[k][j]);
        }
    }
}

int cost(string &s){
    //we check the min for each letter
    int minCost = INF, testCost;
    char base;
    loop(i, 0, alphabetSize){
        testCost = 0;
        base = i;
        for(char c : s){
            testCost += costPath[c-'A'][base];
        }
        minCost = min(minCost, testCost);
    }
    return minCost == INF? -1 : minCost;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    string s, edge;
    int k;
    loop(i, 0, t){
        cin>>s;
        cleanCostMatrix();
        cin>>k;
        loop(i, 0, k){
            cin>>edge;
            costPath[edge[0]-'A'][edge[1]-'A'] = 1;
        }
        floydWarshall();
        cout<<"Case #"<<(i+1)<<": "<<cost(s)<<"\n";    
    }
    return 0;
}