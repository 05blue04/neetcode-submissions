class Solution {
public:
    string create_freq_key(const string& s){
        int count[26];
        for(int i = 0; i < 26; i++){
            count[i] = 0;
        }

        for(int i = 0; i < s.size(); i++){
            count[s[i] - 'a']++;
        }

        string key = "";
        for(int i = 0; i < 26; i++){
            key += count[i];
        }
        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> map;

        for(string str : strs) {
            string key = create_freq_key(str);
            
            if(map.find(key) == map.end()){
                map[key] = {str};
                continue;
            }

            map[key].push_back(str);
        }

        vector<vector<string>> res;

        for(auto elem : map){
            res.push_back(elem.second);
        }

        return res;
    }

};
