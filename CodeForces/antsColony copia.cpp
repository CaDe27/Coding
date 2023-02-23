/*
    only the ants that have the min stregth can divide all others
    if a divides b, then |a| <= |b|
    also, dividing a whole segment is equivalent to dividing the gcd of the interval

    then, you just have to query the min value of a segment, the
    gcd of the interval, and if the min does divide the gcd, save
    all of the min values in the interval

    I used a Segment Tree to make queries log^2 (N) time

*/

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

using namespace std;

typedef int64_t ll;

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define INF 1000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define loopi(i,a,b) for(int i = a; i <= b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)
#define invli(i,a,b) for(int i = a; i >= b; --i)


const int maxN = 100005;

//gets the greatest common divisor of two numbers
int gcd(int a, int b){
    if(a == 0)
        return b;
    else
        return gcd(b%a, a);
}


int s[maxN];
int lft[4*maxN+1], rght[4*maxN+1], mcd[4*maxN+1], mini[4*maxN+1], cantMini[4*maxN+1]; 
    
//procedure to initiliaze segment tree
void init(int i, int a, int b){
    lft[i] = a;
    rght[i] = b;
    if(a==b){
        mini[i] = s[a];
        cantMini[i] = 1;
        mcd[i] = s[a];
    } 

    else{
        int m = (a+b)/2;
        init(2*i, a, m);
        init(2*i+1, m+1, b);

        mini[i] = min(mini[2*i], mini[2*i+1]);
        if(mini[i] == mini[2*i+1])
            cantMini[i] +=  cantMini[2*i+1];
        if(mini[i] == mini[2*i])
            cantMini[i] +=  cantMini[2*i];
        mcd[i] = gcd(mcd[2*i], mcd[2*i+1]);
    }
    
}

//queries the minimum strength on the interval [a, b]
int queryMin(int i, int a, int b){
    if(rght[i] < a || lft[i] > b)
        return INF;
    
    if(a <= lft[i] && rght[i] <= b)
        return mini[i];
    
    else{
        int leftM = queryMin(2*i, a, b);
        int rightM = queryMin(2*i+1, a, b);
        return min(leftM, rightM);
    }

}

//queries the gcd of all strengths on the interval
int queryMcd(int i, int a, int b){
    if(rght[i] < a || lft[i] > b)
        return 0;
    
    if(a <= lft[i] && rght[i] <= b)
        return mcd[i];
    
    else{
        int leftM = queryMcd(2*i, a, b);
        int rightM = queryMcd(2*i+1, a, b);
        return gcd(leftM, rightM);
    }
}

//queries for the total amount of min streghts on the interval [a,b]
int queryCantMin(int i, int minQ, int a, int b){
    if(rght[i] < a || lft[i] > b)
        return 0;
    
    if(a <= lft[i] && rght[i] <= b)
        return minQ == mini[i]? cantMini[i] : 0;
    
    else{
        int leftM = queryCantMin(2*i, minQ, a, b);
        int rightM = queryCantMin(2*i+1, minQ, a, b);
        return leftM + rightM;
    }
}


//returns the amount of ants eaten on the interval [a,b]
int antsEaten(int a, int b){
    int m = queryMin(1, a, b);
    int c = 0;
    int d = queryMcd(1, a, b);

    //if the minimum divides de gcd, we substract all ants with that
    //strength 
    if( m == d)
        c = queryCantMin(1, m, a, b);   

    return b-(a-1) -  c;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    loopi(i, 1, n)
        cin>>s[i];
    
    init(1, 1, n);
    
    int t; cin>>t;
    int l, r;
    loop(i, 0, t){
        cin>>l>>r;
        cout<<antsEaten(l, r)<<"\n";
    }

    
}

