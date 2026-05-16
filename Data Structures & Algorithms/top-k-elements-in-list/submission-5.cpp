class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq_map;
       vector<vector<int>> count(nums.size() + 1);

        for(int elem : nums){ //create the freq map
            freq_map[elem]++;
        }

        for(auto elem : freq_map){
            count[elem.second].push_back(elem.first);
        }

        vector<int> res;
        int l = 0;
        for(int i = nums.size(); i >= 0 && l < k ; i--){
            vector<int> inner = count[i];

            for(int j = 0; j < inner.size() && l < k;  j++){
                res.push_back(inner[j]);
                l++;
            }
        }

        return res;
    }
};
