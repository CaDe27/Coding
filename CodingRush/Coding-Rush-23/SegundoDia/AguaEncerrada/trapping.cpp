#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int fin, vector<int>& height){
    int64_t resp = 0;
    if(fin <= 1) 
        return 0;

    int acum[height.size()];
    for(int i = 0; i <= fin; ++i){
        acum[i] = height[i];
        if(i > 0)
            acum[i] += acum[i-1];
    }

    int it, last = 0;
    while(last < fin){
        it = last + 1;
        while(height[it] < height[last])
            ++it;
        resp += height[last]*(it-1 - last); 
        resp -= acum[it-1] - acum[last];
        last = it;
    }
    return resp;
}

int trap(vector<int>& height) {
    int n = height.size();
    int resp = 0;
    int indxMax = 0;
    for(int i = 1; i < n; ++i)
        if(height[i] > height[indxMax])
            indxMax = i;

    int otraN = n - indxMax;
    vector<int> otro(n - indxMax);
    for(int i = indxMax; i < n; ++i)
        otro[otraN + indxMax - 1 - i] = height[i];

    resp += solve(indxMax, height);
    resp += solve(otraN-1, otro);
    return resp;
}


int main(){
    int n; cin>>n;
    vector<int> height(n);
    for(int i = 0; i < n; ++i){
        cin>>height[i];
    }
    cout<<trap(height)<<endl;
    
}
