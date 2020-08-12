class Solution {
public:
    //typedef pair<pair<int, int>, int> PAIR;
    //struct CustomCompare
    //{
    //    bool operator()(const PAIR& a, const PAIR& b)
    //    {
    //        return a.second > b.second;
    //    }
    //};
    //typedef priority_queue<PAIR, vector<PAIR>, CustomCompare> min_heap;
    //min_heap hp;
    Solution() : nallowed(9, vector<int>(9, 0)) {
    }
    
    map<int, set<char> > rows, columns;
    map<int, map<int, set<char> > > grid;
    vector<vector<char> > b;
    void solveSudoku(vector<vector<char>>& board) {
        b = board;
        initializeBoard();
        bool sol=solveBoard();
        board = b;
    }
    
    void initializeBoard(){ //load numbers into our sets
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char ch = b[i][j];
                if(ch=='.') continue;
                rows[i].insert(ch);
                columns[j].insert(ch);
                grid[i/3][j/3].insert(ch);
            }
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                nallowed[i][j] = 10;
                char ch = b[i][j];
                if(ch!='.') nallowed[i][j] = 10; // any number greater than 9, so that this cell will never be considered.
                else nallowed[i][j] = getnAllowed(i, j);
                //if(ch=='.') hp.push({{i,j}, getnAllowed(i, j)});
            }
        }
    }

     int getnAllowed(int i, int j){
        set<char> unions = rows[i];
        unions.insert(columns[j].cbegin(), columns[j].cend());
        unions.insert(grid[i/3][j/3].cbegin(), grid[i/3][j/3].cend());
        return (9-unions.size());
    }
    
    void getnAllowed(int i, int j, set<char>& s){
        set<char> unions = rows[i];
        s = {'1','2','3','4','5','6','7','8','9'};
        unions.insert(columns[j].cbegin(), columns[j].cend());
        unions.insert(grid[i/3][j/3].cbegin(), grid[i/3][j/3].cend());
        for(auto e:unions) s.erase(e);
    }
    
    bool solveBoard(){
        int i=-1,j=-1;
        set<char> opts;
        getNext(i, j, opts);
        
        if(i==-1 || j==-1) return true;
        for(auto k:opts){
            fillNumber(i, j, k);
            if(solveBoard()) return true; 
            fillNumber(i, j, '.'); // else, this k cannot be put here, so we reset this cell and try next posiible option
        }
        //hp.push({{i,j},getnAllowed(i, j)});
        return false; // means we tried all possible options, but it fails to complete the board
    }
    
    void getNext(int& row, int& col, set<char>& opts){
        row = -1; col = -1;
        
        int min = 10;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(nallowed[i][j]<min){
                    min = nallowed[i][j];
                    row = i;
                    col = j;
                }
            }
        }
        //row = hp.top().first.first;
        //col = hp.top().first.second;
        //hp.pop();
        getnAllowed(row, col, opts);
    }
    
    void fillNumber(int i, int j, char ch){
        
        if(ch!='.'){
            rows[i].insert(ch);
            columns[j].insert(ch);
            grid[i/3][j/3].insert(ch);
            nallowed[i][j] = 10;
        }else{
            rows.at(i).erase(b[i][j]);
            columns.at(j).erase(b[i][j]);
            grid.at(i/3).at(j/3).erase(b[i][j]);
            nallowed[i][j] = getnAllowed(i, j);
        }
        b[i][j] = ch;
    }
    private:
    vector<vector<int> > nallowed;
    
};