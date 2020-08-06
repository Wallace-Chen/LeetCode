class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len=nums.size(), lo = 0, hi = len-1, mid;
        if(target > nums.back()) return len;
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};