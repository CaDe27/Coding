#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int n; cin>>n;
    int64_t resp = 0;
    n<<=1;
    vector<pair<int,int> > numbers(2*n);

    for(int i = 0, a, b; i < n; ++i){
        cin>>a>>b;
        numbers[i] = make_pair(a, i);
        numbers[n+i] = make_pair(b, i);
    }
    sort(numbers.begin(), numbers.end());
    int remainingPairs = n;
    bool visited[n];
    fill(visited, visited + n, 0);
    int leftIt=0, rightIt = 2*n-1;
    while(remainingPairs > 0){
        while (visited[numbers[leftIt].second])
            ++leftIt;
        while (visited[numbers[rightIt].second])
            --rightIt;  
        resp += numbers[rightIt].first - numbers[leftIt].first; 
        visited[numbers[rightIt].second] = visited[numbers[leftIt].second] = true;
        remainingPairs -= 2;
    }
    cout<<resp<<"\n";

    return 0;
}
