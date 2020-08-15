class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> board(n, 1);
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                board[j] += board[j+1];
            }
        }
        return board[0];
    }
};