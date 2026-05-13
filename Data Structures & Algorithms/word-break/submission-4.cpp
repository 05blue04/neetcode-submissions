class Solution {
    vector<int> dp;
public:
    int f(int i, string& s, vector<string>& dict){
        if(i == s.size())
            return dp[i] = 1;

        if(dp[i] != -1)
            return dp[i];
        
        for(const auto& word : dict){
            if(i + word.size() > s.size())
                continue;
            string str(s.begin() + i, s.begin() + i + word.size());
            if(str == word && f(i + word.size(), s, dict))
                return dp[i] = 1;
        }

        return dp[i] = 0;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.size() + 1, -1);

        return f(0,s , wordDict);
    }
};
