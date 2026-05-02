class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> map;

        for(int i = 0; i < nums.size(); i++){
            auto val = map.find(nums[i]);

            if (val != map.end()){
                return true;
            }

            map.insert(nums[i]);
        }
        return false;
    }
};