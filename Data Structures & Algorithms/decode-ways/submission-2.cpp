class Solution {
    vector<vector<int>> cache;
public:
    bool valid_map(int i, int j, string& s){

        if(s[i] == '0')
            return false;

        if(i == j){
            return s[i] > '0' && s[i] <= '9';
        }
        string str = string(1, s[i]) + s[j];
        int check = std::stoi(str);

        if(check <= 0 || check > 26)
            return false;

        return true;
    }
    int f(int i, int j, string& s, int n){
        if(i >= n){
            //out of range
            return 0;
        }

        if(j >= n){
            return 0;
        }

        if(cache[i][j] != -1)
            return cache[i][j];
        
        if(!valid_map(i,j,s))
            return cache[i][j] = 0;
        
        if(i == j){
            if(i == n - 1)
                return cache[i][j] = 1;
            return cache[i][j] = f(i + 1, i + 1, s, n) +
                   f(i + 1, i + 2, s, n);
        }

        if(j == n -1)
            return cache[i][j] = 1;

        return cache[i][j] = f(j + 1, j + 1, s, n) + f(j + 1, j + 2, s, n);

    }
    int numDecodings(string s) {
        int n = s.size();
        if(n == 1){
            if(valid_map(0,0, s))
                return 1;
            return 0;
        }
        cache.resize(n + 1, vector<int>(n + 1, -1));
        return f(0,0, s, n) + f(0,1, s, n);
    }
};
