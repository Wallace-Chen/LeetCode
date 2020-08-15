class Solution {
public:
    int mySqrt(int x) {
        if(x < 1) return 0;
        if(x < 4) return 1;
        long lo = 2, hi = x/2 + 1, mid;
        while(lo < hi){
            mid = lo + (hi-lo)/2;
            long tmp = mid * mid;
            if(tmp==x) return mid;
            if(tmp > x) hi = mid;
            else lo = mid + 1;
        }
        return (lo-1);
    }
};