#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define loop(i, a, b) for(int i = a; i <b; ++i)

const int maxN = 1e6 + 5;
int n, arre[maxN];


void solve(){
    cin>>n;
    char bucket[27];
    fill(bucket, bucket +27, 0);
    string w[n];
    loop(i, 0, n){
        cin>>w[i];
        bucket[w[i][0]-'A'] = 1;
    }
    bool sePuede;
    loop(i, 0, n){
        sePuede = true;
        for(char x : w[i]){
            if(bucket[x-'A']==0)
                sePuede = false;
        }
        if(sePuede){
            cout<<"Y"<<endl;
            return;
        }
    }
    cout<<"N"<<endl;
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