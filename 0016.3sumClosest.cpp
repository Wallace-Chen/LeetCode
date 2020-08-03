class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int rlt = nums[0] + nums[1] + nums[2];
        int len = nums.size();
        int diff = 10000;
        if(len == 3 || target<rlt) return rlt;
        if(target > nums[len-1] + nums[len-2] + nums[len-3]) return nums[len-1] + nums[len-2] + nums[len-3];
        for(int i=0; i<len-2; i++){
            int a = nums[i];
            int low = i + 1;
            int high = len - 1;
            while(low < high){
                int b = nums[low];
                int c = nums[high];
                int tmp = target - a -b - c;
                if(tmp == 0){
                    diff = 0;
                    break;
                }
                if(abs(tmp) < abs(diff)) diff = tmp;
                if(tmp > 0) low ++ ;
                else if(tmp < 0) high --;
            }
        }
        return (target-diff);
    }
};