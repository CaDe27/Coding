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

using namespace std;

typedef int64_t ll;
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)

const int maxN = 500005;
int n;
int a[maxN];

int sq;
ll aq[maxN];
int indxMax[maxN];
ll respQ[maxN];
stack<int> nums; 
ll answer(){
    ////cout<<"Query"<<endl;
    while(!nums.empty())
        nums.pop();
    iloop(i, sq-1, -1){
        while(!nums.empty() && aq[i] > aq[nums.top()])
            nums.pop();
            
        if(nums.empty())
            indxMax[i] = -1;
        else 
            indxMax[i] = nums.top();
        
        nums.push(i);
    }

    ll answer = 0;

    iloop(i, sq-1, -1){
        if(indxMax[i] == -1){
            respQ[i] = aq[i]* (sq - i);
            ////cout<<i<<" "<<respQ[i]<<endl;
        }
        else{
            respQ[i] = aq[i]*(indxMax[i] - i) + respQ[indxMax[i]];
            ////cout<<i<<" "<<respQ[i]<<endl;
        }
        answer += respQ[i];
        ////cout<<"Anwe "<<answer<<endl;;
    }
    return answer;
}

const int maxPot = 20;
int sparse[maxN][maxPot];
int logg[maxN];
void fillSparse(){
    logg[1] = 0;
    loop(i, 2, maxN)
        logg[i] = logg[i/2]+1;
    
    int mid;
    loop(indx, 0, n)
        sparse[indx][0] = indx;
    loop(i, 1, maxPot){
        loop(indx, 0, n){
            mid = min(n-1, indx+(1<<(i-1)));
            sparse[indx][i] = a[sparse[mid][i-1]] > a[sparse[indx][i-1]]? sparse[mid][i-1] : sparse[indx][i-1];
        }
    }
}
 
int leftMostQuery(int l, int r){
    int size = logg[r-l+1];
    int maxiL = sparse[l][size], maxiR = sparse[r-(1<<size)+1][size];
    return a[maxiR] > a[maxiL]? maxiR : maxiL;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n;
    loop(i, 0, n)
        cin>>a[i];
    fillSparse();

    int q; cin>>q;
    ll sumaIni;
    loop(i, 0, q){
        cin>>sq;
        sumaIni = 0;
        loop(j, 0, sq){
            int indx;
            cin>>indx;
            --indx;
            aq[j] = indx;
            sumaIni += a[indx];
        }

        //cout<<"Query "<<endl;
        loop(j, 0, sq-1){
            //cout<<aq[j]<<" "<<aq[j+1]<<" "<<leftMostQuery(aq[j], aq[j+1])<<endl;
            aq[j] = a[leftMostQuery(aq[j], aq[j+1])];
            //cout<<aq[j]<<" ";
        }
        --sq;
        //cout<<endl;
        cout<<sumaIni+answer()<<"\n";
    }
    return 0;
}