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
#include <unordered_map>

using namespace std;

typedef int64_t ll;
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 500005;
int n, q;
ll num[maxN];
bool deleted[maxN];
vector<pair<int, pii> > ops;
map<ll, int> mapeo;

ll bit[maxN];
void update(int pos, ll x){
    pos = mapeo[pos];
    while(pos < maxN){
        bit[pos] = bit[pos] + x;
        pos += pos&(-pos);
    }
}

ll query(int pos){
    pos = mapeo[pos];
    ll suma = 0;
    while(pos > 0){
        suma = suma + bit[pos];
        pos -= pos&(-pos);
    }
    return suma;
}

void coordinate_compression(){
    set<ll> elementos;
    loop(i, 0, q){
        if(ops[i].first == 1){ 
            num[i+1] = ops[i].second.first;
            elementos.insert(num[i+1]);
            elementos.insert(num[i+1]-1);
        }
        else if(ops[i].first == 3){
            
            int indx = ops[i].second.first, 
                x = ops[i].second.second;
            num[ops[i].second.first]+= x;
            elementos.insert(num[indx]); 
            //we are also using this number to query for the numbers less than num[indx] in the BIT
            elementos.insert(num[indx]-1); 
        }
    }
    
    int indx = 1;
    for(int x : elementos){
        mapeo[x] = indx;
        ++indx;
    } 
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    cin>>q;
    ops.resize(q);
    loop(i, 0, q){
        int op1, op2, op3;
        cin>>op1>>op2;
        if(op1 == 3) 
            cin>>op3;
        else
            op3 = 0;

        ops[i].first = op1;
        ops[i].second = pii(op2, op3);
    }

    coordinate_compression();

    int t, indx, x;
    loop(i, 0, q){
        t = ops[i].first;
        switch(t){
            case 1:
                x = ops[i].second.first;
                num[i+1] = x;
                update(x, 1);
                break;
            case 2:
                indx = ops[i].second.first;
                if(!deleted[indx]){
                    deleted[indx] = true;
                    update(num[indx], -1);
                }
                break;
            case 3:
                indx = ops[i].second.first;
                x = ops[i].second.second;
                update(num[indx], -1);
                num[indx] += x;
                update(num[indx], 1);
                break;
            case 4:
                indx = ops[i].second.first;
                cout<<query(num[indx]-1)<<"\n";
                break;
            default:
                break;
        }
    }
    return 0;
}