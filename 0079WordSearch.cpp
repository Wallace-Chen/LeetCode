class Solution {
public:
    int nrow, ncol;
    bool exist(vector<vector<char>>& board, string word) {
        nrow = board.size(), ncol = board[0].size();
        for(int i=0;i<nrow;i++){
            for(int j=0;j<ncol;j++){
                if(dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int row, int col, int len){
        if(word[len] != board[row][col]) return false;
        if(len == word.size()-1) return true;
        char tmp = board[row][col];
        board[row][col] = '*';
        if(row>0 && dfs(board, word, row-1, col, len+1)) return true;
        if(row<nrow-1 && dfs(board, word, row+1, col, len+1)) return true;
        if(col>0 && dfs(board, word, row, col-1, len+1)) return true;
        if(col<ncol-1 && dfs(board, word, row, col+1, len+1)) return true;
        board[row][col] = tmp;
        return false;
    }
};
