class DSU {
    vector<int> parent;
    vector<int> size;


    public:
        DSU(int n){
            parent.resize(n + 1);
            size.resize(n + 1,0);
            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
        }

        int findUParent(int node){
            if(node == parent[node])
                return node;
            
            return parent[node] = findUParent(parent[node]);
        }

        void unionBySize(int v, int u){
            int ultp_v = findUParent(v);
            int ultp_u = findUParent(u);

            if(ultp_v == ultp_u)
                return;
            
            if(size[ultp_v] > size[ultp_u]){
                parent[ultp_u] = ultp_v;
                size[ultp_v] += size[ultp_u];
            } else{
                parent[ultp_v] = ultp_u;
                size[ultp_u] += size[ultp_v];
            }
        }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU ds(edges.size());

        for(int i = 0; i < edges.size(); i++){
            if(ds.findUParent(edges[i][0]) == ds.findUParent(edges[i][1]))
                return {edges[i][0], edges[i][1]};
            ds.unionBySize(edges[i][0],edges[i][1]);
        }

        return {};
    }
};
