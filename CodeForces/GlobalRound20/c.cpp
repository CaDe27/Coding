#include<iostream>
using namespace std;

int n; 
int arre[200005];
void solve(){
    int first, last;
    first = last = -1;
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>arre[i];
    }
    for(int i = 0; i < n-1; ++i){
        if(arre[i+1] == arre[i]){
            last = i;
            if(first == -1)
                first = i;
        }
    }
    if(first == last || first == -1){
        cout<<0<<endl;
    }
    else{
        cout<<max(1, (last-1 - (first+1) +1))<<endl;
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>>t;

    for(int i = 0; i < t; ++i){
        solve();
    }
}