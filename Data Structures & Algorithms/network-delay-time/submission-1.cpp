class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       unordered_map<int, vector<pair<int,int>>> adj;
       for(int i = 1; i <= n; i++){
            adj[i] = {};
       }
       for(auto time : times){
            adj[time[0]].emplace_back(time[1], time[2]); 
       } 
       
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
       minHeap.push({0,k}); //push start onto heap

       unordered_set<int> visited;
       int t = 0;

       while(!minHeap.empty()){
            auto curr = minHeap.top();
            minHeap.pop();

            int weight = curr.first;
            int nei = curr.second;

            if(visited.count(nei))
                continue;
            
            visited.insert(nei);
            t = weight;

            if(adj.count(nei)){
                for(const auto& next : adj[nei]){
                    int nei2 = next.first;
                    int weight2 = next.second;
                    if(!visited.count(nei2))
                        minHeap.push({weight + weight2, nei2});
                }
            }
       }

    if(visited.size() != n)
        return -1;
        
    return t;
    }
};
