class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        std::queue<pair<int,int>> q;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            //go up
            if(r - 1 >= 0 && grid[r-1][c] == INT_MAX){
                grid[r-1][c] = grid[r][c] + 1;
                q.push({r-1,c});
            }
            //go down
            if(r + 1 < rows && grid[r+1][c] == INT_MAX){
                grid[r+1][c] = grid[r][c] + 1;
                q.push({r+1,c});
            }
            //go left
            if(c - 1 >= 0 && grid[r][c-1] == INT_MAX){
                grid[r][c-1] = grid[r][c] + 1;
                q.push({r,c-1});
            }
            //go right
            if(c + 1 >= 0 && grid[r][c+1] == INT_MAX){
                grid[r][c+1] = grid[r][c] + 1;
                q.push({r,c+1});
            }

        }
        return;
    }
};
