class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> row;
        map<int, set<char> > column;
        map<int, set<char> >  grid;
        for(int i = 0;i<9;i++){
            for(int j =0;j<9;j++){
                char ch = board[i][j];
                if(ch=='.') continue;
                if(row.find(ch)==row.end())  row.insert(ch);
                else return false;
                if( column[j].find(ch)==column[j].end() ) column[j].insert(ch);
                else return false;
                if(grid[j/3].find(ch)==grid[j/3].end()) grid[j/3].insert(ch);
                else return false;
            }
            row.clear();
            if((i+1)%3 == 0) grid.clear();
        }
        grid.clear();
        return true;
    }
};