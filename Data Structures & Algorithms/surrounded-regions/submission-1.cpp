class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0; i < rows; i++){
            if(board[i][0] == 'O')
                dfs(i,0,board,rows,cols);
            if(board[i][cols-1] == 'O')
                dfs(i,cols-1,board,rows,cols);
        }

        for(int i = 0; i < cols; i++){
            if(board[0][i] == 'O')
                dfs(0,i,board,rows,cols);
            if(board[rows-1][i] == 'O')
                dfs(rows-1,i,board,rows,cols);
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'S'){
                    board[i][j] = 'O';
                } else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }

private:
    void dfs(int r, int c, vector<vector<char>>& board, int rows, int cols){
        if(r < 0 || r >= rows || c < 0 || c >= cols|| board[r][c] != 'O')
            return;

        board[r][c] = 'S';

        dfs(r-1,c,board,rows,cols);
        dfs(r+1,c,board,rows,cols);
        dfs(r,c-1,board,rows,cols);
        dfs(r,c+1,board,rows,cols);
    }
};
