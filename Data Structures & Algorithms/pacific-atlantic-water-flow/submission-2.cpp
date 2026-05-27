class Solution {
    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& visit, queue<pair<int,int>>& q){
        vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(const auto& dir : directions){
                int nx = x + dir.first;
                int ny = y + dir.second;
                if(nx > -1 && nx < heights.size() && ny > -1 && ny < heights[0].size() 
                    && heights[x][y] <= heights[nx][ny] && !visit[nx][ny]){
                    visit[nx][ny] = true; //mark as visited
                    q.push({nx,ny});
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        vector<vector<bool>> pacific(heights.size(),vector<bool>(heights[0].size(),false));
        vector<vector<bool>> atlantic(heights.size(),vector<bool>(heights[0].size(),false));
        queue<pair<int,int>> q1;
        queue<pair<int,int>> q2;


        // initialize pacific and atlantic visit sets 
        for(int i = 0; i < heights.size();i++){
            pacific[i][0] = true;
            q1.push({i,0});
            atlantic[i][heights[0].size()-1] = true;
            q2.push({i,heights[0].size()-1});
        }
        for(int j = 0; j < heights[0].size(); j++){
            pacific[0][j] = true;
            if(j != 0)
                q1.push({0,j});
            atlantic[heights.size()-1][j] = true;
            if(j != heights[0].size()-1)
                q2.push({heights.size()-1,j});
        }

        bfs(heights,pacific,q1);
        bfs(heights,atlantic,q2);

        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                if(pacific[i][j] && atlantic[i][j])
                    res.push_back({i,j});
            }
        }

        return res;
    }
};
