class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pt;
        for(int i=1;i<=numRows;i++){
            pt.push_back(vector<int>(i));
            for(int j=0;j<i;j++){
                if(j==0 || j==i-1) pt[i-1][j] = 1;
                else pt[i-1][j] = pt[i-2][j] + pt[i-2][j-1];
            }
        }
        return pt;
    }
};
