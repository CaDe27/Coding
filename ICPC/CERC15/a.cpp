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

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 100005;

void solve(){
    map<string, ll> nums1;
    map<ll, string> nums2;
    nums1["xxxxxx...xx...xx...xx...xx...xxxxxx"]=0;
    nums2[0]="xxxxxx...xx...xx...xx...xx...xxxxxx";
    nums1["....x....x....x....x....x....x....x"]=1;
    nums2[1]="....x....x....x....x....x....x....x";
    nums1["xxxxx....x....xxxxxxx....x....xxxxx"]=2;
    nums2[2]="xxxxx....x....xxxxxxx....x....xxxxx";
    nums1["xxxxx....x....xxxxxx....x....xxxxxx"]=3;
    nums2[3]="xxxxx....x....xxxxxx....x....xxxxxx";
    nums1["x...xx...xx...xxxxxx....x....x....x"]=4;
    nums2[4]="x...xx...xx...xxxxxx....x....x....x";
    nums1["xxxxxx....x....xxxxx....x....xxxxxx"]=5;
    nums2[5]="xxxxxx....x....xxxxx....x....xxxxxx";
    nums1["xxxxxx....x....xxxxxx...xx...xxxxxx"]=6;
    nums2[6]="xxxxxx....x....xxxxxx...xx...xxxxxx";
    nums1["xxxxx....x....x....x....x....x....x"]=7;
    nums2[7]="xxxxx....x....x....x....x....x....x";
    nums1["xxxxxx...xx...xxxxxxx...xx...xxxxxx"]=8;
    nums2[8]="xxxxxx...xx...xxxxxxx...xx...xxxxxx";
    nums1["xxxxxx...xx...xxxxxx....x....xxxxxx"]=9;
    nums2[9]="xxxxxx...xx...xxxxxx....x....xxxxxx";
    nums1[".......x....x..xxxxx..x....x......."]=10;
    nums2[10]=".......x....x..xxxxx..x....x.......";

    //leo 
    string lines[7];
    loop(i, 0, 7)
        cin>>lines[i];
    
    string act;
    int limit = 0;
    loop(i, 0, 7)
        act += lines[i].substr(limit, 5);
    limit = 5+1;
    ll a = 0, b=0;
    
    while(nums1[act] != 10){
        a = 10*a + nums1[act];
        
        act.clear();
        loop(i, 0, 7)
            act += lines[i].substr(limit, 5);
        limit += 6;
        
    }

    while(limit < lines[0].size()){
        act.clear();
        loop(i, 0, 7)
            act += lines[i].substr(limit, 5);
        limit += 6;
        b = 10*b + nums1[act];
    }
   ;
    ll res = a+b, digit;
    string result[7];

    digit = res%10;
    res /=10;
    string t = nums2[digit];
    loop(i, 0, 7)
        result[i] = t.substr(i*5, 5);
    
    while( res > 0){
        digit = res % 10;
        res /=10;
        t = nums2[digit];
        loop(i, 0, 7)
            result[i] = t.substr(i*5, 5)+"."+result[i];
        
    }
    loop(i, 0, 7)
        cout<<result[i]<<"\n";
    

}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}
