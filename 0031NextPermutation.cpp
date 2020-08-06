class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size(), pi=len-1, i=len-1;
        if(len <= 1) return;
        for(;i>=0;i--){ // find the switch point
            if(nums[i]<nums[pi]) break;
            else pi = i;
        }
        if(i >= 0){
            int j = pi;
            cout << i << ", " << j << endl;
            for(;j<len;j++){ // find the proper position and do the swap
                if(nums[j]<=nums[i]) {swap(nums[i], nums[j-1]); break;}
            }
            if(j == len) swap(nums[i], nums[j-1]);
        }
            
        for(int j=pi;j<pi+(len-pi)/2;j++){ //sort the remaining part to the least permutation
            swap(nums[j], nums[len-1-(j-pi)]);
        }
        return;
    }
    
    void swap(int &a, int &b){
        int tmp = a;
        a = b;
        b = tmp;
    }
};