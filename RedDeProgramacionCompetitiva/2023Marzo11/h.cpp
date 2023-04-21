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
typedef pair<ll,int> pli;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)

const int maxN = 5e5 + 5;
int n; 
int izq[maxN], der[maxN], repre[maxN];
ll spiciness[maxN];
priority_queue<pli, vector<pli>, greater<pli> > minHeap;

int representative(int a){
    if(repre[a] == a)  
        return a;
    else
        return repre[a] = representative(repre[a]);
}

void procesa(int currentRepre, ll costo){
    int nextLeft = (izq[currentRepre] - 1 + n) %n, 
        nextRight = (der[currentRepre] + 1)%n, otherRepre;
    while(  nextRight != izq[currentRepre]
            && 
            costo + spiciness[currentRepre] >= min(spiciness[representative(nextLeft)], spiciness[representative(nextRight)])
         ){
        
        if(spiciness[representative(nextLeft)] < spiciness[representative(nextRight)]){
            otherRepre = representative(nextLeft);
            spiciness[currentRepre] += spiciness[otherRepre];
            izq[currentRepre] = izq[otherRepre];
            repre[otherRepre] = currentRepre;
            nextLeft = (izq[currentRepre] - 1 + n) %n;
        }else{
            otherRepre = repre[nextRight];
            spiciness[currentRepre] += spiciness[otherRepre];
            der[currentRepre] = der[otherRepre];
            repre[otherRepre] = currentRepre;
            nextRight = (der[currentRepre] + 1)%n;
        }
    }
    //I couldn't eat any of the remaining
    if(nextRight != izq[currentRepre]){
        if(spiciness[nextRight] < spiciness[nextLeft]){
            minHeap.push(pli(spiciness[nextRight] - spiciness[currentRepre], currentRepre));
        }
        else{
            minHeap.push(pli(spiciness[nextLeft] - spiciness[currentRepre], currentRepre));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    
    cin>>n;
    loop(i, 0, n){
        repre[i] = i;
        izq[i] = der[i] = i;
    }

    loop(i, 0, n) {
        cin>>spiciness[i];
        minHeap.push(pli(spiciness[i], i));
    }

    int nextRepre, nextIndx;
    bool finished = false;
    ll costo, resp;
    while(!finished){
        nextIndx = minHeap.top().second;
        costo = minHeap.top().first;
        minHeap.pop();
        if(repre[nextIndx] == nextIndx){
            nextRepre = nextIndx;
            procesa(nextRepre, costo);
            if( (der[nextRepre] + 1)%n == izq[nextRepre] ){
                finished = true;
                resp = costo;
            }
        }   
    }
    cout<<resp<<"\n";

    return 0;
}