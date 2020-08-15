class Solution {
public:
    int nrow, ncol;
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return ;
        nrow = matrix.size(), ncol = matrix[0].size();
        for(int i=0;i<nrow;i++){ 
            for(int j=0;j<ncol;j++){
                if (matrix[i][j] == 0) { // find zeros in the matrix and set it to -1000000
                    setZeroes(matrix, i, j, 0);
                    setZeroes(matrix, i, j, 1);
                    break;
                }
            }
        }
        for(int i=0;i<nrow;i++){
            for(int j=0;j<ncol;j++){
                if (matrix[i][j] == -1000000) { // set all our maker to 0
                    matrix[i][j] = 0;
                }
            }
        }
    }
    
     void setZeroes(vector<vector<int>>& matrix, int row, int col, int dir) {
        if(dir == 0){ // set zeros horizontally
            for(int j=0;j<ncol;j++){
                if(j==col) matrix[row][j] = -1000000;
                else if(matrix[row][j] == -1000000) ;
                else if(matrix[row][j] != 0) matrix[row][j] = -1000000;
                else setZeroes(matrix, row, j, 1);
            }
        }else{ // set zeros vertically
            for(int i=0;i<nrow;i++){
                if(i==row) matrix[i][col] = -1000000;
                else if(matrix[i][col] == -1000000) ;
                else if(matrix[i][col] != 0) matrix[i][col] = -1000000;
                else  setZeroes(matrix, i, col, 0);
            }
        }
    }
};