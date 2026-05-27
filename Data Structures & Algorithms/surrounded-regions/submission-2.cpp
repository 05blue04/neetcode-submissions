class Solution {

public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m;i++){
            if(board[i][0] == 'O'){
                board[i][0] = 'S';
                q.push({i,0});
            }
            if(board[i][n-1] == 'O'){
                board[i][n-1] = 'S';
                q.push({i,n-1});
            }
        }

        for(int j = 0; j < n; j++){
            if(board[0][j] =='O'){
                board[0][j] = 'S';
                q.push({0,j});
            }
            if(board[m-1][j] == 'O'){
                board[m-1][j] = 'S';
                q.push({m-1,j});
            }
        }

        vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            auto it = q.front();
            int x = it.first;
            int y = it.second;
            q.pop();

            for(const auto& dir : directions){
                int nx = x + dir.first;
                int ny = y + dir.second;
                if(nx > -1 && nx < m && ny > -1 && ny < n && board[nx][ny] == 'O'){
                    board[nx][ny] = 'S';
                    q.push({nx,ny});
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'S'){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
