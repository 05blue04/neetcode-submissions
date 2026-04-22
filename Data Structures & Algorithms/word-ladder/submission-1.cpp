class Solution {
private:
    std::unordered_map<std::string, vector<std::string>> adj;
    std::unordered_set<std::string> visited;
    std::queue<std::string> q;

    bool matches(string a, string b){
        if(a.size() != b.size())
            return false;
        
        int distinct_count = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i])
                distinct_count++;
            if(distinct_count > 1)
                return false;
        }

        return distinct_count == 1;
    }
    
    int bfs(string begin, string end){
        int path_count = 1;  
        q.push(begin);
        visited.insert(begin);
        
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                string word = q.front();
                q.pop();
                for(const auto& str : adj[word]){
                    if(visited.count(str))
                        continue;
                    if(str == end){
                        return ++path_count;
                    }
                    q.push(str);
                    visited.insert(str);
                }
            }
            path_count++;
        }

        return 0;// if match wasn't found in path
    }
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        //initialize adjaceny list for words
        adj[beginWord] = {};
        for(const auto& word : wordList){
            adj[word] = {}; 
        }

        //initialize graph 
        string curr = beginWord;
        int i = -1;
        while(i < (int)wordList.size()){
            for(auto word : wordList){
                if(matches(curr, word))
                    adj[curr].push_back(word);
            }
            i++;
            if(i < wordList.size())
                curr = wordList[i];
        }
        //traverse path and try to find endWord
        return bfs(beginWord, endWord);
    }
};
