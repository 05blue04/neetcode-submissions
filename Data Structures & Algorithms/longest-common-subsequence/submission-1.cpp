class Solution {
    vector<vector<int>> dp;
public:
    int f(int i, int j, string& s1, string& s2){
        if(i == s1.size() || j == s2.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int add = 0;
        if(s1[i] == s2[j])
            add = 1;
        
        int both = f(i + 1, j + 1,s1 ,s2) + add;
        int a = f(i + 1, j, s1, s2);
        int b = f(i, j + 1, s1, s2);

        return dp[i][j] = max(both,max(a,b));
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size(),vector<int>(text2.size(),-1));
        return f(0,0,text1,text2);
    }
};
