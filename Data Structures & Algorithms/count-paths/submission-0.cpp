class Solution {
public:
    int f(int r, int c, vector<vector<int>>& m){
        if(r == 0 && c == 0)
            return 1;
        if(m[r][c] != -1)
            return m[r][c];

        int up = 0;
        if(r - 1 >= 0)
            up = f(r - 1, c, m);
        
        int left = 0;
        if(c - 1 >= 0)
            left = f(r,c-1,m);
        
        return m[r][c] = left + up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return f(m-1,n-1, dp);
    }
};
