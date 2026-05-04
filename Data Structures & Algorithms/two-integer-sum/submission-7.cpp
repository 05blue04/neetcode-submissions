class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        std::unordered_map<int,int> map;

        for(int i = 0; i < nums.size(); i++){
            int check = target - nums[i];

            auto val = map.find(check);

            if(val != map.end()){ //this means we found our match
                return {val->second,i};
            }

            map[nums[i]] = i;
        }

        return {0,0};
    }
};
