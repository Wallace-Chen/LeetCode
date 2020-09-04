class Solution {
public:
    int len;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > rlt={{}};
        sort(nums.begin(), nums.end());
        len = nums.size();
        vector<int> sub;
        subsetsWithDup(nums, sub, rlt, 0);
        return rlt;
    }
    
    void subsetsWithDup(vector<int>& nums, vector<int>& sub, vector<vector<int>>& rlt, int pos) {
        if(pos>=len) return ;
        for(int i=pos;i<len;i++ ){
            sub.push_back(nums[i]);
            rlt.push_back(sub);
            subsetsWithDup(nums, sub, rlt, i+1);
            sub.pop_back();
            while(i<len-1 && nums[i+1] == nums[i]) i++; // check for duplicates numbers and skip them
        }
    }
};
