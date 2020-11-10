class Solution {
public:
    /*
    int longestConsecutive(vector<int>& nums) { // sorting method, ~O(nlgn) complexity
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int ret=1, nmax = ret;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] == nums[i]) continue;
            if(nums[i-1]+1 == nums[i])  ret ++;
            else {
                nmax = max(nmax, ret);
                ret = 1;
            }
        }
        nmax = max(nmax, ret);
        return nmax;
    }
    */
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set_num(nums.begin(), nums.end());
        int nmax = 0;
        for(int num : nums){
            if(num>INT_MIN && set_num.count(num-1)) continue; // skip since we will check num when we do a loop start num-1
            int n=1, curr = num;
            while(curr<INT_MAX && set_num.count(curr+1)){
                curr += 1;
                n += 1;
            }
            nmax = max(nmax, n);
        }
        return nmax;
    }
};
