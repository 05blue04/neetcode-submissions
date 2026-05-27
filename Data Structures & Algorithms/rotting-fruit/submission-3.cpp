class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int ripe = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1)
                    ripe++;
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        int time = 0;
        vector<pair<int,int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty() && ripe != 0){
            int sz = q.size();
            time++;
            for(int i = 0; i < sz; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(const auto& dir : directions){
                    int nx = x + dir.first;
                    int ny = y + dir.second;
                    if(nx > -1 && nx < grid.size() && ny > -1 && ny < grid[0].size() && grid[nx][ny] != 0 && grid[nx][ny] != 2){
                        ripe--;
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                    }
                }
            }
        }

        if(ripe != 0)
            return -1;
        return time;
    }
};
     