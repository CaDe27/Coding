#include <iostream>
#include <algorithm>
#include <climits>

#define loop(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

const int maxN = 5e5 + 5;
int n;

//query uses min function
    /*
        if we are currently at index i representing segment [a,b]
        l   -   indicates left limit of the segment (a)
        r   -   indicates right limit of the segment (b)
        f   -   value of the function in segment [a, b]

    */
    int l[4*maxN+1], r[4*maxN+1], f[4*maxN+1]; 
    
    //procedure to initiliaze segment tree
    void init(int i, int a, int b){
        l[i] = a;
        r[i] = b;
        if(a==b){
            f[i] = 0;
        } else{
            int m = (a+b)/2;
            init(2*i, a, m);
            init(2*i+1, m+1, b);
            f[i] = min(f[2*i], f[2*i+1]);
        }
    }
    
    SegmentTree(int n){
        init(1, 1, n);
    }

    void update(int a, int val){
        int i = 1;
        while(!(l[i]==a && r[i]==a)){
            if( a <= r[i<<1])
                i = i<<=1;
            else
                i = (i<<=1)+1;
        }
        f[i] = val;

        while(i != 1){
            f[i>>1] = i&1? min(f[i-1], f[i]) : min(f[i], f[i+1]);
            i>>=1;
        }
    }

    int query(int i, int a, int b){
        if(b < l[i] || r[i] < a)
            return INT_MAX; 
        
        if(a <= l[i] && r[i] <= b)
            return f[i];
        else{
            return min(query(2*i, a, b), query(2*i+1, a, b));
        }
    }

    int query(int a, int b){
        return query(1, a, b);
    }

int main(){
    init(1, 1, maxN);
}