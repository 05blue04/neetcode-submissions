class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int> res{};

       for(int i = 0; i < numCourses; i++){
            prereqs[i] = {};
       }

       for(const auto& pre : prerequisites){
            prereqs[pre[0]].push_back(pre[1]); //create prerequisite map
       }
       for(int i = 0; i < numCourses; i++){
            if(!dfs(i,res))
                return {};
       }

       return res;
    }
private:
    unordered_map<int,vector<int>> prereqs; 
    unordered_set<int> visit;
    unordered_set<int> cycle;

    bool dfs(int i, vector<int>& res){
        if(cycle.find(i) != cycle.end())
            return false;
        
        if(visit.find(i) != visit.end()) 
            return true;

        cycle.insert(i);
        
        for(int pre : prereqs[i]){
            if(!dfs(pre,res))
                return false;
        }

        res.push_back(i);
        visit.insert(i);
        cycle.erase(i);

        return true;
    }
};
