class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if(len<=1) return 0;
        vector<int> dp(len);
        dp[len-1] = 0;
        for(int i = len-2;i>=0;i--){
            if(nums[i]>=len-1-i) dp[i] = 1; // set it to 1 if we can directly jump over to the dest
            else if(nums[i]<1) dp[i] = -1; // set it to -1 if we cannot jump at this cell
            else{
                int mincost = -1;
                for(int k=nums[i];k>=1;k--) // try all possible jumps
                    if(dp[i+k] != -1 ) // skip this jump if next number is 0
                        if(mincost<0 || (1+dp[i+k])<mincost){
                            mincost = 1+dp[i+k];
                            if(mincost <= 2) break; // we've already have the optimal jump in this case
                        }
                dp[i] = mincost; // update the dp array
            }
        }
        
        return dp[0];
    }
};