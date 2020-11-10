class Solution {
public:
    int nrow=0, ncol=0;
    void solve(vector<vector<char>>& board) {
        nrow = board.size(); 
        if(nrow==0) return;
        ncol = board[0].size();
        for(int j=0;j<ncol;j++){
            for(int i=0;i<nrow;i++){
                if(i==0 || i==nrow-1 || j==0 || j==ncol-1){ // only scan the border
                    if(board[i][j] == 'O'){ // set O to M, and check its connected cells
                        checkConnectedCell(board, i, j);
                    }
                }
            }
        }
        for(int j=0;j<ncol;j++){
            for(int i=0;i<nrow;i++){ // set Ms (means connected to some Os on the border) to Os, and Os to Xs
                if(board[i][j]=='M') board[i][j] = 'O';
                else if(board[i][j]=='O') board[i][j] = 'X';
            }
        }
    }
    
    void checkConnectedCell(vector<vector<char>>& board, int i, int j){
        board[i][j] = 'M';
        if(i-1>= 0 && board[i-1][j]=='O') checkConnectedCell(board, i-1, j);
        if(i+1<nrow && board[i+1][j]=='O') checkConnectedCell(board, i+1, j);
        if(j-1>= 0 && board[i][j-1]=='O') checkConnectedCell(board, i, j-1);
        if(j+1<ncol && board[i][j+1]=='O') checkConnectedCell(board, i, j+1);
    }
};
