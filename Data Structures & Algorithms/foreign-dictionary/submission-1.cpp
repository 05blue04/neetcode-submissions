class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        if(words.size() == 1){
            if(words[0].size() == 1)
                return words[0];
            return "";
        }
       unordered_set<char> chars;
        for(auto& w : words)
            for(char c : w)
                chars.insert(c); 

       adj.resize(26);
       visit.resize(26,0); 
       cycle.resize(26,0);

       for(int i = 0; i < words.size(); i++){
            if(i + 1 == words.size()){
                continue;         
            }
            pair<char,char> p = compare(words[i], words[i + 1]);
            if(p.first == '#') return "";
            if(p.first != '\0')
                adj[p.second - 'a'].push_back(p.first);
       }

       string res = "";
       for(char c : chars){
            if(!dfs(c, res))
                return "";
       }

        return res; 
    }
private:
    vector<vector<char>> adj;
    vector<int> visit;
    vector<int> cycle;
    bool dfs(char node, string& res){
        if(visit[node - 'a'])
            return true;
        if(cycle[node - 'a'])
            return false;
        cycle[node - 'a'] = 1;

        for(auto it: adj[node - 'a']){
            if(!dfs(it, res))
                return false;
        }
        res += node;
        cycle[node - 'a'] = 0;
        visit[node - 'a'] = 1;
        return true;
    }

    pair<char,char> compare(string& a, string& b){
        int sz;
        if(a.size() < b.size()){
            sz = a.size();
        } else{
            sz = b.size();
        }

        for(int i = 0; i < sz; i++){
            if(a[i] != b[i]){
                return {a[i], b[i]};
            }
        }

        if(a.size() > b.size())
            return {'#', '#'}; // signal invalid
        return {'\0', '\0'};

    }

    
};
