class Solution {
public:
    vector<vector<int>> rlt;
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()<1) {rlt.push_back({}); return rlt;}
        vector<int> tmp;
        //permute(nums, tmp);
        permute(nums, tmp, 0);
        return rlt;
    }
    
     void permute(vector<int> nums, vector<int>& p, int pos) {
         if(pos == nums.size()) {rlt.push_back(p);return;}
         for(int i=0;i<=p.size();i++){
             vector<int> tmp(p);
             tmp.insert(tmp.begin()+i, nums[pos]);
             permute(nums, tmp, pos+1);
         }
     }
    
    
    /*
    void permute(vector<int> nums, vector<int>& p) {
        if(nums.size()==1) {p.push_back(nums[0]);rlt.push_back(p);}
        else{
            for(int i=0;i<nums.size();i++) {
                vector<int> cache(nums), sol(p);
                cache.erase(cache.begin()+i);
                sol.push_back(nums[i]);
                permute(cache, sol);
            }
        }
    }
    */
};