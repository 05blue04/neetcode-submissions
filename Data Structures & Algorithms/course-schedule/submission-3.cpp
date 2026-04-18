struct Node{
        int num; //course number
        vector<Node*> neighbors;
        
        Node(int num) : num(num){}
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        for(int i = 0; i < numCourses; i++){
            reqs[i] = {};
        }

        for(const auto& course : prerequisites){
            reqs[course[1]].push_back(course[0]);
        }

        for(int i = 0; i < numCourses;i++){
            if(!dfs(i))
                return false;
        }

        return true;
    }
private:
    unordered_map<int, vector<int>> reqs;
    unordered_set<int> visit;
    bool dfs(int course){

        if(visit.find(course) != visit.end()){
            return false;
        }

        if(reqs[course].empty())
            return true;

        visit.insert(course);

        for(const auto& deps : reqs[course]){
            if(!dfs(deps))
                return false;
        }
        visit.erase(course);
        reqs[course].clear();


        return true;
    }
};
