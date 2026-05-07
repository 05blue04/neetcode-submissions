class Solution {
    vector<int> dp;
public:
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
        dp.resize(cost.size() + 1, -1);
        return f(cost.size(), cost);
        
    }
};
