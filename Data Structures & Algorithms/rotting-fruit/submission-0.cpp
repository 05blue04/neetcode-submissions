class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       queue<pair<int,int>> q; 
       int rows = grid.size();
       int cols = grid[0].size();
       int time = 0;
       int fresh_count = 0;

       for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    fresh_count++;
                }
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
       }

       while(!q.empty() && fresh_count != 0){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                //check above
                if(r - 1 >= 0 && grid[r-1][c] == 1){
                    fresh_count--;
                    grid[r-1][c] = 2;
                    q.push({r-1,c});
                }
                //check below
                if(r + 1 < rows && grid[r+1][c] == 1){
                    fresh_count--;
                    grid[r+1][c] = 2;
                    q.push({r+1,c});
                }
                //check to the left
                if(c - 1 >= 0 && grid[r][c-1] == 1){
                    fresh_count--;
                    grid[r][c-1] = 2;
                    q.push({r,c-1});
                }
                //check to the right
                if(c + 1 < cols && grid[r][c+1] == 1){
                    fresh_count--;
                    grid[r][c+1] = 2;
                    q.push({r,c+1});
                }
            }
            time++;
       }

       if(fresh_count != 0){
            return -1;
       }

       return time;
    }
};
