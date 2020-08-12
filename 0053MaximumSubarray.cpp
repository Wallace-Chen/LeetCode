class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int rlt=0, len = nums.size();
        if(len==0) return INT_MIN;
        vector<int> dp(len, 0);
        dp[0] = nums[0]; rlt = dp[0];
        for(int i=1;i<len;i++){
            if(nums[i]+dp[i-1]>nums[i]) dp[i] = nums[i]+dp[i-1];
            else dp[i] = nums[i];
            if(dp[i] > rlt) rlt = dp[i];
        }
        return rlt;
    }
};