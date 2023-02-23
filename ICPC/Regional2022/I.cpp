#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#define loop(i, a, b) for(int i = a; i <b; ++i)

const int maxN = 1e6 + 5;
int n;
typedef int64_t ll;

int mod(ll c, ll d){
    return ((c-d)%7 + 7)%7;
}

int caso(int k, int d){
    int r = mod(k, d);
    if( r ==0){
        int a=d%91;
        if(a==0) return 0;
        if(a<31) return 30-a;
        if(a<61) return 60-a;
        if(a<91) return 91-a;
    }
    else if ( r==1)
    {   
        if(d<62){
            int a=d;
            if(a==0) return 0;
            if(a<31) return 30-a;
            if(a<62) return 62-a;
        }
        else{
            return (caso(k,d-62));
        }
    }
    else if ( r==2)
    {
        if(d<61){
            int a=d;
            if(a==0) return 0;
            if(a<31) return 30-a;
            if(a<61) return 61-a;
        }
        return(caso(k,d-61));
    }
    else if ( r==3)
    {
        if(d<32){
            return 32-d;
        }
        return(caso(k,d-32));
    }
    else if ( r==4)
    {
        if(d<31){
            return 31-d;
        }
        return(caso(k,d-31));
    }
    
    return -1;
    
    
}

void solve(){
    string s;
    cin>>s; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    if(s=="Mon") k=0;
    if(s=="Tue") k=1;
    if(s=="Wed") k=2;
    if(s=="Thu") k=3;
    if(s=="Fri") k=4;
    if(s=="Sat") k=5;
    if(s=="Sun") k=6;
    int mini=40;
    for(int i=0; i<n; i++){
        mini=min(mini,caso(k,arr[i]));
    }
    cout<<mini<<endl;
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