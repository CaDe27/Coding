#include <iostream>
using namespace std;
typedef int64_t ll;

int main(){
    ll n, m; 
    cin>>n>>m;

    int limit = 1;
    bool foundLimit = false;
    ll powers[3985];
    powers[1] = 1;
    int power;
    while(!foundLimit){
        ++limit;
        power = 1;

        powers[limit] = 1;
        while( power < n && m/powers[limit] >= limit){
            powers[limit] *= limit;
            power += 1;
        }
        
        if(power == n && power
    }
    
    ll pResp, qResp;
    bool found = false;
    for(ll q = 2; !found && q <= limit ; ++q){
        for(ll p = 1; !found && p < q; ++p){
            if (m % (powers[q] - powers[q-p]) == 0){
                 pResp = p;
                 qResp = q;
                 found = true;
            }
        }
    }
    if(!found){
        cout<<"impossible\n";
    }
    else{
        cout<<pResp<<" "<<qResp<<"\n";
    }
    return 0;
}