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
#include <fstream>

using namespace std;

typedef int64_t ll;

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define MINF -1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(ll i = a; i < b; ++i)

const int maxP = 1e6+10;
int n, m;



void solve(){
   
}

int aInt(string x){
    int resp = 0;
    for(char c:x)
        resp = resp*10 + (c-'0');
    return resp;
}

string sumTiempo(string x, int s, int mili){
    int milX=aInt(x.substr(9,3));
    int mil = mili;

    int seg= s;
    int segX=aInt(x.substr(6,2));

    int minuteX=aInt(x.substr(3,2));
    int hourX=aInt(x.substr(0,2));

    if(mil+milX>999){
        segX+=1;
    }
    milX=(mil+milX)%1000;
    if(segX+seg>59){
        minuteX+=1;
    }
    segX=(segX+seg)%60;

    if(minuteX>59){
        hourX+=1;
    }
    minuteX %= 60;

    string hX = to_string(hourX), mX = to_string(minuteX), sX = to_string(segX), miliX = to_string(milX);
    while(hX.size() < 2)
        hX = "0" + hX;

    while(mX.size() < 2)
        mX = "0" + mX;  

    while(sX.size() < 2)
        sX = "0" + sX;  

    while(miliX.size() < 3)
        miliX = "0" + miliX;    

    return hX+":"+mX+":"+sX+","+miliX;
    //00:00:00,000
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n;
    int s, milis;
    string delay;
    cin>>delay;
    bool band = false;
    s = milis = 0;
    for(char c : delay){
        if(c == '.') {
            band = true;
            continue;
        }
        if(!band){
            s = 10*s + c-'0';
        }else{
            milis = 10*milis + c-'0';
        }
    }

    string indx, lnum, linea;
    loop(i, 0, n){
        cin>>indx;
        cout<<indx<<"\n";

        cin>>lnum;
        lnum = sumTiempo(lnum, s, milis);
        cout<<lnum;
        
        cin>>linea;
        cout<<" "+linea+" ";

        cin>>lnum;
        lnum = sumTiempo(lnum, s, milis);
        cout<<lnum<<"\n";

        
        getline(cin, indx);
        getline(cin, indx);
        cout<<indx<<"\n";

        if(i != n-1){
            getline(cin, indx);
            cout<<indx<<"\n";
            if(indx.size() > 0){ 
                getline(cin, indx);
                cout<<indx<<"\n";
            }
        }
        else{
            string x2;
            getline(cin, x2);
            if(x2.size() > 0)
                cout<<x2<<"\n";
        }
    }
    
    return 0;

}
/*
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}*/