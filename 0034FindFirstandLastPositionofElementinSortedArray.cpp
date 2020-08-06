class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> rlt={-1,-1};
        searchRange(nums, target, 0, nums.size()-1, rlt, 0);
        return rlt;
    }
    
    void searchRange(vector<int>& nums, int target, int start, int end, vector<int>& rlt, int dir) {
        int left = start, right = end, mid;
        while(left <= right){
            mid = left + (right - left)/2;
            if(nums[mid] == target){
                if(dir<=0){
                    if(mid-1<0 || nums[mid-1] != target) {if(rlt[0]<0) rlt[0] = mid;}
                    else if(rlt[0]<0) searchRange(nums, target, left, mid-1, rlt, -1);
                }
                if(dir>=0){
                    if(mid+1>nums.size()-1 || nums[mid+1] != target) {if(rlt[1]<0) rlt[1] = mid;}
                    else if(rlt[1]<0) searchRange(nums, target, mid+1, right, rlt, 1);
                }
                return ;
            }else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
    }
};