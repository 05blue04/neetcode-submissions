class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        // push all treasure indices to the q
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    q.push(make_pair(i,j));
                }
            }
        }
        vector<pair<int,int>> offsets = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int x = q.front().first;
            int y  = q.front().second;
            q.pop();

            for(const auto& off : offsets){
                int nx = x + off.first;
                int ny = y + off.second;
                if(nx >= 0 && nx < m  && ny >= 0 && ny < n && grid[nx][ny] != -1 && grid[nx][ny] > grid[x][y] + 1){
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx,ny});
                }
            }

        }
    }
};
