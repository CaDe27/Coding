#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define loop(i, a, b) for(int i = a; i <b; ++i)
typedef int64_t ll;
typedef pair<int, int> pii;

const int maxN = 1e6 + 5;
int n, arre[maxN];
ll INF = (1LL<<60);


void solve(){
    int x,n; cin >> x >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    ll b[n+1];
    b[0] = 0;
    for(int i=0;i<n;i++){
        b[i+1] = b[i]+a[i];
    }

    int A[n+1];
    //estado <numero, indice>
    stack<pair<ll, int>> stackA;
    stackA.push( make_pair((-INF),n+1));
    for(int i= n; i>= 0; --i){
        while(!stackA.empty() && stackA.top().first >= b[i])
            stackA.pop();
        A[i] = stackA.top().second;
        stackA.push(make_pair(b[i], i));
    }

    int N[n];

    for(int i=0;i<n;i++){
        N[i] = A[i]-i-1;
    }

    ll C[n+1];
    C[0] = 0;
    for(int i = 1; i<= n; i++){
        C[i] = b[i]-x;
    }

    const int m = 21;
    ll ST[n+1][m];

    
    for(int i=0;i<=n;i++){
         ST[i][0] = C[i];
    }


     for(int j=1;j<m;j++){
        for(int i=0;i+(1<<(j-1))<=n;i++){
            ST[i][j] = min(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
        }
    }


    int L[n+100];
    L[1] = 0;
    for(int i=2;i<=n+50;i++){
        L[i] = L[i/2]+1;
    }

    // min(ST[a][L[b-a+1]],ST[b-(1<<L[b-a+1])+1][L[b-a+1]])
    
    int M[n];

    for(int i=0;i<n;i++){
        ll q = b[i];

        if(min(ST[i+1][L[n-i-1+1]],ST[n-(1<<L[n-i-1+1])+1][L[n-i-1+1]]) >= q){
            M[i] = n-i;
        }
        else if(i<n && C[i+1] < q){
            M[i] = 0;
        }
        else{
            int lo = i+1; // >= q
            int hi = n; //min(i+1,n) < q 
            while(hi > lo+1){
                int g = (lo+hi)/2;
                if(min(ST[i+1][L[g-i-1+1]],ST[g-(1<<L[g-i+1])+1][L[g-i-1+1]]) >= q){
                    lo = g;
                }
                else{
                    hi = g;
                }
            }
            M[i] = hi-i-1;
        }
    }

    ll K[n],Q[n];

    K[0] = 0;
    for(int i=1;i<n;i++){
        K[i] = K[i-1] + M[i];
    }

    Q[n-1] = N[n-1];

    for(int i=n-2;i>=0;i--){
        Q[i] = Q[i+1] + N[i];
    }

    ll ans = 0;

    for(int i=0;i<=n-2;i++){
        ans = max(ans,K[i]+Q[i+1]);
    }

    ans = max(ans,K[n-1]);
    ans = max(ans,Q[0]);


    cout << ans << "\n";









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