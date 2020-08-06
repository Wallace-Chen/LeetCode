class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX; // 唯一可能的溢出情况
        if(divisor == 1) return dividend;
        
        if(divisor == INT_MIN) return dividend == INT_MIN ? 1 : 0;
        
        int abs_dividend_minus_1 = abs(dividend + (dividend < 0 ? 1: -1));
        
        int abs_divisor = abs(divisor), step = abs(divisor), step_i= 1;
        int res = 0;
        while(abs_dividend_minus_1 >= abs_divisor){
            while(abs_dividend_minus_1 < step){
                step >>= 1;
                step_i >>= 1;
            }
            abs_dividend_minus_1 -= step;
            res += step_i;
            
            if(step <= (INT_MAX >> 1)){
                step <<= 1;
                step_i <<= 1;
            }
        }
        
        if(abs_dividend_minus_1 + 1 == abs_divisor) res += 1;
        
        if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) return -res;
        return res;
    }
};