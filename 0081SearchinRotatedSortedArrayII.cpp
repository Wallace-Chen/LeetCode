class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size(), lo = 0, hi = len-1, mid;
        while(lo <= hi){
            mid = lo + (hi-lo)/2;
            if(target == nums[mid]) return true;
            if(nums[mid] > nums[lo]){ // means the left part is in order
                if(target<=nums[mid] && target>=nums[lo]){ // target is in the range of left part
                    hi = mid - 1;
                }else lo = mid + 1;
            }else if((nums[mid] < nums[lo])){ // mean right part is in order
                if(target <= nums[hi] && target>=nums[mid]){ //target is in the range of right part
                    lo = mid + 1;
                }else hi = mid - 1;
            }else lo ++;
        }
        return false;
    }
};
