class Solution {
    vector<vector<int>> dp;
public:
    bool f(int l, int r, unordered_set<string>& dict, string& s, string cur){
        if(r == s.size() && l == s.size())
            return true;

        if(r == s.size() || l == s.size())
            return false;

        if(dp[l][r] != -1)
            return dp[l][r];
        
        cur += s[r];

        if(dict.find(cur) != dict.end()){
            if(f(r+1, r+1, dict, s, ""))
                return dp[l][r] = true;
        }

        return dp[l][r] = f(l, r + 1, dict, s , cur);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        dp.resize(s.size() + 1, vector<int>(s.size() + 1, -1));
        for(const auto& word : wordDict){
            dict.insert(word);
        }
    
        return f(0,0, dict, s, "");
    }
};
