class Solution {
vector<int> dp;
public:

    int stairs(int n){
        if(n == 0 || n == 1)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = stairs(n -1) + stairs(n - 2);
    }
    int climbStairs(int n) {
        dp.resize(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        stairs(n);

        return dp[n];
    }
};
