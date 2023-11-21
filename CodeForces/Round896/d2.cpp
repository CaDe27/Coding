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
const int maxN = 2e5+5;
int n, a[maxN], give[40], receive[40], pgive[40], preceive[40];

void solve(){
    fill(give, give+40, 0);
    fill(receive, receive+40, 0);
    fill(pgive, pgive+40, 0);
    fill(preceive, preceive+40, 0);

    cin>>n;
    ll sum = 0;
    loop(i, 0, n){
        cin>>a[i];
        sum += a[i];
    }
    if(sum % n != 0){
        cout<<"NO\n";
        return;
    }
    
    int p = sum/n;
    loop(i, 0, n){
        int d = a[i] - p, g = 0, r = 0;
        if(d == 0) continue;
        if(d > 0){
            while(d%2 == 0){
                d/=2;
                ++r;
            }

            if(d != 1){
                d+=1;
                g = r;
                while(d%2 == 0){
                    d/=2;
                    ++g;
                }
                if(d != 1){
                    cout<<"NO\n";
                    return;
                }
                ++give[g];
                ++receive[r];
            }
            else{
                ++pgive[r];
            }
        }
        else{
            d = -d;
            while(d%2 == 0){
                d/=2;
                ++g;
            }
            if(d != 1){
                d+=1;
                r = g;
                while(d%2 == 0){
                    d/=2;
                    ++r;
                }
                if(d != 1){
                    cout<<"NO\n";
                    return;
                }
                ++give[g];
                ++receive[r];
            }
            else{
                ++preceive[g];
            }
        }
    }

    for(int i = 35; i > 0; --i){
        give[i] += pgive[i];
        receive[i] += preceive[i];

        if(give[i] != receive[i]){
            if(give[i] < receive[i]){
                pgive[i-1] -= receive[i] - give[i];
                receive[i-1] += receive[i] - give[i];

                if(pgive[i-1] < 0){
                    cout<<"NO\n";
                    return;
                }
            }   
            else{
                preceive[i-1] -= give[i] - receive[i];
                give[i-1] += give[i] - receive[i];
                if(preceive[i-1] < 0){
                    cout<<"NO\n";
                    return;
                }
            }
        }
    }
    
    give[0] += pgive[0];
    receive[0] += preceive[0];
    if(give[0] == receive[0])
        cout<<"YES\n";
    else
        cout<<"NO\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}