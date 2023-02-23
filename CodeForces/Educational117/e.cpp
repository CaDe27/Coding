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
typedef pair<ll, ll> pll;


#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 200005;
int n, m;
int message[maxN], k[maxN];

pll probaMax = pll(0, 1); 
int indxMax = 0; 
vector<int> messagesResp; 

bool menorFrac(pll a, pll b){return a.first*b.second < b.first * a.second;}

int sumaKsM[maxN];
void especial(int p){
    fill(sumaKsM, sumaKsM + maxN, 0);
    loop(i, 0, n){
        sumaKsM[message[i]] += min(k[i], p);
    }
    priority_queue< int, vector<int>, greater<int> > minHeap;
    loop(i, 1, p+1){
        minHeap.push(sumaKsM[i]);
    }
    loop(i, p+1, maxN){
        if(minHeap.top() < sumaKsM[i]){
            minHeap.pop();
            minHeap.push(sumaKsM[i]);
        }
    }
    int denEsperanza = 0;
    while(!minHeap.empty()){
        denEsperanza += minHeap.top();
        minHeap.pop();
    }
    
    pll esperanza = pll(denEsperanza, p);
    if( menorFrac(probaMax, esperanza)){
        probaMax = esperanza;
        indxMax = p;
    }
}

void llenaMsgs(){
    int p = indxMax;
    fill(sumaKsM, sumaKsM + maxN, 0);
    loop(i, 0, n){
        sumaKsM[message[i]] += min(k[i], p);
    }
    priority_queue< pii, vector<pii>, greater<pii> > minHeap;
    loop(i, 1, p+1){
        minHeap.push(pii(sumaKsM[i], i));
    }
    loop(i, p+1, maxN){
        if(minHeap.top().first < sumaKsM[i]){
            minHeap.pop();
            minHeap.push(pii(sumaKsM[i], i));
        }
    }
    while(!minHeap.empty()){
        messagesResp.push_back(minHeap.top().second);
        minHeap.pop();
    }
}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n;
    loop(i, 0, n){
        cin>>message[i]>>k[i];
    }
    
    //para los primeros 19
    loop(i, 1, 19){
        especial(i);
    }

    fill(sumaKsM, sumaKsM + maxN, 0);
    loop(i, 0, n){
        sumaKsM[message[i]] += k[i];
    }

    vector<pii> sumas(maxN);
    loop(i, 1, maxN)
        sumas[i] = pii(sumaKsM[i], i);  
    sort(sumas.begin(), sumas.end(), greater<pii>());
    ll denEsp = 0;
    loop(i, 0, 19)
        denEsp += sumas[i].first;
    pll esp;
    loop(i, 19, maxN){
        denEsp += sumas[i].first;
        esp = pll(denEsp, i+1);
        if( menorFrac(probaMax, esp)){
            probaMax = esp;
            indxMax = i+1;
        }
    }


    if(indxMax < 20){
        llenaMsgs();
    }
    else{
        loop(i, 0, indxMax){
            messagesResp.push_back(sumas[i].second);
        }
    }
    int size = messagesResp.size();
    cout<<size<<"\n";
    cout<<messagesResp[0];
    loop(i, 1, size){
        cout<<" "<<messagesResp[i];
    }
    cout<<"\n";
    
    return 0; 
}
