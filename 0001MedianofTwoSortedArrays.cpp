class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        min1=0, max1=nums1.size();
        len1 = max1; len2 =nums2.size();
        if(len1 == 0) {
            return (len2%2==0) ? double(nums2[len2/2-1]+nums2[len2/2])/2 : (double)nums2[len2/2];
        }
        else if(len2 == 0){
            return (len1%2==0) ? double(nums1[len1/2-1]+nums1[len1/2])/2 : (double)nums1[len1/2];
        }
        return getMedian(nums1, nums2, len1/2);        
    }
    
    double getMedian(vector<int>& a, vector<int>& b, int i){
        int j = (len1 + len2) / 2 - i ;
        if(i>0 && j<len2 && a[i-1]>b[j]){ // we have to move the i index left by binary search
            max1 = i;
            if((min1 + max1) / 2 == i) i --;
            else i = (min1 + max1) / 2;
            j = (len1 + len2) / 2 - i;
            if(j>len2) {
                j = len2;
                i = (len1 + len2) / 2 - j;
            }
            else if(j<0){
                j = 0;
                i = (len1 + len2) / 2 - j;
            }
            return getMedian(a, b, i);
        }
        else if(j>0 && i<len1 && b[j-1]>a[i]){ // now need to move i index right by binary search
            min1 = i;
            if((min1 + max1) / 2 == i) i ++;
            else i = (min1 + max1) / 2;
            j = (len1 + len2) / 2 - i;
            if(j>len2) {
                j = len2;
                i = (len1 + len2) / 2 - j;
            }
            else if(j<0){
                j = 0;
                i = (len1 + len2) / 2 - j;
            }
            return getMedian(a, b, i);
        }
        else{ // indicate we shoud now find a valid splitting
            int med1, med2;
            if(i == 0) med1 = b[j-1];
            else if(j == 0) med1 = a[i-1];
            else med1 = max(a[i-1], b[j-1]);
            if(i == len1) med2 = b[j];
            else if(j == len2) med2 = a[i];
            else med2 = min(a[i], b[j]);
            
            return (len1+len2)%2==0 ? double(med1+med2)/2.0 : double(med2);
        }
    }

private:
    int len1, len2;
    int min1, max1;
};