class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int prev1 = 1;
        int curr = 1;

        if(n < 2)
            return 1;

        for(int i = 2; i <= n; i++){
            curr = prev + prev1;
            prev1 = prev;
            prev = curr;
        } 
        return curr;
    }
};
