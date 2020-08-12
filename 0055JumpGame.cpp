class Solution {
public:
    bool canJump(vector<int>& nums) {
        int currpos = nums[0], nextpos=currpos, len=nums.size();
        if(len<=1) return true;
        for(int i=1;i<len && i<=currpos;i++){
            if(nums[i]+i>nextpos) nextpos=nums[i]+i;
            if(nextpos>=len-1) return true;
            if(i==currpos){
                currpos = nextpos;
            }
        }
        return false;
    }
};