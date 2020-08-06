class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=nums.size(), rlt = 0;
        if(len==0) return 0;
        for(int i=1;i<len;i++){
            if(nums[i]!=nums[rlt]) {rlt++; nums[rlt]=nums[i];}
        }
        return rlt+1;
    }
};