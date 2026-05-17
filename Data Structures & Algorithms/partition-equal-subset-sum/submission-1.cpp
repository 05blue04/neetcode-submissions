class Solution {
    vector<vector<int>> dp;
public:
    bool f(int idx, int target, vector<int>& nums){
        if(target == 0)
            return true;
        if(idx == 0) 
            return nums[0] == target;

        if(dp[idx][target] != -1)
            return dp[idx][target];

        bool no_take = f(idx - 1, target,nums);
        bool take = false;
        if(target >= nums[idx])
            take = f(idx - 1, target - nums[idx], nums);
        
        return dp[idx][target] = no_take | take;
    }
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(int num : nums){
            target += num;
        }

        if(target % 2 != 0)
            return false;
        target /= 2;

        dp.resize(nums.size(), vector<int>(target + 1, -1));

        return f(nums.size() -1, target, nums);
    }
};
