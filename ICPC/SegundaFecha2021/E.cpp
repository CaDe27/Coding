#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("nombre.in", "r", stdin);
    //freopen("nombre.out", "w", stdout);
    int N; string c;
    cin>>N>>c;
    ll cap=stoi(c.substr(0,c.size()-1));
    ll a[N];

    if(c[c.size()-1]=='G'){
        cap*=1024;
    }
    if(c[c.size()-1]=='T'){
        cap*=(1024*1024);
    }

    for(int i=0; i<N; i++){
        cin>>a[i];
    }

    ll acum=0;
    int right=0;
    int rs[N];

    for(int i=0; i<N; i++){
        while(acum<=cap-a[right] && right<N){
            acum+=a[right];
            right++;
        }
        rs[i]=right-i;
        acum-=a[i];
    }

    int R=N;

    int minimo=rs[0];
    while(R>0){
        if(minimo>=R){
            break;
        }
        R--;
        minimo=min(minimo,rs[N-R]);
    }

    int L=-1;

    int k=0;
    while(k<N-R){
        if(rs[k]==R){
            L=k+1;
            break;
        }
        k++;
    }

    cout<<R<<" "<<L<<"\n";

    return 0;
}
