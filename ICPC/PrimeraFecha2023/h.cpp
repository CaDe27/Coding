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

const int maxN = 100005;
int n;
string words[maxN];
vector<int> finishOneBefore[maxN];
ll dp[maxN];

int nll[200004];


//======= Ahocorasick================
const int K = 26;

struct Vertex {
    int next[K];
    bool leaf = false;
    int wordLeaf;
    int parent = -1;
    char parentCharacter;
    int link = -1;
    int go[K];

    Vertex(int parent=-1, char ch='$') : parent(parent), parentCharacter(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> automatonNodes(1);

void add_string(int indx, string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (automatonNodes[v].next[c] == -1) {
            automatonNodes[v].next[c] = automatonNodes.size();
            automatonNodes.emplace_back(v, ch);
        }
        v = automatonNodes[v].next[c];
    }
    automatonNodes[v].leaf = true;
    automatonNodes[v].wordLeaf = indx;
}

int go(int v, char ch);

int get_link(int v) {
    if (automatonNodes[v].link == -1) {
        if (v == 0 || automatonNodes[v].parent == 0)
            automatonNodes[v].link = 0;
        else
            automatonNodes[v].link = go(get_link(automatonNodes[v].parent), automatonNodes[v].parentCharacter);
    }
    return automatonNodes[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (automatonNodes[v].go[c] == -1) {
        if (automatonNodes[v].next[c] != -1)
            automatonNodes[v].go[c] = automatonNodes[v].next[c];
        else
            automatonNodes[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return automatonNodes[v].go[c];
} 
//======= Ahocorasick================

//from the sequence of links from me, give me the first one that is
// a leaf, or zero
int nextLeafLink(int id){
    if(id == 0 || get_link(id) == 0)
        return 0;
    if(nll[id] == -1){
        int gl = get_link(id);
        if(automatonNodes[gl].leaf)
            nll[id] = gl;
        else
            nll[id] = nextLeafLink(gl);
    }
    return nll[id];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    cin>>n;
    loop(i, 0, n){
        cin>>words[i];
        add_string(i, words[i]);
    }

    fill(nll, nll + automatonNodes.size(), -1);
    nll[0] = 0;
    //we process the given string to get all indexes 
    //where a word from the list fits 
    string given; 
    cin>>given;
    given += "$";

    int it = 0, itLeafs;
    loop(i, 0, given.size()-1){
        it = go(it, given[i]);
        itLeafs = automatonNodes[it].leaf? it : nextLeafLink(it);
        while(itLeafs != 0){
            finishOneBefore[i+1].push_back(automatonNodes[itLeafs].wordLeaf);
            itLeafs = nextLeafLink(itLeafs);
        }
    }

    dp[given.size()-1] = 1;
    int otherIndex;
    for(int i = given.size()-1; i >= 0; --i){
        for(int v : finishOneBefore[i]){
            otherIndex = i - words[v].size();
            dp[otherIndex] = (dp[otherIndex] + dp[i])%MOD;
        }
    }
    cout<<dp[0]<<"\n";
    return 0;
}