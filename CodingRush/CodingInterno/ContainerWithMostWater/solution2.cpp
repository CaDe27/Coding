#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int main(){
    int n; cin>>n;
    pii arre[n];
    for(int i = 0 ; i <n; ++i){
        cin>>arre[i].first;
        arre[i].second = i;
    }

    int indxMin = 1000000, indxMax = -1, resp = 0;
    sort(arre, arre+n);
    reverse(arre, arre+n);
    for(int i = 0; i < n; ++i){
        indxMin = min(indxMin, arre[i].second);
        indxMax = max(indxMax, arre[i].second);
        resp = max(resp, arre[i].first * (arre[i].second - indxMin));
        resp = max(resp, arre[i].first * (indxMax - arre[i].second));
    }
    cout<<resp<<"\n";
    return 0;
}
