class Solution {
    vector<int> dp;
public:

    int f(int idx, vector<int>& cost){
        if(idx >= cost.size()){
            return 0;
        }
        if(dp[idx] != -1)
           return dp[idx];

        int l = cost[idx] + f(idx +2,cost);
        int r = cost[idx] + f(idx + 3,cost);
        
        return dp[idx] = max(l,r);
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
           return nums[0];
        
        dp.resize(nums.size(),-1);
        return max(f(0,nums), f(1,nums));

    }
};
