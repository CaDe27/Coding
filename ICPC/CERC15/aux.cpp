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

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    loop(i, 0, 11){
    int t = 7;
    //int t; cin>>t;
    string s, res;
    loop(i, 0, t){
        cin>>s;
        if(i == 0)res = s;
        else res += s;
    }
       cout<<"nums1[\""<<res<<"\"]="<<i<<";"<<endl;
       cout<<"nums2["<<i<<"]=\""<<res<<"\";"<<endl;
    }
    return 0; 
}
