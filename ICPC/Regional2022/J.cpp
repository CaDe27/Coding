#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define loop(i, a, b) for(int i = a; i <b; ++i)

const int maxN = 1e6 + 5;
int n, arre[maxN];

int W,H;
bool border(int x, int y){
    return (x == 0 || x == W) || (y == 0 || y == H);
}


void solve(){
    cin >> W >> H;
    int n; cin >> n;

    vector<vector<int>> P;

    for(int i =0; i<n; i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(border(x1,y1) && border(x2,y2)){
            P.push_back({x1,y1,i});
            P.push_back({x2,y2,i});
        }
    }
    vector<vector<int>> V[4];

    for(auto p:P){
        if(p[0] == 0){
            V[0].push_back(p);
        }
        else if(p[2] == W){
            V[2].push_back(p);
        }
        else if(p[1] == H){
            V[1].push_back(p);
        }
        else{
            V[3].push_back(p);
        }
    }

    for(int i=0;i<4;i++){
        sort(V[i].begin(),V[i].end());
    }
    for(int i=2;i<4;i++){
        reverse(V[i].begin(),V[i].end());
    }

    stack<int> S;
    int visited[n];
    for(int i=0;i<n;i++){
        visited[i] = 0;
    }

    string ans = "Y\n";

    for(int i=0;i<4;i++){
        for(auto p:V[i]){
            int k = p[2];
            if(!visited[k]){
                visited[k] = 1;
                S.push(k);
            }
            else{
                if(!S.empty() && S.top() == k){
                    S.pop();
                }
                else{
                    ans = "N\n";
                }
            }

        }
    }

    cout << ans;


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1; //cin>>t;
    loop(i, 0, t){
        solve();
    }   
    return 0;

}