class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        return kSum(nums, target, 0, 4);
    }
    
    vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k) {
        vector<vector<int>> rlt;
        if(nums.size() < k) return rlt;
        int sum_check = 0;
        for_each(nums.begin()+start, nums.begin()+start+k, [&] (int n) {
                    sum_check += n;
                });
        if(sum_check > target) return rlt;
        sum_check = 0;
        for_each(nums.end()-k, nums.end(), [&] (int n) {
                    sum_check += n;
                });
        if(sum_check < target) return rlt;
        
        if (k==2) {
            return twoSum(nums, target, start);
        }
        
        for(int i = start; i < nums.size()-k+1;i++){
            if(i>0 && i>start && nums[i]==nums[i-1]) continue;
            vector<vector<int>> tmp;
            tmp = kSum(nums, target-nums[i], i+1, k-1);
            for (auto &set: tmp){
                rlt.push_back({nums[i]});
                rlt.back().insert(end(rlt.back()), begin(set), end(set));
            }
        }
        
        return rlt;
    }
    
    vector<vector<int>> twoSum(vector<int>& nums, int target, int start) {
        int low = start;
        int high = nums.size()-1;
        vector<vector<int> > rlt;
        while(low<high){
            if(nums[low] + nums[high] == target){
                vector<int> pair;
                pair.push_back(nums[low]);
                pair.push_back(nums[high]);
                rlt.push_back(pair);
                while(low<high-1 && nums[low]==nums[low+1]) low++;
                low ++;
                while(low<high-1 && nums[high]==nums[high-1]) high--;
                high --;
            }
            else if(nums[low] + nums[high] > target) {
                while(low<high-1 && nums[high]==nums[high-1]) high--;
                high --;
            }
            else{
                while(low<high-1 && nums[low]==nums[low+1]) low++;
                low ++;
            }
        }
        return rlt;
    }
    
};