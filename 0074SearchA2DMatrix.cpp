class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int ncol = matrix[0].size();
        int lo = 0, hi = matrix.size()*ncol - 1, mid;
        while(lo <= hi){
            mid = lo + (hi-lo)/2;
            if(matrix[mid/ncol][mid%ncol] == target) return true;
            else if(matrix[mid/ncol][mid%ncol] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return false;
    }
};