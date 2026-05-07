class Solution {
    vector<int> dp;
public:
    //recursive approach
    int f(int idx, vector<int>& cost){
        if(idx == -1)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        if(idx == cost.size()){
            return min(f(idx - 1, cost), f(idx - 2,cost));
        }

        int l = cost[idx] + f(idx - 1, cost);
        int r = INT_MAX;
        if(idx > 0){
            r = cost[idx] + f(idx - 2, cost);
        }

        
        return dp[idx] = min(l,r); 
    } 
    int minCostClimbingStairs(vector<int>& cost) {
        // dp.resize(cost.size() + 1, -1);

        //no recursion approach
        // dp[0] = 0;
        // dp[1] = 0;
        // for(int i = 2; i < cost.size(); i++){
        //     dp[i] = min(cost[i] + dp[i-1], cost[i] + dp[i-2])
        // }
        // return f(cost.size(), cost);

        // tabulation
        int prev = 0;
        int prev1 = 0;
        for(int i = 2; i <= cost.size();i++){
            int curr = min(cost[i - 1] + prev, cost[i - 2] + prev1);
            prev1 = prev;
            prev = curr;
        }

        return prev;
        
    }
};
