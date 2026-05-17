class Solution {
    vector<vector<bool>> dp;
public:
    // bool f(int idx, int target, vector<int>& nums){
    //     if(target == 0)
    //         return true;
    //     if(idx == 0) 
    //         return nums[0] == target;

    //     if(dp[idx][target] != -1)
    //         return dp[idx][target];

    //     bool no_take = f(idx - 1, target,nums);
    //     bool take = false;
    //     if(target >= nums[idx])
    //         take = f(idx - 1, target - nums[idx], nums);
        
    //     return dp[idx][target] = no_take | take;
    // }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums){
            sum += num;
        }

        if(sum % 2 != 0)
            return false;

        int target = sum / 2;

        dp.resize(nums.size(), vector<bool>(target + 1, 0));

        for(int i = 0; i < nums.size();i++){
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;

        for(int i = 1; i < nums.size();i++){
            for(int t = 1; t <= target; t++){
                bool no_take = dp[i - 1][t];
                bool take = false;
                if(t >= nums[i])
                    take = dp[i - 1][t - nums[i]];
                
                dp[i][t] = no_take | take;
            }
        }

        return dp[nums.size() -1][sum / 2];
    }
};
