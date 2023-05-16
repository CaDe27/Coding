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

const int maxN = 3e6+5;
int n, q;
vector<pair<int, pii> > queries;
vector<int> originalCollection;
set<int> collection;
unordered_map<int, int> newIndx;

ll bit[maxN];
void update(int pos, ll x){
    while(pos < maxN){
        bit[pos] = bit[pos] + x;
        pos += pos&(-pos);
    }
}

ll queryBIT(int pos){
    ll suma = 0;
    while(pos > 0){
        suma = suma + bit[pos];
        pos -= pos&(-pos);
    }
    return suma;
}

ll queryBIT(int pos1, int pos2){
	return queryBIT(pos2) - queryBIT(pos1-1);
}

void readCollectionAndQueries(){
    cin>>n>>q;
    originalCollection.resize(n);
    loop(i, 0, n)
        cin>>originalCollection[i];
    
    queries.resize(q);
    loop(i, 0, q){
        cin>>queries[i].first;
        if(queries[i].first == 1)
            cin>>queries[i].second.first;
        else
            cin>>queries[i].second.first>>queries[i].second.second;
    }
}


void coordinateCompression(){
    set<int> allIntegers;
    for(int i : originalCollection)
        allIntegers.insert(i);
    for (auto q : queries){
        if(q.first == 1)
            allIntegers.insert(q.second.first);
        else{
            allIntegers.insert(q.second.first);
            allIntegers.insert(q.second.second);
        }
    }
    //ya tengo el set con todos los numeros ordenados
    //
    int i = 1;
    for(int x : allIntegers){
        newIndx[x] = i;
        ++i;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    readCollectionAndQueries();
    coordinateCompression();

    for(int x : originalCollection){
        collection.insert(newIndx[x]);
        update(newIndx[x], 1);
    }

    int elem;
    loop(i, 0, q){
        if(queries[i].first == 1){
            elem = newIndx[queries[i].second.first];
            auto it = collection.lower_bound(elem);
            if(*it == elem)
                continue;
            else if(it == collection.end()){
                collection.insert(elem);
                update(elem, 1);
            }
            else{
                collection.insert(elem);
                update(*it, -1);
                update(elem, 1);
            }
        }
        else{
            cout<<queryBIT(newIndx[queries[i].second.first],
                        newIndx[queries[i].second.second])<<"\n";
        }
    }

    return 0;
}