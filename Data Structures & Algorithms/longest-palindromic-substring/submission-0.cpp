class Solution {
    vector<vector<pair<int,int>>> dp;
public:
    bool isP(int l, int r, string& s){
        if(l == r)
            return true;
        
        while(l <= r){
            if(s[l] != s[r])
                return false;
            
            l++;
            r--;
        }
        return true;
    }
    pair<int,int> f(int l, int r, string& s){
        if(l > r)
            return {0, 0};
        
        if(dp[l][r].first != -1){
            return dp[l][r];
        }
        
        if(isP(l, r, s)){
            return dp[l][r] = {l,r}; 
        }
        
        auto p1 = f(l + 1, r, s);
        auto p2 = f(l, r - 1, s);

        int diff1 = p1.second - p1.first;
        int diff2 = p2.second - p2.first;
        
        if(diff1 >= diff2)
            return dp[l][r] = p1;
        
        return dp[l][r] = p2;
    }
    string longestPalindrome(string s) {
        // -1 -> not calc
        // 0 -> not a pal
        // 1 -> is pal
        dp.resize(s.size(), vector<pair<int,int>>(s.size(), {-1,-1}));
        pair<int,int> indices = f(0, s.size() - 1, s);

        string res = "";
        int l = indices.first;
        int r = indices.second;
        while(l <= r){
            res += s[l];
            l++;
        }

        return res;
        
    }
};
  