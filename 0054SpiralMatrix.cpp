class Solution {
public:
    vector<int> rlt;
    int ncolumn = 0, nrow = 0;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return rlt;
        nrow = matrix.size(), ncolumn = matrix[0].size();
        for(int i=0;i<(min(ncolumn, nrow)-1)/2+1;i++){
            loopspiral(i, matrix);
        }
        return rlt;
    }
        
    void loopspiral(int start, vector<vector<int>>& matrix){
        // go right first
        int i=start, j=start;
        for(;j<ncolumn-start;j++) rlt.push_back(matrix[i][j]);
        // go down
        j--; i++;
        if(i>=nrow-start) return;
        for(;i<nrow-start;i++) rlt.push_back(matrix[i][j]);
        // go left
        i--; j--;
        if(j<start) return;
        for(;j>=start;j--) rlt.push_back(matrix[i][j]);
        // go up
        j++; i--;
        if(i<=start) return;
        for(;i>start;i--) rlt.push_back(matrix[i][j]);
    }
};