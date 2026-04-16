class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        std::queue<pair<int,int>> q;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 0){
                    continue;
                }
                
                int area = 0;
                q.push({i,j});
                grid[i][j] = 0;
                while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    area++;

                    //check up
                    if(r - 1 >= 0 && grid[r - 1][c] != 0){
                        q.push({r - 1, c});
                        grid[r-1][c] = 0;
                    }
                    //check down
                    if(r + 1 < rows && grid[r + 1][c] != 0){
                        q.push({r+1,c});
                        grid[r+1][c] = 0;
                    }
                    //check to the left
                    if(c - 1 >= 0 && grid[r][c - 1] != 0){
                        q.push({r,c-1});
                        grid[r][c-1] = 0;
                    }
                    // check to the right
                    if(c + 1 < cols && grid[r][c+1] != 0){
                        q.push({r,c+1});
                        grid[r][c+1] = 0;
                    }
                    
                }

                if(area > res){
                    res = area;
                }

            }
        }

        return res;

        
    }
};
