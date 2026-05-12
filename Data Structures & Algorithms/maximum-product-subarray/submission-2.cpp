class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        for(int n : nums){
            if(n > res)
               res =n;
        }
        int curMax = 1, curMin = 1;
        for(int n : nums){
            if(n == 0){
                curMin = 1;
                curMax = 1;
                continue;
            }
            int tmp = curMax * n;
            curMax = max(tmp,max(curMin * n, n));
            curMin = min(tmp, min(curMin*n, n));
            res = max(curMax,res);
        }
        return res;
    }
};

