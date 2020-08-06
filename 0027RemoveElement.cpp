class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int rlt=0, len=nums.size();
        for(int i=0;i<len;i++){
            //if(nums[i] != val) {nums[rlt]=nums[i]; rlt++;}
            if(nums[i] == val) {nums[i] = nums[len-1]; nums.pop_back();len -=1;i--;}
            //else rlt++;
        }
        //return rlt;
        return len;
    }
};