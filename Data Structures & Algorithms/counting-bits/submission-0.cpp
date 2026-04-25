class Solution {
public:
    int counter(int n){
        uint32_t mask = 1;
        int count = 0;
        for(int i = 0; i < 32; i++){
            uint32_t check = mask & n;
            if(check > 0)
                count++;
            mask = mask << 1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> res;

        for(int i = 0; i <= n; i++){
            res.push_back(counter(i));
        }

        return res;
    }
};
