//as we can only jump twice, we check the furthest we can get
// from the beginning before reaching water and then land on the
// first piece of land that is connected to the end
// Challenge: solve with O(1) memory, that is, whithout the location array
 
#include <iostream>
#define LAND 1
#define WATER 0
using namespace std;
 
const int maxN = 100;
int n; 
int location[maxN];
void solveTestCase(){
    cin>>n;
    for(int i = 0; i < n; ++i)
        cin>>location[i];
    //we look for the furthest land before the first water
    //it has to be less than n-1 because you are going to ask if
    // the next position has land. That means, the next position needs to be valid
    // and less than n. 
    int indexFurthestLand = 0;
    while(indexFurthestLand < n-1 && location[indexFurthestLand + 1] == LAND)
        ++indexFurthestLand;
    
    //if we did reach water, we need to look for the closest land connected to the end
    int indexClosestLand = n-1;
    if(indexFurthestLand != n-1){
        //we don't need to worry for the index being valid because we know 
        //theres water at some place
        while(location[indexClosestLand-1] != WATER)
            --indexClosestLand;
    }
    int cost = indexClosestLand - indexFurthestLand;
    cout<<cost<<"\n";
 
}
 
int main(){
    int testCases; 
    cin>>testCases;
 
    for(int i = 0; i < testCases; ++i){
        solveTestCase();
    }
}