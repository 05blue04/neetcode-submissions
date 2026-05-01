class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<vector<pair<int,int>>> adj(n);

       for(auto& flight : flights){
            int strt = flight[0];
            int dest = flight[1];
            int cost = flight[2];

            adj[strt].emplace_back(cost, dest);
        }

       vector<int> dist(n,INT_MAX);
       dist[src] = 0;
       priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

       pq.push({0,0,src});

       while(!pq.empty()){
            int cost = pq.top()[0];
            int stop = pq.top()[1];
            int node = pq.top()[2];

            pq.pop();

            for(const auto& it: adj[node]){
                int dest = it.second;
                int cost2 = it.first;
                
                if(dest == dst && stop <= k){
                    if(cost + cost2 < dist[dst]){
                        dist[dest] = cost + cost2;
                        pq.push({cost + cost2, stop, dest});
                        continue;
                    }
                }
                if(cost + cost2 < dist[dest] && stop + 1 <= k){
                    dist[dest] = cost + cost2;
                    pq.push({cost + cost2, stop + 1, dest});
                }
            }
       } 

       if(dist[dst] == INT_MAX)
            return -1;
        
       return dist[dst]; 

    }
};
