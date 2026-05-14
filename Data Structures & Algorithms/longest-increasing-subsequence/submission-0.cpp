class Solution {
    vector<vector<int>> dp;
public:

    int f(int i, int prev, vector<int>& nums){
        if(i == nums.size())
           return 0;
        if(dp[i][prev+1] != -1)
           return dp[i][prev+1];

        int len = f(i+1,prev,nums);

        if(prev == -1 || nums[i] > nums[prev]){
            len = max(len, 1 + f(i +1, i, nums));
        }

        return dp[i][prev+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size(), vector<int>(nums.size()+1,-1));
        return f(0,-1,nums);

    }
};
