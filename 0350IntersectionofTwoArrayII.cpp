class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> rlt;
        if(nums1.size()==0 || nums2.size()==0) return rlt;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int j=0;
        for(int i=0;i<nums1.size(); i++){
            int a = nums1[i];
            while(j<nums2.size() && nums2[j]<a) j++;
            if(j>=nums2.size()) return rlt;
            if(nums2[j] == a) {rlt.push_back(a); j++;}    
        }
        
        return rlt;
    }
};