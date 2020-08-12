class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ind=0, len = nums.size();
        if(len==0) return 1;
        while(ind<len){
            if(nums[ind]>=1 && nums[ind]<=len){
                if(nums[ind] != ind+1) {
                    if(nums[nums[ind]-1] == nums[ind]) {nums[ind] = -1;ind++;} // deal with duplicates
                    else swap(nums[ind], nums[nums[ind]-1]);
                }
                else {ind++; while(ind<len && nums[ind]==ind+1) ind++;}
            }else {nums[ind] = -1;ind++;}
        }
        
        for(int i =0;i<len;i++){
            if(nums[i]==-1) return i+1;
        }
        return len+1;
    }
    
    void swap(int& a, int&b){
        int tmp = a;
        a = b;
        b = tmp;
    }
};