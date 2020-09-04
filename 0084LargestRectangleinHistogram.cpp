class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size(), max_area=0;
        vector<int> left_smaller(len, -1), right_smaller(len, len);
        stack<int> left_stk, right_stk;
        for(int i=0;i<len;i++){
            while(!left_stk.empty() && heights[left_stk.top()]>=heights[i]) left_stk.pop();
            if(!left_stk.empty()) left_smaller[i] = left_stk.top();
            left_stk.push(i);
            
            int j = len-i-1;
            while(!right_stk.empty() && heights[right_stk.top()]>=heights[j]) right_stk.pop();
            if(!right_stk.empty()) right_smaller[j] = right_stk.top();
            right_stk.push(j);
        }
        
        for(int i=0;i<len;i++) max_area = max(max_area, heights[i]*(right_smaller[i]-left_smaller[i]-1));
        
        return max_area;
    }
};

/*
//refer to: https://github.com/ShusenTang/LeetCode/blob/master/solutions/84.%20Largest%20Rectangle%20in%20Histogram.md
class Solution {
public:
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
*/
