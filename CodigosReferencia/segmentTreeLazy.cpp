#include <iostream>
#include <algorithm>
#include <climits>

#define loop(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

const int maxN = 100000;
int n;



//for this tree:
//update uses increment on a certain segment 
   
//(for example, increment each index in segment [1,10] by 10 units)
//query uses min function

    /*
        if we are currently at index i representing segment [a,b]
        l   -   indicates left limit of the segment (a)
        r   -   indicates right limit of the segment (b)
        f   -   value of the function in segment [a, b]
        delta   -   stores lazy updates 
    */
    int l[4*maxN+1], r[4*maxN+1], f[4*maxN+1], delta[4*maxN+1]; 
    
    //procedure to initiliaze segment tree
    void init(int i, int a, int b){
        l[i] = a;
        r[i] = b;
        if(a==b) return;
        int m = (a+b)/2;
        init(2*i, a, m);
        init(2*i+1, m+1, b);
    }
    
    SegmentTree(int n){
        init(1, 1, n);
    }

    //function to lazy update children
    //it depends on lazy operation 
    void propagate(int i){
        cout<<"Progate method: must tell me which is the lazy operation"<<endl;
        //delta[2*i] += delta[i];
        //delta[2*i + 1] += delta[i];
        //delta[i] = 0;
    }

    void update(int i){
        cout<<"update method: must tell me which is the update operation"<<endl;
        //its now implemented with min
        //funct[i] =  min(funct[2*i] + delta[2*i], funct[2*i+1] + delta[2*i+1]);
    }

    
    void lazy(int i, int a, int b, int val){
        //if I'm totally out of the segment, don't do nothing
        if(b < left[i] || right[i] < a)
            return;
        
        //if I'm fully contained in the segment update my lazy
        //funct update is only made when you update children
        if( a<=left[i] && right[i]<=b ){
            //this may change depending on how update works on certain problem
            cout<<"lazy method: must tell me which is the lazy operation"<<endl;
            delta[i] += val;
            return;
        }
        
        //apply my lazy changes to my children and lazy update them 
        propagate(i);
        lazy(2*i, a, b, val);
        lazy(2*i+1, a, b, val);
        update(i);
        
    }


    void update(int a, int b, int val){
        lazy(1, a, b, val);
    }

    int query(int i, int a, int b){
        cout<<"update all returns and careful with overflows (int leftQ ...) "<<endl;
        if(b < left[i] || right[i] < a)
            return INT_MAX; 
        
        
        if(a <= left[i] && right[i] <= b)
            return funct[i] + delta[i];
        
        propagate(i);

        //BE CAREFUL with overflow
        int leftQ =  query(2*i, a, b);
        int rightQ = query(2*i+1, a, b);
        update(i);

        return min(leftQ, rightQ);
    }

    int query(int a, int b){
        return query(1, a, b);
    }

int main(){
    init(1, 1, 100);
}