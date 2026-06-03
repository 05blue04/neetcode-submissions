class Solution {
public:
    int f(int i, bool hold, vector<int>& prices,vector<vector<int>>& dp){
        if(i >= prices.size()){
            return 0;
        }

        if(dp[i][hold] != -1)
            return dp[i][hold];

        if(!hold){ // we can choose to either buy or hold
            dp[i][hold] = max(f(i+1, 1,prices,dp) - prices[i], f(i+1,0,prices,dp));
        } else{ //choose to sell or hold
            dp[i][hold] = max(f(i+2,0,prices,dp) + prices[i], f(i+1,hold,prices,dp));
        }

        return dp[i][hold];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2,-1));
        return f(0, 0, prices,dp);
    }
};
    