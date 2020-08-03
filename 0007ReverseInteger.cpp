class Solution {
public:
     int reverse(int x) {
         int rlt = 0;
        while(abs(x)>0){
            int digit = x%10;
            x /= 10;
            if( rlt>0 && rlt>(INT_MAX-digit)/10) return 0;
            if( rlt<0 && rlt<(-INT_MAX-1-digit)/10 ) return 0;
            rlt = rlt*10 + digit;
        }       
        return rlt;
    }
};