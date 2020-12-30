class Solution {
public:
    int singleNumber(vector<int>& nums) { // bit operation
        int ret=0;
        for(auto num:nums) ret ^= num;
        return ret;
    }
};
