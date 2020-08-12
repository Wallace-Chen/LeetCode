class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        double rlt(1.0);
        int last=0;
        if(n<0){ // deal with the INT_MIN
            n = -(n+1);
            x = 1/x;
        }else n--;
        double last_r=x;
        for(int i=0;i<32;i++){
            if((n>>i)&1){
                double to_mul = last_r;
                for(int j=last;j<i;j++) to_mul *= to_mul;
                rlt *= to_mul;
                last = i;
                last_r = to_mul;
            }
            
        }
        return rlt*x;
    }
};