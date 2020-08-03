class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> rlt;
        int len1 = nums1.size(), len2 = nums2.size();
        if(len1==0 || len2==0) return rlt;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i=0, j=0;
        while(i<len1 && j<len2){
            if(nums1[i]<nums2[j]) {
                i++;
                while(i<len1 && nums1[i]==nums1[i-1]) i++;
            }
            else if(nums1[i] > nums2[j]) {
                j ++;
                while(j<len2 && nums2[j]==nums2[j-1]) j++;
            }
            else{
                rlt.push_back(nums1[i]);
                i++; j++;
                while(i<len1 && nums1[i]==nums1[i-1]) i++;
                while(j<len2 && nums2[j]==nums2[j-1]) j++;
            }
        }
        return rlt;
    }
};