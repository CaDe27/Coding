#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
#include <set>
#include <iomanip>
#define INF 1000000000000000000
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)
using namespace std;
typedef int64_t ll;
typedef pair<int,int> pii;
const int maxN = 105;
int n, m, numX = 0;
vector< vector<int> > paths;
int indxPaths[maxN*maxN];
vector< vector<char> > mat;

void generaPath(int a, int b){
    int indxPath = a*m +b;
    paths[indxPath].resize(numX);
    int markedX = 0, s = 0, cellsBeforeX = 1;

    if(mat[a][b] == 'X')
        paths[indxPath][markedX++]= 0;

    int i, j;
    while(markedX < numX){
        ++s;
        ////cout<<s<<endl;
        //de la ini a extremo derecho
        ////cout<<"arriba"<<endl;
        i = a-s;
        if(i >= 0 && i < n)
            for(j = b-s+1; j < b+s; ++j){
                if(0 <= j && j < m && mat[i][j] == 'X'){
                    ////cout<<"\tmarco en "<<i<<" "<<j<<endl;
                    paths[indxPath][markedX++] = cellsBeforeX + (j-(b-s+1)); 
                }
            }
        cellsBeforeX += 2*s-1; //b+s-(b-s+1)
        //de la derecha hacia abajo
        ////cout<<"derecha"<<endl;
        j = b+s;
        if(j >= 0 && j < m)
            for(i = a-s; i < a+s; ++i){
                if(0 <= i && i < n && mat[i][j] == 'X'){
                    ////cout<<"\tmarco en "<<i<<" "<<j<<endl;
                    paths[indxPath][markedX++] = cellsBeforeX + (i-(a-s)); 
                }
            }
        cellsBeforeX += 2*s; //a+s-(a-s)
        
        //de abajo derecha a izquierda 
        ////cout<<"abajo"<<endl;
        i = a+s;
        if(i >= 0 && i < n)
            for(j = b+s; j > b-s; --j){
                if(0 <= j && j < m && mat[i][j] == 'X'){
                    ////cout<<"\tmarco en "<<i<<" "<<j<<endl;
                    paths[indxPath][markedX++] = cellsBeforeX + ((b+s)-j); 
                }
            }
        cellsBeforeX += 2*s; //b+s-(b-s)

        //de izquierda hacia arriba
        ////cout<<"izq"<<endl;
        j = b-s;
        if(j >= 0 && j < m)
            for(i = a+s; i >= a-s; --i){
                if(0 <= i && i < n && mat[i][j] == 'X'){
                    ////cout<<"\tmarco en "<<i<<" "<<j<<endl;
                    paths[indxPath][markedX++] = cellsBeforeX + ((a+s)-i); 
                }
            }
        cellsBeforeX += 2*s + 1; //a+s-(a-s) + 1
    }
    ////cout<<"acabe "<<a<<" "<<b<<endl;
}

//it is guaranteed that two paths are always different 
bool comp(int a, int b){
    int i = 0; 
    while(paths[a][i] == paths[b][i])
        ++i;
    return paths[a][i] < paths[b][i];
}

int minIndxDifferent(int a, int b){
    int indx = 0;
    while(paths[a][indx] == paths[b][indx])
        ++indx;
    return min(paths[a][indx], paths[b][indx]);
}


int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>m>>n;
    
    mat.resize(n);
    loop(i, 0, n)
        mat[i].resize(m);

    loop(i, 0, n)
    loop(j, 0, m){
        cin>>mat[i][j];
        if(mat[i][j] == 'X') ++numX;
    }

    //generaCamino
    int totalSize = n*m;
    paths.resize(totalSize);
    loop(i, 0, n)
    loop(j, 0, m){
        generaPath(i, j);
    }
    
    //loop(i, 0, totalSize){
        //cout<<i<<" "<<i/m<<" "<<(i- (i/m)*m)<<": ";
    //    loop(j, 0, paths[i].size())
            //cout<<paths[i][j]<<" \n"[j==paths[i].size()-1];
    //}
    iota(indxPaths, indxPaths + totalSize, 0);
    sort(indxPaths, indxPaths + totalSize, comp);
    //cout<<"indxPaths: ";
    //loop(i, 0, totalSize)
        //cout<<indxPaths[i]<<" \n"[i==totalSize-1];
    
    //cout<<"indxPaths: ";
    //loop(i, 0, totalSize)
        //cout<<indxPaths[i]<<" \n"[i==totalSize-1];
    ////cout<<"acabe sort"<<endl;
    int need[totalSize], indxMax = -1;
    loop(i, 0, totalSize){
        need[indxPaths[i]] = 0;
        if(i > 0) need[indxPaths[i]] = minIndxDifferent(indxPaths[i], indxPaths[i-1]);
        if(i < totalSize-1) need[indxPaths[i]] = max(need[indxPaths[i]], minIndxDifferent(indxPaths[i], indxPaths[i+1]));
        if(indxMax == -1 || need[indxMax] < need[indxPaths[i]]) indxMax = indxPaths[i];
        ////cout<<"bueno "<<indxPaths[i]<<" "<<indxPaths[i]/m<<" "<<(indxPaths[i]- (indxPaths[i]/m)*m)<<": "<<need[indxPaths[i]]<<endl;
    }

    //cout<<"need: ";
    //loop(i, 0, totalSize)
    //    cout<<need[i]<<" \n"[i==totalSize-1];

    int totalIndxMax = 0;
    loop(i, 0, totalSize)
        if(need[indxMax] == need[i])
            ++totalIndxMax;
    ll sum = 0;
    loop(i, 0, totalSize)
        sum += need[i];
    cout<<fixed<<setprecision(4)<<sum/((long double) totalSize)<<"\n";
    cout<<need[indxMax]<<"\n";

    vector<pii> todos;
    loop(i, 0, totalSize){
        if(need[i] == need[indxMax]){
            int indxI = i/m, indxJ = i - (i/m)*m;
            int y = n - indxI, x = indxJ + 1;
            todos.push_back(pii(y, x));   
        }
    }

    sort(todos.begin(), todos.end());
    loop(i, 0, todos.size())
        cout<<"("<<todos[i].second<<","<<todos[i].first<<")"<<" \n"[i == todos.size() - 1];

    return 0;
}