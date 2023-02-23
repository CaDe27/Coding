#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define loop(i, a, b) for(int i = a; i <b; ++i)

const int maxN = 1e6 + 5;
int n, arre[maxN];
typedef pair<int, int> pii;
typedef int64_t ll;
vector< pair<int, int > > tasks;

ll dura[maxN];

void solve(){
    cin>>n;
    int a, b;
    tasks.resize(n);
    ll sumaT = 0; 
    loop(i, 0, n){
        cin>>a>>b;
        tasks[i] = pii(b, i);
        dura[i] = a; 
    }

    sort(tasks.begin(), tasks.end());
    vector<ll> suma(n);
    suma[0] = dura[tasks[0].second];
    loop(i, 1, n){
        suma[i] = suma[i-1] + dura[tasks[i].second];
    }   

    loop(i, 0, n){
        sumaT += dura[tasks[i].second];
        if(sumaT > tasks[i].first){
            cout<<"*"<<endl;
            return;
        }
    }

    vector<int> resp(n);
    int mP;
    ll mD;
    int actI;
    for(int z = 0; z < n; ++z){ 
        mP = tasks[0].second;
        mD = tasks[0].first-suma[0];
        actI = 0;
        for(int i = 1;i< tasks.size(); ++i){
            if(tasks[i].second < mP && mD >= dura[tasks[i].second]){
                mP = tasks[i].second;
                actI = i;
            }
            mD = min(mD, tasks[i].first-suma[i]);
        }

        resp[z] = mP;
        for(int i = actI; i < tasks.size()-1; ++i){
            tasks[i] = tasks[i+1];
        }
        tasks.resize(tasks.size()-1);
        for(int i = 0; i < actI; ++i){
            suma[i] += dura[mP];
        }
        for(int i = actI; i < suma.size() -1; ++i){
            suma[i] = suma[i+1];
        }
        suma.resize(suma.size()-1);

    }
    cout<<resp[0]+1;
    for(int i = 1; i <n; ++i)
        cout<<" "<<(resp[i]+1);
    cout<<endl;


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