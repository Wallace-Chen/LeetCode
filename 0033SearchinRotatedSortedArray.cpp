class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size(), last=len-1, step = 1, pivot=0;
        int  left=0, right=len-step;
        while(right>left){
            if(nums[left] > nums[right]) {
                if(right == left + 1) {pivot = right;break;}
                step <<= 1;
                last = right;
                right = (right - step/2) > left ? right-step/2 : left+1;
            }else{
                left = right;
                right = last;
                step = 1;
            }
        }
        // now we have the pivot, and I will do a standard binary search by index conversion: new i = (i+pivot)%len
        int index = 0, new_i;
        left = 0, right = len-1;
        while(left <= right){
            index = (left + right) / 2;
            new_i = (index + pivot)%len;
            if(nums[new_i] == target) return new_i;
            else if(nums[new_i] > target){
                right = index - 1;
            } 
            else {
                left = index + 1;
            }
        }
        return -1;
    }
};