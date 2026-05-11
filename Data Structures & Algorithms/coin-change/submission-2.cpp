class Solution {
    vector<int> dp;
public:
    long f(long total, long target, vector<int>& coins){
        if(total == target)
            return 0;
        
        if(dp[total] != -1)
            return dp[total];
        
        long mini = INT_MAX;
        for(int i = 0; i < coins.size();i++){
            if(total + coins[i] > target)
                continue;
            mini = min(mini, f(total + coins[i], target, coins) + static_cast<long>(1));
        }

        return dp[total] = mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        dp.resize(amount, -1);
        long res = f(0, amount, coins);
        if(res == INT_MAX)
            return -1;
        
        return res;
    }
};
