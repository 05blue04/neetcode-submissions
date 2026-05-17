class Solution {
public:
    bool isP(string s){
        int l = 0;
        int r = s.size()-1;
        while(l < r){
            if(s[l] != s[r])
               return false;
            l++;
            r--;
        }

        return true;
    }
    void f(int idx, string& s, vector<string>& path, vector<vector<string>>& res){
        if(idx >= s.size()){
           res.push_back(path);
           return;
        }

        string check = "";
        for(int i = idx; i < s.size();i++){
            check += s[i];
            if(isP(check)){
              path.push_back(check);
              f(i + 1,s,path,res);
              path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> p;
        f(0,s, p,res);
        return res;
    } 
};
