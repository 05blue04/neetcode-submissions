class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>> dp(text1.size() + 1,vector<int>(text2.size() + 1,0));
        vector<int> prev(text2.size() + 1, 0);
        vector<int> curr(text2.size() + 1, 0);

        for(int j = 0; j < text2.size();j++){
            prev[j] = 0;
        }

        for(int i = 1; i <= text1.size(); i++){
            for(int j = 1; j <= text2.size(); j++){
                if(text1[i - 1] == text2[j - 1]){
                    curr[j] = prev[j - 1] + 1;
                } else{
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[text2.size()];
    }
};
