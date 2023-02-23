#include <iostream>
#include <stack>
#define loop(i, a, b) for(int i = a; i < b; ++i)
#define MOD 1000000007
using namespace std;

typedef int64_t ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;

const int maxR = 1005, maxC = 1005;
char mat[maxR][maxC];
bool vis[maxR][maxC];
string alf = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int r, c;
int empieza(int i, int j){
    stack<piii> pila;
    pila.push(piii(pii(i,j),1));
    int resp = 1;
    while(!pila.empty()){
        int f, l, miResp;
       
        f = pila.top().first.first; l= pila.top().first.second;
        miResp = pila.top().second;
        pila.pop();

        if(vis[f][l]) continue;
        
        vis[f][l] = 1;
        resp = max(resp, miResp);
        if(mat[f][l] == 'Z') continue;
        for(int x= -1; x <2; ++x)
        for(int y= -1; y< 2; ++y){
            if( f + x > -1 && f+x < r && 
                l + y > -1 && l+y < c &&
                !vis[f+x][l+y] &&  mat[f+x][l+y] == alf[mat[f][l]-'A'+1]){
                    pila.push(piii(pii(f+x, l+y), miResp +1));
                }
        }
    }
    return resp;
}

void solve(){
    cin>>r>>c;
    loop(i,0,r)
    loop(j,0, c){
        vis[i][j] = 0;
        cin>>mat[i][j];
    }   

    int resp = 0;
    for (char carac : alf){ 
        loop(i,0, r){
        loop(j,0, c){
            if(mat[i][j] == carac && !vis[i][j]){
                resp = max(resp, empieza(i, j));
                //cout<<c<<" "<<i<<" "<<j<<" "<<resp<<endl;
            }
        }
        }
    }
    cout<<resp<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    loop(i, 0, t){
        solve();
    }
}