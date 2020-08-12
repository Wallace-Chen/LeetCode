class Solution {
public:
    int n;
    void rotate(vector<vector<int>>& matrix) {
        n = matrix.size();
        for(int j=0;j<=n/2;j++){
            for(int i=j;i<n-1-j;i++)    loopswap(matrix, i,j); // we do a round swap here (think of rotating four corners)
        }
    }
    void loopswap(vector<vector<int>>& matrix, int i, int j){
        // (i,j) --> (j, len-i-1)
        swap(matrix[i][j], matrix[j][n-i-1]);
        // (j, len-i-1) --> (len-i-1, len-j-1)
        swap(matrix[i][j], matrix[n-i-1][n-j-1]);
        // (len-i-1, len-j-i) --> (len-j-1, i), (len-j-1, i) --> (i,j)
        swap(matrix[i][j], matrix[n-j-1][i]);
    }
};