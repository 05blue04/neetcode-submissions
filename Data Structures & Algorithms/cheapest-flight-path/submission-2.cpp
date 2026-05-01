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

       priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

       pq.push({0,0,src});

       while(!pq.empty()){
            int cost = pq.top()[0];
            int stop = pq.top()[1];
            int node = pq.top()[2];

            if(node == dst)
                return cost;

            pq.pop();

            for(const auto& it: adj[node]){
                int dest = it.second;
                int cost2 = it.first;
                
                if(stop <= k){
                    pq.push({cost + cost2, stop + 1, dest});
                }
            }
       } 
        
       return -1; 

    }
};
