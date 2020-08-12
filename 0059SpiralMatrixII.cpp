class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> dc = {1, 0, -1, 0}, dr = {0,1,0,-1};
        int di = 0, row=0, col=0;
        vector<vector<int> > rlt(n, vector<int>(n, 0));
        for(int i=1;i<=n*n;i++){
            rlt[row][col] = i;
            int tmp_row = row + dr[di], tmp_col = col + dc[di];
            if(tmp_row>=n || tmp_row<0 || tmp_col>=n || tmp_col<0 || rlt[tmp_row][tmp_col]!=0) di = (di+1) % 4;
            row += dr[di]; col += dc[di];
        }
        return rlt;
    }
};