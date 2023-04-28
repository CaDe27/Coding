#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        //calculate dps
        for(int indx = n-1; indx>=0; --indx){
            dp[indx] = 1;
            for(int j = indx+1; j < n; ++j){
                if(nums[j] > nums[indx])
                    dp[indx] = max(dp[indx], 1+dp[j]);
            }
        }
        
        //resp is the maximum over dp array
        int resp = 0;
        for(int i = 0; i < n; ++i)
            resp = max(resp, dp[i]);

        return resp;
    }
};