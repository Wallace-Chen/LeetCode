class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int nrow = matrix.size(), ncol = matrix[0].size();
        int max_area = 0;
        vector<int> heights(ncol, 0);
        for(int i=0;i<nrow;i++){
            for(int j=0;j<ncol;j++){
                if(matrix[i][j] == '1') heights[j] += 1;
                else heights[j] = 0;
            }
            max_area = max(max_area, largestRectangleArea(heights));
        }
        return max_area;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size(), res = 0;
        
        stack<int>ascend_stk;
        for(int i = 0; i < n; i++){
            while(!ascend_stk.empty() && heights[ascend_stk.top()] > heights[i]){
                //cout << i << " " << heights[i] << " " << heights[ascend_stk.top()] << endl;
                int height = heights[ascend_stk.top()]; ascend_stk.pop();
                int width = ascend_stk.empty() ? i : i - 1 - ascend_stk.top();
                res = max(res, height * width);
            }
            ascend_stk.push(i);
        }
        return res;
    }
};
