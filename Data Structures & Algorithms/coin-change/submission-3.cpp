class Solution {
    vector<long> dp;
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
        dp.resize(amount + 1, -1);

        dp[0] = 0;
        for(long amt = 1; amt <= amount; amt++){
            dp[amt] = INT_MAX;
            for(long i = 0; i < coins.size();i++){
                if(amt - coins[i] < 0)
                    continue;
                if(dp[amt] > dp[amt - coins[i]] + 1)
                    dp[amt] = dp[amt - coins[i]] + 1;
            }
        }

        long res = dp[amount];
        if(res >= INT_MAX)
            return -1;
        
        return res;
    }
};
