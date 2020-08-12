class Solution {
public:
    vector<vector<int>> rlt;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int len = nums.size();
        if(len==0) {rlt.push_back({}); return rlt;}
        vector<vector<int> > tmp;
        //vector<int> tmp;
        sort(nums.begin(), nums.end());
        
        permute(nums, tmp);
        return rlt;
        
    }
    
     void permute(vector<int> nums, vector<int>& p) {
        if(nums.size()==1) {p.push_back(nums[0]);rlt.push_back(p);}
        else{
            for(int i=0;i<nums.size();i++) {
                if(i>0 && nums[i]==nums[i-1]) continue;
                vector<int> cache(nums), sol(p);
                cache.erase(cache.begin()+i);
                sol.push_back(nums[i]);
                permute(cache, sol);
            }
        }
    }
    
};