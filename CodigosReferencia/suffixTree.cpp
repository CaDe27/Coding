// Given a string s, construct p array for suffix array

// Whats p array?
// p[i] stores the index of the i'th lexicographilly smaller suffix 
// p[0] = n+1 as its the empty suffix

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define loop(i, a, b) for(int i = a; i < b; ++i) 
typedef pair<int,int> pii;
typedef pair<pii, int> piii;

//it goes sorting first 2^k characters of each suffix 
// as k goes from 0 till 2^k < n
// it compares each 2^(k+1)-legth string taking advantaje of the 2^k string classes
// this is to make comparison in constant time

void pArray(string s, int n, int* p){
    //base case
    // create p and c (string class array)
    int c[n];
    pair<char, int> a[n];
    
    //create <arrays, position> array
    //sort array
    // assign p and classes
    loop(i, 0, n)
        a[i] = pair<char, int> (s[i], i);

    sort(a, a+n);

    //assings p
    loop(i, 0, n)
        p[i] = a[i].second;

    //assings classes
    c[p[0]] = 0;
    loop(i, 1, n)
        c[p[i]] = a[i].first == a[i-1].first? c[p[i-1]] : c[p[i-1]] + 1;


    int k = 0;
    //transition from k to k+1
    //same procedure
    // initialize a - array
    //sort
    //assing p
    //assing c
    while( (1<<k) < n){
        piii a[n];
        loop(i, 0, n){
            //pair< clase del string, posicion >
            a[i] = piii( pii(c[i], c[ (i+(1<<k))%n ]), i);
        }
        
        sort(a, a+n);
        //assings p
        p[0] = a[0].second;
        loop(i, 0, n)
            p[i] = a[i].second;

        //assings classes
        c[p[0]] = 0;
        loop(i, 1, n)
            c[p[i]] = a[i].first == a[i-1].first? c[p[i-1]] : c[p[i-1]] + 1;

        ++k;
    }
}

int main(){
    string s;
    cin>>s;
    s+="$";
    int n = s.size();

    int p[n];
    pArray(s, n, p);
    for(int i = 0; i < n; ++i)
        cout<<p[i]<<" ";
    cout<<"\n"; 
    return 0;
}

