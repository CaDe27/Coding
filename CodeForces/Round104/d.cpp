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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int a1,a2,a3,a4;
    cin>>a1>>a2>>a3>>a4;
    if(abs(a3-a4) > 1){
        cout<<"-1\n";
        return 0;
    }
    else{
        string resp = "";
        if(a3 == a4+1 && a1 >= a3 && a2 >= a3){
            loop(i, 0, a1-a3){
                resp.append("4");
            }
            loop(i, 0, a3){
                resp.append("47");
            }
            loop(i, 0, a2-a3){
                resp.append("7");
            }
            cout<<resp<<"\n";
        }
        else if(a4 == a3+1 && a1 >= a4 && a2 >= a4){
            resp = "7";
            loop(i, 0, a1 - a4)
                resp.append("4");
            resp.append("4");
            loop(i, 0, a4-2){
                resp.append("74");
            }
            resp.append("7");
            loop(i, 0, a2-a4){
                resp.append("7");
            }
            resp.append("4");
            cout<<resp<<"\n";
        }
        else if(a4 == a3){
            if(a1 >= a4+1 && a2 >= a4){
                loop(i, 0, a1 - (a4+1) )
                    resp.append("4");
                loop(i, 0, a4){
                    resp.append("47");
                }
                loop(i, 0, a2-a4){
                    resp.append("7");
                }
                resp.append("4");
                cout<<resp<<"\n";
            }
            else if(a2 >= a4+1 && a1 >= a4){
                resp.append("7");
                loop(i, 0, a1-a4){
                    resp.append("4");
                }
                resp.append("4");
                loop(i, 0, a4-1)
                    resp.append("74");
                loop(i, 0, a2 - a4){
                    resp.append("7");
                }
                cout<<resp<<"\n";
            }
            else{
                cout<<"-1\n";
            }
        }
        else{
            cout<<"-1\n";
        }
        
    }

    return 0;
}