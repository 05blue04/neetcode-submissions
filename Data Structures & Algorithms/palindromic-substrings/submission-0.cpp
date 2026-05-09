class Solution {
    vector<vector<int>> dp;
public:
    bool isP(int l, int r, string& s){
        if (l == r)
            return true;
        
        while(l <= r){
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }

        return true;
    }
    int f(int l, int r, string& s){
        if(dp[l][r] != -1)
            return 0;
        
        if(l == r)
            return dp[l][r] = 1;
        
        int add = 0;
        if(isP(l, r, s))
            add++;
        
        return dp[l][r] = f(l + 1, r, s) + f(l, r - 1, s) + add;

    }
    int countSubstrings(string s) {
        dp.resize(s.size(), vector<int>(s.size(), -1));
        return f(0, s.size() - 1, s);
    }
};
