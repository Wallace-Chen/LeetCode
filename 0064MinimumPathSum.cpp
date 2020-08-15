class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size()==0) return 0;
        int nrow = grid.size(), ncol = grid[0].size();
        vector<int> dp(ncol+1, 0);
        for(int i=0;i<nrow;i++){
            for(int j=0;j<ncol;j++){
                if(i==0) dp[j+1] = dp[j] + grid[i][j];
                else if(j==0) dp[j+1] += grid[i][j];
                else dp[j+1] = min(dp[j], dp[j+1]) + grid[i][j];
            }
        }
        return dp[ncol];
    }
};