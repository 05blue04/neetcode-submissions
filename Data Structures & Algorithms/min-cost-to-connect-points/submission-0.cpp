class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int,int>>> adj(points.size());

        for(int i = 0; i < points.size(); i++){
            for(int j = i + 1; j < points.size(); j++){
                
                int xi = points[i][0];
                int yi = points[i][1];

                int xj = points[j][0];
                int yj = points[j][1];

                int dst = abs(xi - xj) + abs(yi - yj);

                adj[i].push_back({dst,j});
                adj[j].push_back({dst,i});
            }
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int> vis(points.size(),0);
        pq.push({0,0});
        int sum = 0;

        while(!pq.empty()){
            int dst = pq.top().first;
            int idx = pq.top().second;

            pq.pop();
            if(vis[idx])
                continue;
            
            vis[idx] = 1;
            sum += dst;

            for(const auto& p : adj[idx]){
                int dst2 = p.first;
                int idx2 = p.second;
                if(!vis[idx2])
                    pq.push({dst2, idx2});
            }
        }

        return sum;
    }
};
