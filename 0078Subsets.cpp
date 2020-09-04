class Solution {
public:
    vector<vector<int> > rlt = {{}};
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> com;
        combine(nums.size(), 0, com, nums);
        return rlt;
    }
    
    void combine(int n, int pos, vector<int>& com, vector<int>& nums) {
        int start = pos + 1;
        for(int i = start;i<=n;i++){
            com.push_back(nums[i-1]);
            rlt.push_back(com);
            combine(n, i, com, nums);
            com.pop_back();
        }
    }
};
