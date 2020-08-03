class Solution {
public:
    int maxArea(vector<int>& height) { // key: two pointers and move the shorter one
        int left = 0, right = height.size()-1, areaMax = 0;
        while(left < right){
            int area = min(height[left], height[right]) * (right - left);
            if( area > areaMax ) areaMax = area;
            if(height[left] < height[right]) left ++;
            else right --;
        }
        return areaMax;
    }
};