class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int count = 0;
        for(const auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i = 0; i < n; i++){
            int check = visit.size();
            dfs(i,-1, adj);
            if(visit.size() > check)
                count++;
            
            if(visit.size() == n)
                break;
        }

        return count;

    }
private:
    unordered_set<int> visit;

    void dfs(int node, int parent, vector<vector<int>>& adj){
        if(visit.count(node))
            return;
        
        visit.insert(node);

        for(int nei : adj[node]){
            if(nei == parent)
                continue;
            
            dfs(nei, node,adj);
        }
    }

};
