#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

void solve(int n, int m){
    int target = m;
    if(n > 1){
        cout<<"*\n";
        return;
    }


    queue<pair<int,vector<int> > > bfs;
    vector<int> camino, aux, resp;
    int number, son;
    camino.push_back(1);

    bfs.push(make_pair(1, camino));
    bool encontrado = false;
    while(!bfs.empty() && !encontrado){
        aux = bfs.front().second;
        number = bfs.front().first;

        bfs.pop();

        if(number == target){
            encontrado = true;
            resp = aux;
        }
        else{
            for(int i = 0; i < aux.size(); ++i){
                son = number + aux[i];
                if(son <= target ){
                    vector<int> sonV = aux;
                    sonV.push_back(son);
                    bfs.push(make_pair(son, sonV));
                }
            }
        }
    }
    for(int i = 1; i < resp.size(); ++i){
        cout<<"1 "<<resp[i-1]<<"\n";
        cout<<"1 "<<(resp[i] - resp[i-1])<<"\n"; 
    }
}

int main(){
    /*
    int n, m;
    cin>>n>>m;
    solve(n, m);
    return 0;
    */
   int n, m;
    for(int i = 2; i <= 100;++i)
        solve(1, i);
    return 0;
}