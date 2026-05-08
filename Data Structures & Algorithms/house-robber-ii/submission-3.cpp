class Solution {
public:
    int f(int idx, vector<int>& nums, int n){
        int prev = 0;
        int prev2 = 0;
        for(int i = idx; i <= n; i++){
            int curr = max(nums[i] + prev2, prev);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        return max(f(0,nums, nums.size() - 2), f(1,nums, nums.size() - 1));
    }
};
