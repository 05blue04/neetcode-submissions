class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>> visit(r,vector<bool>(c,false));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> heap; // {time , i, j}


        heap.push({grid[0][0],0,0});
        while(!heap.empty()){
            int t = heap.top()[0];
            int i = heap.top()[1];
            int j = heap.top()[2];

            if(i == (r - 1) && j == (c - 1))
                return t;

            heap.pop();

            if(visit[i][j])
                continue;
            visit[i][j] = true;

            if(i + 1 < r){
                int tn = grid[i+1][j];

                if(t > tn)
                    tn = t;
                
                heap.push({tn, i + 1, j});
            }

            if(i - 1 >= 0){
                int tn = grid[i-1][j];

                if(t > tn)
                    tn = t;
                
                heap.push({tn, i - 1, j});
            }

            if(j + 1 < c){
                
                int tn = grid[i][j+1];

                if(t > tn)
                    tn = t;
                
                heap.push({tn,i,j + 1});
            }

            if(j - 1 >= 0){
                int tn = grid[i][j-1];

                if(t > tn)
                    tn = t;
                
                heap.push({tn,i,j - 1});
            }
            
        }
        return -1;

    }
};
