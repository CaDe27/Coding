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
#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 200005;
int n; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    map<char, char> l;
    l.insert(make_pair('3', 'E'));
    l.insert(make_pair('0', 'O'));
    l.insert(make_pair('8', 'B'));
    l.insert(make_pair('1', 'I'));
    l.insert(make_pair('2', 'Z'));
    l.insert(make_pair('4', 'A'));
    l.insert(make_pair('5', 'S'));
    l.insert(make_pair('6', 'G'));
    l.insert(make_pair('7', 'T'));
    l.insert(make_pair('9', 'P'));

    int t; cin>>t;
    
    string s;
    getline(cin, s);
    loop(i, 0, t){
        getline(cin, s);
        for(int i = 0; i < s.size(); ++i){
            if('0' <= s[i] && s[i] <= '9')
                s[i] = l[s[i]];
        }
        cout<<s<<"\n";
    }
    return 0;

}