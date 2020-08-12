class Solution {
public:
    int nsize;
    int ret;
    int totalNQueens(int n) {
        vector<int> mid(n, 1), left(2*n-1, 1), right(2*n-1, 1);
        ret = 0; nsize = n;
        solveTotalNQueens(0, mid, left, right);
        return ret;
    }
    
    void solveTotalNQueens(int nrow, vector<int>& mid, vector<int>& left, vector<int>& right) {
        if(nrow == nsize) {ret++; return;}
        for(int j=0;j<nsize;j++){
            if(mid[j] && left[nrow+j] && right[j-nrow+(nsize-1)]){
                mid[j] = left[nrow+j] = right[j-nrow+(nsize-1)] = 0;
                solveTotalNQueens(nrow+1, mid, left, right);
                mid[j] = left[nrow+j] = right[j-nrow+(nsize-1)] = 1;
            }
        }
    }
};