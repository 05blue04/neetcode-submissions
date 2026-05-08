class Solution {
public:
    //pick indicates whether or not we have chosen the last house
    int f(int i, int pick, vector<int>& nums, vector<vector<int>>& dp){
        if(i == 0){
            if(pick)
                return 0;
            return nums[i];
        }

        if(i < 0)
            return 0;
        if(dp[pick][i] != -1)
            return dp[pick][i];

        int p = nums[i];
        if(i == nums.size() - 1){
            p += f(i - 2, 1, nums, dp);
        } else{
            p += f(i - 2, pick, nums, dp);
        }

        int np = f(i - 1, pick, nums, dp);

        return dp[pick][i] = max(p, np);
    }
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(nums.size(), -1));
        return f(nums.size() - 1, 0, nums, dp);
        
    }
};
