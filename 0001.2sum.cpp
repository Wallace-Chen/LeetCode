class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> rlt;
        for(int i=0 ; i<nums.size();i++ ){
            if(map.find(target - nums[i]) == map.end()){
                map[nums[i]] = i;
            }
            else{
                rlt.push_back(map[target - nums[i]]);
                rlt.push_back(i);
                break;
            }
        }
        return rlt;
    }
};