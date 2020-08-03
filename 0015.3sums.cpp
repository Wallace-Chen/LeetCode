class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > rlt;
        if(nums.size() < 3) return rlt;
        sort(nums.begin(), nums.end());
        for(int i=0; i < nums.size()-2; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int low = i + 1;
            int high = nums.size() - 1;
            int a = nums[i];
            while(low<high){
                int b = nums[low];
                int c = nums[high];
                if(a + b + c == 0){
                    vector<int> triplet;
                    triplet.push_back(a);
                    triplet.push_back(b);
                    triplet.push_back(c);
                    rlt.push_back(triplet);
                    while(low<high-1 && nums[low+1]==nums[low]) low++;
                    low ++ ;
                    while(high>low+1 && nums[high-1]==nums[high]) high--;
                    high -- ;
                }
                else if(a+b+c>0){
                    while(high>low+1 && nums[high-1]==nums[high]) high--;
                    high --;
                }
                else{
                    while(low<high-1 && nums[low+1]==nums[low]) low++;
                    low ++;
                }
            }   
        }
        return rlt;
    }
};