class Solution {
public:
    vector<vector<string>> rlt;
    int nsize;
    vector<vector<string>> solveNQueens(int n) {
        nsize = n;
        vector<int> sol(n, -1);
        set<int> opts;
        for(int i =0;i<n;i++) opts.insert(i);
        solveNQueens(0, sol, opts);
        return rlt;
    }
    
    void solveNQueens(int nrow, vector<int>& sol, set<int>& opts) {
        if(nrow == nsize) {writeSol(sol); return;}
        for(auto col: opts){
            set<int> tmp(opts);
            if(!notDiag(sol, nrow, col)) continue;
            tmp.erase(col);
            sol[nrow] = col;
            solveNQueens(nrow+1, sol, tmp);
        }
        return ;
    }
    
    bool notDiag(vector<int>& sol, int row, int col){
        for(int i=0;i<row;i++){
            if(abs(col-sol[i])==abs(i-row)) return false;
        }
        return true;
    }
    
    void writeSol(vector<int>& sol){
        vector<string> board(nsize, string(nsize, '.'));
        for(int i=0;i<nsize;i++){
            board[i][sol[i]] = 'Q';
        }
        rlt.push_back(board);
    }
};