class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        unordered_set<int> visit;
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto time : times){
            adj[time[0]].emplace_back(time[2], time[1]);
        }

        pq.push({0,k});
        int tm = 0;

        while(!pq.empty()){
            int wt1 = pq.top().first;
            int n = pq.top().second;
            pq.pop();
            if(visit.count(n))
                continue;
            visit.insert(n);
            tm = wt1;

            for(const auto& it : adj[n]){
                int wt2 = it.first;
                int nei = it.second;

                if(!visit.count(nei)){
                    pq.push({wt1 + wt2, nei});
                }
            }
        }

        if(visit.size() != n){
            return -1;
        }

        return tm;
    }
};
