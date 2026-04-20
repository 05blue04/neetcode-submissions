class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        unordered_set<int> visit;
        queue<pair<int,int>> q;

        if((n - 1) < edges.size())
            return false;
        
        for(const auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        q.push({0,-1}); // {node, parent}
        // visit.insert(0);

        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            if(visit.find(node) != visit.end())
                return false;
                 
            visit.insert(node);

            for(int neigh : graph[node]){
                if(neigh == parent)
                    continue;
                
                q.push({neigh,node});
            }
            
        }

        return visit.size() == n;

    }
};
