class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(rows,vector<bool>(cols,false));
        vector<vector<bool>> atlantic(rows,vector<bool>(cols,false));

        vector<vector<int>> res;

        for(int i = 0; i < rows; i++){
            dfs(i, cols - 1, atlantic, heights[i][cols - 1], heights, rows, cols);
            dfs(i, 0, pacific, heights[i][0], heights,rows, cols);
        }

        for(int i = 0; i < cols; i++){
            dfs(0, i, pacific, heights[0][i],heights, rows, cols);
            dfs(rows - 1, i, atlantic, heights[rows-1][i], heights, rows, cols);
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(pacific[i][j] && atlantic[i][j])
                    res.push_back({i,j});
            }
        }

        return res;
        
    }
private:
    void dfs(int r, int c, vector<vector<bool>>& visited, int prevHeight, vector<vector<int>>& heights, int rows, int cols){
        if(r < 0 || c < 0 || r >= rows || c >= cols || prevHeight > heights[r][c] || visited[r][c])
            return;
        
        visited[r][c] = true;
        dfs(r-1,c,visited,heights[r][c], heights, rows, cols);
        dfs(r+1,c,visited,heights[r][c], heights, rows, cols);
        dfs(r,c-1,visited,heights[r][c], heights, rows, cols);
        dfs(r,c+1,visited,heights[r][c], heights, rows, cols);
    }
};
