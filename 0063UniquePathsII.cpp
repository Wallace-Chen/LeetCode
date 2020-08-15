class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if( obstacleGrid.size()==0 ) return 0;
        int ncol=obstacleGrid[0].size(), nrow=obstacleGrid.size();
        if(ncol == 0) return 1;
        vector<long> state(ncol+1, 0); // here use long type to avoid int overflow.
        state[ncol-1] = 1;
        for(int i=nrow-1;i>=0;i--){
            for(int j=ncol-1;j>=0;j--){
                if(!obstacleGrid[i][j]){
                    state[j] +=  state[j+1];
                }else state[j] = 0;
            }
        }
        return state[0];
    }
};