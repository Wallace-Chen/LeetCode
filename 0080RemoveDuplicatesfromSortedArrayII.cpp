
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int rlt = 0, len = nums.size();
        if(len < 3) return len;
        for(int i=1, cnt=1;i<len;i++){
            if(nums[i] == nums[rlt]){
                if(cnt>=2) continue;
                cnt++;
            }else cnt = 1;
            nums[++rlt] = nums[i];
        }
        return rlt+1;
    }
};

/*
class Solution {
public:
int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
    return i;
}
};
*/
