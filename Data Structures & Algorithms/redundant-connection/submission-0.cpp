class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size() + 1);

        for(const auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        cycle_start = -1;
        dfs(1,-1, adj);

        for(int i = edges.size() - 1; i >= 0; i--){
            int u = edges[i][0];
            int v = edges[i][1];

            if(cycle.count(u) && cycle.count(v))
                return {u,v};
        }

        return {};
        
    }
private:
    unordered_set<int> visit;
    unordered_set<int> cycle;
    int cycle_start;

    bool dfs(int node, int parent, vector<vector<int>>& adj){
        if(visit.count(node)){
            cycle_start = node;
            return true;
        }

        visit.insert(node);
        for(int nei : adj[node]){
            if(nei == parent)
                continue;
            
            if(dfs(nei, node, adj)){
                if(cycle_start != -1)
                    cycle.insert(node);
                
                if(cycle_start == node)
                    cycle_start = -1;
                
                return true;
            }
        }

        return false;
    }
};
